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

        mEarthquakeMesCouilles = mProjet->CreateEffect("EarthquakeMesCouilles", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mEarthquakeMesCouilles)
        {qDebug()<<"===>Erreur chargement EarthquakeMesCouilles ";
            delete mEarthquakeMesCouilles;
            mEarthquakeMesCouilles = NULL;
        }

        mTourbillon = mProjet->CreateEffect("Tourbillon", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mTourbillon)
        {qDebug()<<"===>Erreur chargement EarthquakeMesCouilles ";
            delete mTourbillon;
            mTourbillon = NULL;
        }

        mFogEffect = mProjet->CreateEffect("FogEffect", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mFogEffect)
        {qDebug()<<"===>Erreur chargement Fog ";
            delete mFogEffect;
            mFogEffect = NULL;
        }

        mVibro = mProjet->CreateEffect("Vibration", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mVibro)
        {qDebug()<<"===>Erreur chargement Vibration ";
            delete mVibro;
            mVibro = NULL;
        }

        mRebond = mProjet->CreateEffect("Rebond", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mRebond)
        {qDebug()<<"===>Erreur chargement Rebond ";
            delete mRebond;
            mRebond = NULL;
        }

        mPas = mProjet->CreateEffect("Pas", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mPas)
        {qDebug()<<"===>Erreur chargement Pas ";
            delete mPas;
            mPas = NULL;
        }

        mPluie = mProjet->CreateEffect("Pluie", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mPluie)
        {qDebug()<<"===>Erreur chargement Pluie ";
            delete mPluie;
            mPluie = NULL;
        }

        mCorner = mProjet->CreateEffect("Corner", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mCorner)
        {qDebug()<<"===>Erreur chargement Corner ";
            delete mCorner;
            mCorner = NULL;
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

CImmCompoundEffect *GestionHaptique::GetEarthquakeMesCouilles() const
{
    return mEarthquakeMesCouilles;
}

CImmCompoundEffect *GestionHaptique::GetTourbillon() const
{
    return mTourbillon;
}

CImmCompoundEffect *GestionHaptique::GetFogEffect() const
{
    return mFogEffect;
}

CImmCompoundEffect *GestionHaptique::GetVibroEffect() const
{
    return mVibro;
}

CImmCompoundEffect *GestionHaptique::GetRebondEffect() const
{
    return mRebond;
}

CImmCompoundEffect *GestionHaptique::GetPasEffect() const
{
    return mPas;
}

CImmCompoundEffect *GestionHaptique::GetPluieEffect() const
{
    return mPluie;
}

CImmCompoundEffect *GestionHaptique::GetCornerEffect() const
{
    return mCorner;
}

CImmProject *GestionHaptique::GetProjet() const
{
    return mProjet;
}



