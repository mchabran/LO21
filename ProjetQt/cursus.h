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
    QString* tabUV; //on stock uniquement les noms des UVs
    unsigned int nbUV;
    unsigned int nbMaxUV;
    Cursus *parent; //la branche où la filière est (par défaut =NULL)
    QString nom;
    CategorieCursus categorie;
    QString credCS;
    QString credTM;
    QString credTSH;
    QString credSP;
    friend class CursusManager;
public :
    //QString file; //Je sais pas comment faire autrement que le mettre en public, je sais pas comment c'est fait pour UVManager
    QString getNom() const {return nom;}
    CategorieCursus getCategorie() const {return categorie;}
    void addUV(QString u);
    QString getCredCS()const {return credCS;}
    QString getCredTM()const {return credTM;}
    QString getCredTSH() const {return credTSH;}
    QString getCredSP() const {return credSP;}
    void setCredCS(QString n){credCS=n;}
    void setCredTM(QString n){credTM=n;}
    void setCredTSH(QString n){credTSH=n;}
    void setCredSP(QString n){credSP=n;}

    //à mettre en partie privée quand cursusManager sera créé
    Cursus(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP, const Cursus* p=0 ) : nom(n), categorie(cat), credCS(nbCS), credTM(nbTM), credTSH(nbTSH), credSP(nbSP),nbUV(0), nbMaxUV(0), tabUV(0), parent(p){}
    Cursus& find(const QString& f, const QString& nomcherche);
};

class CursusManager{
    Cursus** mesCursus;
    unsigned int nbCursus;
    unsigned int nbMaxCursus;
    void addItem(Cursus* c);
    bool modification;
    Cursus* trouverCursus(const QString& c) const; //fait mais pas vérifier
    CursusManager(const CursusManager& cm);//pas à faire
    CursusManager& operator=(const CursusManager& cm);//pas à faire
    CursusManager();//pas à faire
    ~CursusManager();//à fait
    QString file;
    friend struct Handler;
    struct Handler{
        CursusManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:

    void load(const QString& f); //manque StringToCursus
    void save(const QString& f); // a faire
    static CursusManager& getInstance(); // a faire
    static void libererInstance(); // a faire
    void ajouterCursus(const QString n, const QString* t, unsigned int nbU, unsigned int nbMax, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP); //fait mais pas vérifié
    const Cursus& getCursus(const QString& nom) const;// a faire
    Cursus& getCursus(const QString& nom);// a faire

    class Iterator {
        friend class CursusManager;
        Cursus** currentCursus;
        unsigned int nbRemain;
        Iterator(Cursus** c, unsigned nb):currentCursus(c),nbRemain(nb){}
       public:
            Iterator():nbRemain(0),currentCursus(0){}
            bool isDone() const { return nbRemain==0; }
            void next() {
                if (isDone())
                        throw UTProfilerException("error, next on an iterator which is done");
                nbRemain--;
                currentCursus++;
            }
            Cursus& current() const {
                if (isDone())
                    throw UTProfilerException("error, indirection on an iterator which is done");
                return **currentCursus;
            }
    };
    Iterator getIterator() {
        return Iterator(mesCursus,nbCursus);
   };


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
    Q_OBJECT
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
