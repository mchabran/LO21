#ifndef CURSUSEDITEUR_H
#define CURSUSEDITEUR_H
#include "cursus.h"
#include "CursusManager.h"

class CursusEditeur :  public QWidget {
    Q_OBJECT
    CursusManager* cM;
    const Cursus* cu;
    QLineEdit* nomCursus;
    QLabel* nomLabel;
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
    QPushButton* supprimerUV;

    QLineEdit* newUV;
    QLabel* UVLabel;
    QPushButton* ok;

    QPushButton* sauver;
    QPushButton* annuler;
    //QPushButton* supprimerCursus; //a implémenter avec toutes les méthodes nécessaires dans CursusManager
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;
    QHBoxLayout* coucheH7;
    QHBoxLayout* coucheH8;


public :
    CursusEditeur(CursusManager* m, const Cursus* c,QWidget* parent=0);

public slots :
   //void sauverCursus();
   void ajoutUV();
};

#endif // CURSUSEDITEUR_H
