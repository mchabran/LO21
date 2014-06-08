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

using namespace std;

class Dossier{ //singleton
    CursusManager& cursus;
    Inscription** inscriptions;
    Equivalence** equivalences;
    bool activiteExtraScolaire;
    bool niveauB2;

    static Dossier* instanceUnique;
    Dossier() :cursus(CursusManager::getInstance()) {}
    Dossier(CursusManager& c): cursus(c), inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false) {}

    Dossier(const Dossier* instance);
    virtual ~Dossier();
    virtual void operator=(const Dossier&){}
public :
    // A REMETTRE EN ¨PV
    Dossier(CursusManager& c, Inscription** i, Equivalence** e, bool aes, bool B2) : cursus(c), inscriptions(i), equivalences(e), activiteExtraScolaire(aes), niveauB2(B2){}

    CursusManager& getCursusManager(){return cursus;}
    Inscription** getInscriptions(){return inscriptions;}
    Equivalence** getEquivalences(){return equivalences;}
    bool getActiviteES(){return activiteExtraScolaire;}
    bool getnivB2(){return niveauB2;}
    void setCursus(); //Marche plus car = est privé pour cursusManager
    void setInscriptions(Inscription** i){inscriptions=i;}
    void setEquivalences(Equivalence** e){equivalences=e;}
    void setAES(bool val){activiteExtraScolaire = val;}
    void setNivB2(bool val){niveauB2 = val;}

    static Dossier& donneInstance(CursusManager& c);
    static void libereInstance();
};


class DossierEditeur : public QWidget{
    Q_OBJECT
    UVManager& manager;
    Dossier& doss;
    QLabel* cursusLabel;
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
    QPushButton* modifEqui;
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
    DossierEditeur(UVManager& m, Dossier& d, QWidget* parent=0);

public slots :
    void sauverDossier();
    //void fenetreAjoutCursus();
    void ajoutCursus();
};

#endif // DOSSIER_H

