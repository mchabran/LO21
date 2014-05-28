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


class Cursus{ ///si UV compose cursus, on devrait avoir un tableau d'UVs ?
protected : ///je crois qu'il faut qu'ils soient protected pour l'héritage ?
    QString nom;
    CategorieCursus categorie;
    ///c'est quoi ? Ah jviens de regarder en haut, c'est pas la même chose que le nom ?
public :
    QString file; //Je sais pas comment faire autrement que le mettre en public, je sais pas comment c'est fait pour UVManager
    ///justement on est pas dans cursusManager, on est juste dans cursus ;-)
    QString getNom() const {return nom;}
    CategorieCursus getCategorie() const {return categorie;}
    Cursus(QString n, CategorieCursus cat) : nom(n), categorie(cat), file(""){}
    void load(const QString& f); ///pareil, à mettre dans cursusManager
};

//en faite, en faisant la classe, je me suis rendu compte qu'on s'est un peu planté dans notre modélisation...
//j't'explique quand je te vois, pour l'instant je laisse commenter ce que j'ai commencé
/*
class CursusManager { //singleton
private:
    Cursus** cursus;
    unsigned int nbCursus;
    unsigned int nbMaxCursus;
    void addCursus(Cursus* c);
    //bool modification;
    Cursus* trouverCursus(const QString& c) const;
    CursusManager(const CursusManager& cm);
    CursusManager& operator=(const CursusManager& cm);
    CursusManager();
    ~CursusManager();
    QString file;
    friend struct Handler;
    struct Handler{
        UVManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:

    void load(const QString& f);
    void save(const QString& f);
    static CursusManager& getInstance();
    static void libererInstance();
    void ajouterCursus(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    const Cursus& getCursus(const QString& nom) const;
    UV& getCursus(const QString& nom);

   //ajouter peut-etre iterator, mais plus tard
};
*/

///pareil ;-)
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
