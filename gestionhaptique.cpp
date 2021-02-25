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


<<<<<<< HEAD
    mProjet = new CImmProject();
    if (mProjet->OpenFile("C:\\Users\\M2IHM\\Desktop\\ProjetSahri\\HapticEffect\\HeartBeatEffect.ifr", mSouris))
    {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
        qDebug()<<"Projet ifr charg�";
        mHeartBoomMesCouilles = mProjet->CreateEffect("HeartBoomMesCouilles", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mHeartBoomMesCouilles)
        {qDebug()<<"===>Erreur chargement HeartBoomMesCouilles ";
            delete mHeartBoomMesCouilles;
            mHeartBoomMesCouilles = NULL;
=======
        mProjet = new CImmProject();
        if (mProjet->OpenFile("C:\\Users\\M2IHM\\Desktop\\ProjetSahri\\HapticEffect\\HeartBeatEffect.ifr", mSouris))
       {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
            qDebug()<<"Projet ifr charg�";
            mHeartBoomMesCouilles = mProjet->CreateEffect("HeartBoomMesCouilles", mSouris, IMM_PARAM_NODOWNLOAD);
            // TODO FIX
            //mEarthquakeMesCouilles = mProjet->CreateEffect("EarthquakeMesCouilles", mSouris, IMM_PARAM_NODOWNLOAD);

            if (!mHeartBoomMesCouilles)
            {qDebug()<<"===>Erreur chargement HeartBoomMesCouilles ";
                delete mHeartBoomMesCouilles;
                mHeartBoomMesCouilles = NULL;
            }
            /*{qDebug()<<"===>Erreur chargement EarthquakeMesCouilles ";
                delete mEarthquakeMesCouilles;
                mEarthquakeMesCouilles = NULL;
            }*/
>>>>>>> 1ec259295b7534b35d49e5d6206f7075b91a66f5
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
        {qDebug()<<"===>Erreur chargement FogEffect ";
            delete mFogEffect;
            mFogEffect = NULL;
        }

        mVibro = mProjet->CreateEffect("Vibration", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mVibro)
        {qDebug()<<"===>Erreur chargement VibrationEffect ";
            delete mVibro;
            mVibro = NULL;
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


<<<<<<< HEAD
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

CImmProject *GestionHaptique::GetProjet() const
{
    return mProjet;
}
=======
        CImmCompoundEffect *GestionHaptique::GetEarthquakeMesCouilles() const
        {
            return mEarthquakeMesCouilles;
        }

        CImmProject *GestionHaptique::GetProjet() const
        {
            return mProjet;
        }
>>>>>>> 1ec259295b7534b35d49e5d6206f7075b91a66f5



