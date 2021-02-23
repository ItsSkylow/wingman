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

    QPoint GetCentreEnclosRelatif() const;
    CImmCompoundEffect *GetLigneIS() const;
    CImmSpring *GetRessort() const;
    CImmSpring *GetRessortIS() const;
    CImmProject *GetProjet() const;
    CImmEnclosure *GetEnclos() const;
    CImmTexture *GetTextureIS() const;
private:
    CImmMouse *mSouris;
    CImmSpring* mRessort;
    CImmEnclosure* mEnclos;
    QPoint mCentreEnclosRelatif;//coordonnées relatives par rapport à la fenêtre
    CImmProject  *mProjet;
    CImmSpring	*mRessortIS;
    CImmTexture	*mTextureIS;
    CImmCompoundEffect	*mLigne;
    Story *mFenetre;
};


#endif // GESTIONHAPTIQUE_H

