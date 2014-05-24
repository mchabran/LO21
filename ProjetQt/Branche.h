#ifndef BRANCHE_H
#define BRANCHE_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include "cursus.h"

using namespace std;

class Filiere { //composition dans la classe Branche --> donc constructeur privée
                //mais en faite ca peut pas être une composition ? Comment on fait dans le dossier pour dire qu'on suit tel filière si toutes les filières sont dans la branche ?
                //il faudrait plutot un héritage ?
                //je finirai d'implémenter tout ca quand ca sera clair
    QString nomF;
    unsigned int credPSFCS;
    unsigned int credPSFTM;
    Filiere();
    Filiere(const Filiere* f);
    void operator=(const Filiere&){}
    Filiere(QString n, unsigned int CS, unsigned int TM): credPSFCS(CS), credPSFTM(TM){}
    friend class Branche;
public :
    QString getNomFiliere(){return nomF;}
    unsigned int getCredPSFCS(){return credPSFCS;}
    unsigned int getCredPSFTM(){return credPSFTM;}

    void setNomFiliere(QString n){nomF=n;}
    void setCredPSFCS(unsigned int C){credPSFCS=C;}
    void setCredPSFTM(unsigned int T){credPSFTM=T;}

};

class Branche : public Cursus{ //non singleton, plusieurs branche, mais seulement la classe CursusManager peut le créer

    QString credPCBCS; ///pourquoi QString et pas unsigned int ?
    QString credPCBTM;
    //QString credTSH;
    QString credSP;
    Filiere* filiere; //dans une branche, il peut y avoir plusieurs filières

    Branche(); //interdiction de l'instancier, seul cursusManager peut le faire
    Branche(const Branche* instance); //pareil
    Branche(QString CS, QString TM, QString SP, QString n, CategorieCursus c):Cursus(n, c), credPCBCS(CS), credPCBTM(TM), credSP(SP){}
    virtual ~Branche() {}
    void operator=(const Branche&){}
    //friend class CursusManager; A decommenter quand on aura créer la classe CursusManager
public :
    QString getCredPCBCS()const {return credPCBCS;}
    QString getCredPCBTM()const {return credPCBTM;}
    //QString getCredTSH() const {return credTSH;}
    QString getCredSP() const {return credSP;}

    void setCredPCBCS(QString n){credPCBCS=n;}
    void setCredPCBTM(QString n){credPCBTM=n;}
    //void setCredTSH(QString n){credTSH=n;}
    void setCredSP(QString n){credSP=n;}

};


#endif // BRANCHE_H
