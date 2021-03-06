#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H


//Compilation en mode non unicode
#undef UNICODE



#include <ifc.h>
#include <QPoint>
#include <QMainWindow>

class Story;

class GestionHaptique
{
public:
    GestionHaptique(Story *fen);
    ~GestionHaptique();

    CImmCompoundEffect *GetHeartBoomMesCouilles() const;
    CImmCompoundEffect *GetEarthquakeMesCouilles() const;
    CImmCompoundEffect *GetTourbillon() const;
    CImmCompoundEffect *GetFogEffect() const;
    CImmCompoundEffect *GetVibroEffect() const;
    CImmCompoundEffect *GetRebondEffect() const;
    CImmCompoundEffect *GetPasEffect() const;
    CImmCompoundEffect *GetPluieEffect() const;
    CImmCompoundEffect *GetCornerEffect() const;
    CImmProject *GetProjet() const;
private:
    CImmMouse *mSouris;
    CImmProject  *mProjet;
    CImmCompoundEffect	*mHeartBoomMesCouilles;
    CImmCompoundEffect	*mEarthquakeMesCouilles;
    CImmCompoundEffect	*mTourbillon;
    CImmCompoundEffect	*mVibro;
    CImmCompoundEffect	*mFogEffect;
    CImmCompoundEffect	*mRebond;
    CImmCompoundEffect	*mPas;
    CImmCompoundEffect	*mPluie;
    CImmCompoundEffect	*mCorner;
    Story *mFenetre;
};


#endif // GESTIONHAPTIQUE_H

