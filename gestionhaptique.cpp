#include "gestionhaptique.h"
#include <QApplication>
#include "story.h"
#include <QDebug>

GestionHaptique::GestionHaptique(Story *fen): mFenetre(fen)
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


        mProjet = new CImmProject();
        if (mProjet->OpenFile("C:\\Users\\M2IHM\\Desktop\\ProjetSahri\\HapticEffect\\HeartBeatEffect.ifr", mSouris))
       {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
            qDebug()<<"Projet ifr charg�";
            mHeartBoomMesCouilles = mProjet->CreateEffect("HeartBoomMesCouilles", mSouris, IMM_PARAM_NODOWNLOAD);
            if (!mHeartBoomMesCouilles)
            {qDebug()<<"===>Erreur chargement HeartBoomMesCouilles ";
                delete mHeartBoomMesCouilles;
                mHeartBoomMesCouilles = NULL;
            }
        }
        else
        {
            qDebug()<<"===>Erreur chargement projet IFR avec code "<<CIFCErrors::GetLastErrorCode() ;
        }
    }

    GestionHaptique::~GestionHaptique()
    {
        if (mProjet)
            delete mProjet;
        if (mSouris)
            delete mSouris;
    }


        CImmCompoundEffect *GestionHaptique::GetHeartBoomMesCouilles() const
        {
            return mHeartBoomMesCouilles;
        }

        CImmProject *GestionHaptique::GetProjet() const
        {
            return mProjet;
        }



