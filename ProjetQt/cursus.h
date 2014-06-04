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
<<<<<<< HEAD
    QString* tabUV; //on stock uniquement les noms des UVs
    unsigned int nbUV;
    unsigned int nbMaxUV;
    const Cursus *parent; //la branche où la filière est (par défaut =NULL)
=======
    UV* tabUV;
    //Cursus& parent; //la branche où la filière est (par défaut =NULL) A rajouter dans le constructeur mais comment mettre une valeur par défaut si 0 ne marche pas ?
>>>>>>> e23a9215f49d1a7338465221fad6516ef0844a5f
    QString nom;
    CategorieCursus categorie;
    unsigned int credCS;
    unsigned int credTM;
    unsigned int credTSH;
    unsigned int credSP;

    //Cursus& find(const QString& f, const QString& nomcherche);
    friend class CursusManager;
public :
<<<<<<< HEAD
    //QString file; //Je sais pas comment faire autrement que le mettre en public, je sais pas comment c'est fait pour UVManager
=======
    QString file; //a mettre dans CursusManager en fait
>>>>>>> e23a9215f49d1a7338465221fad6516ef0844a5f
    QString getNom() const {return nom;}
    CategorieCursus getCategorie() const {return categorie;}
    const QString* getTabUV()const{return tabUV;}
    const Cursus* getParent()const{return parent;}
    unsigned int getNbUV()const{return nbUV;}
    unsigned int getCredCS()const {return credCS;}
    unsigned int getCredTM()const {return credTM;}
    unsigned int getCredTSH() const {return credTSH;}
    unsigned int getCredSP() const {return credSP;}
    void setCredCS(unsigned int n){credCS=n;}
    void setCredTM(unsigned int n){credTM=n;}
    void setCredTSH(unsigned int n){credTSH=n;}
    void setCredSP(unsigned int n){credSP=n;}
    void setCategorie(CategorieCursus c){categorie=c;}
    void setParent(const Cursus* p){parent=p;}
    void addUV(QString u); //ca marche

<<<<<<< HEAD
    //a mettre en privée
    Cursus(QString n, CategorieCursus cat, unsigned int nbCS, unsigned int nbTM, unsigned int nbTSH, unsigned int nbSP, const Cursus* p=0 ) : nom(n), categorie(cat), credCS(nbCS), credTM(nbTM), credTSH(nbTSH), credSP(nbSP),nbUV(0), nbMaxUV(4), tabUV(new QString[4]), parent(p){}
=======
    //à mettre en partie privée quand cursusManager sera créé
    Cursus(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP) : nom(n), categorie(cat), credCS(nbCS), credTM(nbTM), credTSH(nbTSH), credSP(nbSP) , file(""){}
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
>>>>>>> e23a9215f49d1a7338465221fad6516ef0844a5f
};





#endif // CURSUS_H
