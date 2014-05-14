#ifndef UVEDITEUR_H
#define UVEDITEUR_H
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
/*#include <>
#include <>
#include <>
#include <>
#include <>*/
#include "UTProfiler.h"

class UVEditeur : public QWidget {
   Q_OBJECT
   UV& uv;
   QLineEdit* code;
   QLabel* codeLabel;
   QTextEdit* titre;
   QLabel* titreLabel;
   QSpinBox* credits;
   QLabel* creditsLabel;
   QComboBox* categorie;
   QLabel* categorieLabel;
   QLabel* ouvertureLabel;
   QCheckBox* automne;
   QCheckBox* printemps;
   QPushButton* newUV;
   QPushButton* sauver;
   QPushButton* annuler;
   QVBoxLayout* couche;
   QHBoxLayout* coucheH1;
   QHBoxLayout* coucheH2;
   QHBoxLayout* coucheH3;
   QHBoxLayout* coucheH4;

   UVManager* manager;
private slots :
   void activerSauver (QString str="");

public :
   UVEditeur(UVManager* m, UV& u, QWidget* parent=0); //on peut avoir un parent mais par d?faut on en a pas
public slots :
   void sauverUV();
   void addUv();

};


#endif // UVEDITEUR_H
