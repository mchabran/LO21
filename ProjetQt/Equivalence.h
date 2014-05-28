#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H
#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"

class Equivalence{
    QString nomEtablissement;
    QString pays;
    unsigned int equiCS;
    unsigned int equiTM;
    unsigned int equiTSH;
    unsigned int equiSP;
public :
    Equivalence(QString nom, QString p, unsigned int Cs, unsigned int Tm, unsigned int Tsh, unsigned int Sp=0):nomEtablissement(nom), pays(p), equiCS(Cs), equiTM(Tm), equiTSH(Tsh), equiSP(Sp){}
    QString getNomEtablissement()const{return nomEtablissement;}
    QString getPays()const{return pays;}
    unsigned int getEquiCS()const{return equiCS;}
    unsigned int getEquiTM()const{return equiTM;}
    unsigned int getEquiTSH()const{return equiTSH;}
    unsigned int getEquiSP()const{return equiSP;}

    void setNomEtablissement(QString n){nomEtablissement=n;}
    void setPays(QString p){pays=p;}
    void setEquiCS(unsigned int C){equiCS=C;}
    void setEquiTM(unsigned int T){equiTM=T;}
    void setEquiTSH(unsigned int Tsh){equiTSH=Tsh;}
    void setEquiSP(unsigned int S){equiSP=S;}

};


#endif // EQUIVALENCE_H