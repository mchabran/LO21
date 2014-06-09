#ifndef CURSUSFINDER_H
#define CURSUSFINDER_H
#include "CursusManager.h"

class CursusFinder : public QWidget{
    Q_OBJECT
    CursusManager* cM;
    QComboBox* nomCursus;
    QLabel* nomCursusLabel;

    //QPushButton* rechercher;

    QPushButton* annuler;
    QPushButton* supprimerC;
    QPushButton* ajouterC;
    QPushButton* editerC;

    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
public :
    CursusFinder(CursusManager* M, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
    //void recherche();
    void ajouter();
    void editer();
    void supprimer();
};

#endif // CURSUSFINDER_H
