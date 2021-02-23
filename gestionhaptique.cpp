#include "gestionhaptique.h"
#include <QApplication>
#include "story.h"
#include <QDebug>

GestionHaptique::GestionHaptique(Story *fen):mCentreEnclosRelatif(150,150), mFenetre(fen)
{

    //Initialisation de la souris
    mSouris = new CImmMouse();


        // if (!mSouris->Initialize(qApp->applicationPid(),  fen->effectiveWinId()  ))
    if (!mSouris->Initialize(qWinAppInst(),  (HWND)mFenetre->effectiveWinId()  ))
    {qDebug()<<"===>Erreur chargement souris "<<mSouris;
        delete mSouris;
        mSouris = NULL;
        qApp->quit();
    }


    ////////////////////////////////////
    ////////////////////////////////////
    //Création d'effet par programme
    ////////////////////////////////////
    ////////////////////////////////////

    POINT p;
    p.x=p.x=500;
    mRessort = new CImmSpring();
    if (!mRessort->Initialize(mSouris,
                   10000,//raideur
                   10000,//saturation: force max
                   1,//zone sans effet � partir du centre
                    IMM_EFFECT_AXIS_X,//axe
                   p,//point d��quilibre du ressort
                   0,//abscisse du vecteur directeur de l�axe...ignor�
                   0,//ordonn�ee du vecteur directeur de l�axe...ignor�
                   FALSE,//centre en coordonn�es �cran
                   IMM_PARAM_NODOWNLOAD))//reporte le chargement
    {	qDebug()<<"===>Erreur chargement ressort ";
        delete mRessort;
        mRessort = NULL;
    }

    mEnclos = new CImmEnclosure();
    QPoint temp;
    temp= mFenetre->mapToGlobal(mCentreEnclosRelatif);

    POINT centreEnclos;
    centreEnclos.x = temp.x();
    centreEnclos.y = temp.y();

    if (!mEnclos->Initialize(mSouris,
                    200,    // DWORD dwWidth
                    200,    // DWORD dwHeight
                    -10000,    // LONG lVertStiffness
                    -10000,    // LONG lHorizStiffness
                    10,    // DWORD dwVertWallWidth
                    10,    // DWORD dwHorizWallWidth
                    10000,    // DWORD dwHorizSaturation
                    10000,    // DWORD dwVertSaturation
                    IMM_STIFF_ANYWALL  ,
                    0x0,    // DWORD dwClippingMask,
                    centreEnclos,  // POINT pntCenter,
                    NULL,    // CImmEffect* pInsideEffect
                    0,
                    IMM_PARAM_NODOWNLOAD
                    ))
        {qDebug()<<"===>Erreur chargement enclos ";
            delete mEnclos;
            mEnclos = NULL;
        }

        mProjet = new CImmProject();
        if (mProjet->OpenFile("C:\\Users\\M2IHM\\Desktop\\SolutionTPWingmanQt\\TestQt\\TestEffet.ifr", mSouris))
       {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
            qDebug()<<"Projet ifr charg�";
            mRessortIS = new CImmSpring();
            if (!mRessortIS->InitializeFromProject(*mProjet, "Ressort", mSouris,
                                IMM_PARAM_NODOWNLOAD))
            {qDebug()<<"===>Erreur chargement ressortIS ";
                delete mRessortIS;
                mRessortIS = NULL;
            }
            mTextureIS = new CImmTexture();
            if (!mTextureIS->InitializeFromProject(*mProjet, "Texture", mSouris,
                                IMM_PARAM_NODOWNLOAD))
            {qDebug()<<"===>Erreur chargement TextureIS ";
                delete mTextureIS;
                mTextureIS = NULL;
            }
            mLigne = mProjet->CreateEffect("Ligne", mSouris, IMM_PARAM_NODOWNLOAD);
            if (!mLigne)
            {qDebug()<<"===>Erreur chargement LigneIS ";
                delete mLigne;
                mLigne = NULL;
            }
        }
        else
        {
            qDebug()<<"===>Erreur chargement projet IFR avec code "<<CIFCErrors::GetLastErrorCode() ;
        }
    }

    GestionHaptique::~GestionHaptique()
    {
        if (mRessort)
            delete mRessort;
        if (mEnclos)
            delete mEnclos;
        if (mRessortIS)
            delete mRessortIS;
        if (mTextureIS)
            delete mTextureIS;
        if (mProjet)
            delete mProjet;
        if (mSouris)
            delete mSouris;
    }



        QPoint GestionHaptique::GetCentreEnclosRelatif() const
        {
            return mCentreEnclosRelatif;
        }

        CImmCompoundEffect *GestionHaptique::GetLigneIS() const
        {
            return mLigne;
        }

        CImmSpring *GestionHaptique::GetRessort() const
        {
            return mRessort;
        }

        CImmSpring *GestionHaptique::GetRessortIS() const
        {
            return mRessortIS;
        }

        CImmProject *GestionHaptique::GetProjet() const
        {
            return mProjet;
        }

        CImmEnclosure *GestionHaptique::GetEnclos() const
        {
            return mEnclos;
        }

        CImmTexture *GestionHaptique::GetTextureIS() const
        {
            return mTextureIS;
        }




