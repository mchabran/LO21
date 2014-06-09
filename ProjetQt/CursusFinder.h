#ifndef CURSUSFINDER_H
#define CURSUSFINDER_H
#include "CursusManager.h"

class CursusFinder : public QWidget{
    Q_OBJECT
    CursusManager* cM;
    QComboBox* nomCursus;
    QLabel* nomCursusLabel;

    //affichage attributs

    const Cursus* cu;
    //QLineEdit* nomCursus;
    //QLabel* nomLabel;
    QSpinBox* credCS;
    QLabel* CSLabel;
    QSpinBox* credTM;
    QLabel* TMLabel;
    QSpinBox* credTSH;
    QLabel* TSHLabel;
    QSpinBox* credSP;
    QLabel* SPLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;

    QComboBox* UVs;
    QLabel* UVsLabel;
    //
    //QPushButton* rechercher;

    QPushButton* annuler;
    QPushButton* supprimerC;
    QPushButton* ajouterC;
    QPushButton* editerC;
    QPushButton* actualiserC;

    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
   // QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;
    QHBoxLayout* coucheH7;
    QHBoxLayout* coucheH8;
    QHBoxLayout* coucheH9;

public :
    CursusFinder(CursusManager* M, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
    //void recherche();
    void ajouter();
    void editer();
    void supprimer();
    void afficher(QString cursusN=0);
    void actualisation();
};

#endif // CURSUSFINDER_H
