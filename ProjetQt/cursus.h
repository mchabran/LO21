#ifndef CURSUS_H
#define CURSUS_H
#include <QString>
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

using namespace std;


class Cursus{
    QString nom;
public :
    QString getNom() const {return nom;}
    Cursus(QString s) : nom(s){}
};



class TC : public Cursus{ //Singleton (un seul cursus TC à créer)
    int credCS;
    int credTM;
    //int credTSH; //comment on fait pour les TSH sachant qu'il faut 52 crédits branche + TC confondus ? (:
    int credSP;

    static TC* instanceUnique;
    TC(): Cursus("Tronc Commun"), credCS(48), credTM(24), credSP(6){} //reste à initialiser credTSH si on en met
    TC(const TC* instance);
    virtual ~TC() {}
    virtual void operator=(const TC&){}
public :
    int getCredCS()const {return credCS;}
    int getCredTM()const {return credTM;}
    //int getCredTSH() const {return credTSH;}
    int getCredSP() const {return credSP;}

    static TC& donneInstance();
    static void libereInstance();
};



class HuTech : public Cursus{
    int credCS;
    int credTM;
    //int credTSH; //Idem que pour TC (:
    int credSP;

    static HuTech* instanceUnique;
    HuTech(): Cursus("Tronc Commun"), credCS(48), credTM(24), credSP(6){} //reste à initialiser credTSH si on en met
    HuTech(const HuTech* instance);
    virtual ~HuTech() {}
    virtual void operator=(const HuTech&){}
public :
    int getCredCS() const {return credCS;}
    int getCredTM() const {return credTM;}
    //int getCredTSH() const {return credTSH;}
    int getCredSP() const {return credSP;}

    static HuTech& donneInstance();
    static void libereInstance();
};




class CursusEditeur : public QWidget{
    //Q_OBJECT //pourquoi ça marche pas quand il y est ? :(
    Cursus& cursus;
    QLineEdit* nomCursus;
    QLabel* nomCursusLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QPushButton* rechercher;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
public :
    CursusEditeur(Cursus& c, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
   //void rechercherCursus(); //void ?
};


class TCEditeur : public QWidget{
    Q_OBJECT
    TC& tc;
    QLineEdit* nom;
    QLabel* nomLabel;
    QSpinBox* credCS;
    QLabel* CSLabel;
    QSpinBox* credTM;
    QLabel* TMLabel;
    QSpinBox* credTSH;
    QLabel* TSHLabel;
    QSpinBox* credSP;
    QLabel* SPLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QPushButton* sauver;
    QPushButton* annuler;
public :
    TCEditeur(Cursus& c, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre
public slots :
   void sauverTC();
   void afficherTC();
};


#endif // CURSUS_H
