#ifndef DOSSIER_H
#define DOSSIER_H

#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"

using namespace std;

class Dossier{ //singleton
    Cursus** cursus;
    Inscription** inscriptions;
    //Equivalence** equivalences; //a decommenter quand la classe sera implémentée
    bool activiteExtraScolaire;
    bool niveauB2;

    static Dossier* instanceUnique;
    ///manque pas un constructeur avec paramètres ?
    Dossier(): cursus(new Cursus*){}
    Dossier(Cursus** c): cursus(c), /*inscriptions(new Inscription*), equivalences(new Equivalence*),*/ activiteExtraScolaire(false), niveauB2(false) {}
    Dossier(const Dossier* instance);
    virtual ~Dossier();
    virtual void operator=(const Dossier&){}
public :
    Cursus** getCursus(){return cursus;}
    Inscription** getInscriptions(){return inscriptions;}
    //Equivalence** getEquivalences(){return equivalences;}
    bool getActiviteES(){return activiteExtraScolaire;}
    bool getnivB2(){return niveauB2;}

    void setCursus(Cursus** c){cursus=c;}
    void setInscriptions(Inscription** i){inscriptions=i;}
    //void setEquivalences(Equivalence** e){equivalences=e}
    void setAES(bool val){activiteExtraScolaire = val;}
    void setNivB2(bool val){niveauB2 = val;}

    static Dossier& donneInstance(Cursus** c);
    static void libereInstance();
};


class DossierEditeur : public QWidget{
    Q_OBJECT
    Dossier& doss;
    Cursus** cur;
    QLabel* nomCursusLabel;
    QLineEdit* nomCursus;
    QLabel* categorieCursusLabel;
    QComboBox* categorieCursus;
    QLabel* nomUVLabel;
    QLineEdit* nomUV;
    QLabel* categorieUVLabel;
    QComboBox* categorieUV;
    QLabel* resultatLabel;
    QComboBox* resultat;
    QCheckBox* activiteES;
    QCheckBox* B2;
    QPushButton* sauver;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
public :
    DossierEditeur(Dossier& d, Cursus** c, QWidget* parent=0);

//public slots :
    void sauverDossier(); ///tu ne l'as pas implémenté dans le .cpp ? //Non pas encore
};

#endif // DOSSIER_H

