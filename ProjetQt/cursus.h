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
 C_TC,C_Branche,C_Filiere,C_HuTech, C_Mineur
};


class Cursus{
    QString nom;
    CategorieCursus categorie;
public :
    QString file; //Je sais pas comment faire autrement que le mettre en public, je sais pas comment c'est fait pour UVManager
    QString getNom() const {return nom;}
    CategorieCursus getCategorie() const {return categorie;}
    Cursus(QString n, CategorieCursus cat) : nom(n), categorie(cat), file(""){}
    void load(const QString& f);
};






class CursusEditeur : public QWidget{
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
    CursusEditeur(Cursus& c, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
    void rechercherCursus();
};



#endif // CURSUS_H
