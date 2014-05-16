#ifndef DOSSIER_H
#define DOSSIER_H

#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"

using namespace std;

class Dossier{
    Cursus** cursus;
    //Inscription** inscriptions;
    //Equivalence** equivalences; //a decommenter quand la classe sera implémentée
    bool activiteExtraScolaire;
    bool niveauB2;

    static Dossier* instanceUnique;
    Dossier(Cursus** c): cursus(c), /*inscriptions(new Inscription*), equivalences(new Equivalence*),*/ activiteExtraScolaire(false), niveauB2(false) {}
    Dossier(const Dossier* instance);
    virtual ~Dossier();
    virtual void operator=(const Dossier&){}
public :
    Cursus** getCursus(){return cursus;}
    //Inscription** getInscriptions(){return inscriptions;}
    //Equivalence** getEquivalences(){return equivalences;}
    bool getActiviteES(){return activiteExtraScolaire;}
    bool getnivB2(){return niveauB2;}
    void validerNivB2(){niveauB2=true;}
    void validerActiviteES(){activiteExtraScolaire=true;}

    static Dossier& donneInstance();
    static void libereInstance();
};




#endif // DOSSIER_H
