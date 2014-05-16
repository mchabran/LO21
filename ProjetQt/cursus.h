#ifndef CURSUS_H
#define CURSUS_H
#include <QString>
#include <QTextStream>

using namespace std;


class Cursus{
    QString nom;
public :
    QString getnom() const {return nom;}
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




/*class CursusEditeur : public QWidget{


};
*/




#endif // CURSUS_H
