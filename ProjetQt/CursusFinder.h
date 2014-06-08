/*#ifndef CURSUSFINDER_H
#define CURSUSFINDER_H
#include "CursusManager.h"

class CursusFinder : public QWidget{
    Q_OBJECT
    CursusManager& cM;
    QLineEdit* nomCursus;
    QLabel* nomCursusLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QPushButton* rechercher;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
public :
    CursusFinder(CursusManager& cM, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
    void rechercherCursus();
};

#endif // CURSUSFINDER_H
*/
