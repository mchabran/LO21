#ifndef CURSUS_H
#define CURSUS_H
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
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
#include <sstream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include "UTProfiler.h"

using namespace std;

enum CategorieCursus {
 C_TC,C_Branche,C_Filiere,C_HuTech, C_Mineur, autre
};


class Cursus{
    static unsigned int nbCursus;
    QString nom;
    CategorieCursus categorie;
    QString credCS;
    QString credTM;
    QString credTSH;
    QString credSP;
public :
    QString file; //Je sais pas comment faire autrement que le mettre en public, je sais pas comment c'est fait pour UVManager
    QString getNom() const {return nom;}
    CategorieCursus getCategorie() const {return categorie;}
    QString getCredCS()const {return credCS;}
    QString getCredTM()const {return credTM;}
    QString getCredTSH() const {return credTSH;}
    QString getCredSP() const {return credSP;}
    void setCredCS(QString n){credCS=n;}
    void setCredTM(QString n){credTM=n;}
    void setCredTSH(QString n){credTSH=n;}
    void setCredSP(QString n){credSP=n;}

    Cursus(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP) : nom(n), categorie(cat), credCS(nbCS), credTM(nbTM), credTSH(nbTSH), credSP(nbSP) ,file(""){}
    Cursus& find(const QString& f, const QString& nomcherche);
};






class CursusFinder : public QWidget{
    Q_OBJECT
    Cursus& cursus;
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
    CursusFinder(Cursus& c, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
    void rechercherCursus();
};



class CursusEditeur :  public QWidget {
    Q_OBJECT //fait tout foirer <3
private :
    Cursus& c;
    QLineEdit* nom;
    QLabel* nomLabel;
    QLineEdit* credCS;
    QLabel* CSLabel;
    QLineEdit* credTM;
    QLabel* TMLabel;
    QLineEdit* credTSH;
    QLabel* TSHLabel;
    QLineEdit* credSP;
    QLabel* SPLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QPushButton* sauver;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;


public :
    CursusEditeur(Cursus& cur, QWidget* parent=0);
    void ajouterCursus(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP);

public slots :
   void sauverCursus();
};


#endif // CURSUS_H
