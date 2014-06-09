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

class Dossier{ //singleton
    CursusManager& cursus;
    Inscription** inscriptions;
    Equivalence** equivalences;
    bool activiteExtraScolaire;
    bool niveauB2;
    unsigned int nbIns;
    unsigned int nbEq;
    static Dossier* instanceUnique;

    Dossier(CursusManager& c, Inscription** i, Equivalence** e, bool aes, bool B2, unsigned int ni=0, unsigned int ne=0) : cursus(c), inscriptions(i), equivalences(e), activiteExtraScolaire(aes), niveauB2(B2), nbIns(ni), nbEq(ne) {}
    Dossier() :cursus(CursusManager::getInstance()), inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false), nbIns(0), nbEq(0) {}
    Dossier(CursusManager& c): cursus(c), inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false), nbIns(0), nbEq(0) {}
    Dossier(const Dossier* instance);
    virtual ~Dossier();
    virtual void operator=(const Dossier&){}
public :

    CursusManager& getCursusManager() const {return cursus;}
    Inscription** getInscriptions() const {return inscriptions;}
    Equivalence** getEquivalences() const {return equivalences;}
    unsigned int getNbIns() const{return nbIns;}
    unsigned int getNbEq() const{return nbEq;}
    bool getActiviteES(){return activiteExtraScolaire;}
    bool getnivB2(){return niveauB2;}
    void addInscription(Inscription* i){inscriptions[nbIns++]=i;}
    void addEquivalence(Equivalence* e){equivalences[nbEq++]=e;}
    void setAES(bool val){activiteExtraScolaire = val;}
    void setNivB2(bool val){niveauB2 = val;}
    static Dossier& donneInstance(CursusManager& c);
    static void libereInstance();

    void load(const QString& f);
    //void save(const QString& f);
};


class DossierEditeur : public QWidget{
    Q_OBJECT
    UVManager& manager;
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
    QLineEdit* nomInscrAModif;
    QPushButton* modifEqui;
    QLineEdit* nomEquiAModif;
    QPushButton* ajouterCursus;
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
    void modifCursus();
    void modifierInscription();
    void modifierEquivalence();
};

#endif // DOSSIER_H

