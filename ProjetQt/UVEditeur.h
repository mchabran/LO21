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
   QPushButton* supprimer;
   QVBoxLayout* couche;
   QHBoxLayout* coucheH1;
   QHBoxLayout* coucheH2;
   QHBoxLayout* coucheH3;
   QHBoxLayout* coucheH4;

   UVManager* manager;
private slots :
   void activerSauver (QString str="");

public :
   UVEditeur(UVManager* m, UV& u, QWidget* parent=0);
public slots :
   void sauverUV();
   void addUv();
   void supprimerUV();

};


class UVFinder : public QWidget{ //Créé pour pouvoir répondre à la question 1 du sujet
    Q_OBJECT
    UVManager* manager;
    QLineEdit* code;
    QLabel* codeLabel;
    QPushButton* rechercher;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
public :
   UVFinder(UVManager* m, QWidget* parent=0);
public slots :
   void rechercherUV();
};


#endif // UVEDITEUR_H
