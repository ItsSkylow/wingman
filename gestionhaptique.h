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
<<<<<<< HEAD
    CImmCompoundEffect *GetTourbillon() const;
    CImmCompoundEffect *GetFogEffect() const;
    CImmCompoundEffect *GetVibroEffect() const;
=======
>>>>>>> 1ec259295b7534b35d49e5d6206f7075b91a66f5
    CImmProject *GetProjet() const;
private:
    CImmMouse *mSouris;
    CImmProject  *mProjet;
    CImmCompoundEffect	*mHeartBoomMesCouilles;
    CImmCompoundEffect	*mEarthquakeMesCouilles;
<<<<<<< HEAD
    CImmCompoundEffect	*mTourbillon;
    CImmCompoundEffect	*mVibro;
    CImmCompoundEffect	*mFogEffect;
=======
>>>>>>> 1ec259295b7534b35d49e5d6206f7075b91a66f5
    Story *mFenetre;
};


#endif // GESTIONHAPTIQUE_H

