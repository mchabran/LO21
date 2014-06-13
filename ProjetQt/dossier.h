#ifndef DOSSIER_H
#define DOSSIER_H

#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"
#include "Inscription.h"
#include "Equivalence.h"
#include "CursusManager.h"
#include <QTableWidget>
#include <QListView>
#include <QLineEdit>

using namespace std;

class Inscription;
class Equivalence;


class Dossier{ //singleton
    QString fileI; //fichier d'inscription
    QString fileE; //fichier d'Equivalence
    QString fileD; //fichier de Dossier
    CursusManager& CM;
    UVManager& UVM;
    Cursus** cursus;
    Inscription** inscriptions;
    Equivalence** equivalences;
    bool activiteExtraScolaire;
    bool niveauB2;
    unsigned int nbCur;
    unsigned int nbMaxCur;
    unsigned int nbIns;
    unsigned int nbMaxIns;
    unsigned int nbEq;
    unsigned int nbMaxEq;
    static Dossier* instanceUnique;
    Dossier(CursusManager& c, UVManager& u, Cursus** tabCur, Inscription** tabI, Equivalence** tabE, bool aes, bool B2, unsigned int nc, unsigned int ni, unsigned int ne);
    Dossier():CM(CursusManager::getInstance()), UVM(UVManager::getInstance()), inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false), nbIns(0), nbEq(0), nbCur(0), nbMaxEq(0), nbMaxIns(0), nbMaxCur(0), fileI(""), fileE(""), fileD("") {}
    Dossier(CursusManager& c, UVManager& u): CM(c), UVM(u),inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false), nbCur(0), nbIns(0), nbEq(0), nbMaxIns(0), nbMaxEq(0), nbMaxCur(0),fileI(""), fileE(""), fileD("") {}
    Dossier(const Dossier* instance);
    virtual ~Dossier();
    virtual void operator=(const Dossier&){}
public :

    //CursusManager& getCursusManager() const {return CM;}
    Cursus** getCursus() const {return cursus;}
    Inscription** getInscriptions() const {return inscriptions;}
    void loadInscription(const QString& f);
    void saveInscription(/*const QString &f*/);
    void loadEquivalence(const QString& f);
    void saveEquivalence(/*const QString& f*/);
    void loadDossier(const QString &f);
    void saveDossier(/*const QString &f*/);
    Equivalence** getEquivalences() const {return equivalences;}
    unsigned int getNbCur() const{return nbCur;}
    unsigned int getNbIns() const{return nbIns;}
    unsigned int getNbEq() const{return nbEq;}
    bool getActiviteES(){return activiteExtraScolaire;}
    bool getnivB2(){return niveauB2;}
    void addCursus(Cursus* c);
    void supprCur(Cursus* c);
    void addInscription(Inscription* i);
    void addEquivalence(Equivalence* e);
    void setAES(bool val){activiteExtraScolaire = val;}
    void setNivB2(bool val){niveauB2 = val;}
    static Dossier& donneInstance(/*CursusManager& c, UVManager& u*/);
    static void libereInstance();

    //void load(const QString& f);
    //void save(const QString& f);
};


class DossierEditeur : public QWidget{
    Q_OBJECT
    UVManager& manager;
    CursusManager& CM;
    Dossier& doss;
    QLabel* cursusLabel;
    QLabel* nomCursusLabel;
    QLineEdit* nomNouvCur;
    QTableWidget* equivalences;
    QLabel* equivalencesLabel;
    QComboBox* cursus;
    QLabel* UVLabel;
    QTableWidget* tabUV;
    QLabel* UV;
    //QLabel* resultatLabel;
    //QComboBox* resultat;
    QTableWidget* recapCred;
    QLabel* recapLabel;
    QCheckBox* activiteES;
    QCheckBox* B2;
    QPushButton* modifInscr;
    QPushButton* ajoutInscr;
    QLineEdit* nomInscrAModif;
    QPushButton* modifEqui;
    QPushButton* ajoutEqui;
    QLineEdit* nomEquiAModif;
    QPushButton* ajouterCursus;
    QPushButton* supprimerCursus;
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
    DossierEditeur(UVManager& m, QWidget* parent=0);

public slots :
    void sauverDossier();
    //void fenetreAjoutCursus();
    void ajoutInscription();
    void ajoutEquivalence();
    void ajoutCursus();
    void supprimerCur();
    void modifierInscription(bool j=0);
    void modifierEquivalence(bool j=0);
};


#endif // DOSSIER_H

