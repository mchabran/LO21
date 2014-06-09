#ifndef MENUEDITEUR_H
#define MENUEDITEUR_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>
#include "UTProfiler.h"

class MenuEditeur : public QWidget{
    Q_OBJECT
    UVManager& um;
    QPushButton* ajoutDoss;
    QPushButton* consultDoss;
    QPushButton* ajoutEqui;
    QPushButton* ajoutInscr;
    QPushButton* consultUV;
    QPushButton* ajoutCursus;
    QPushButton* consultCursus;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;

public :
    MenuEditeur(UVManager& m, QWidget* parent=0);
public slots :
    void ajouterDossier();
    void ajouterCursus();
    /*void ajouterEquivalence();
    void consulterUV();*/
    void consulterCursus();
};

#endif // MENUEDITEUR_H
