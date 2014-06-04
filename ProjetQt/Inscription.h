#ifndef INSCRIPTION_H
#define INSCRIPTION_H

class Inscription {
        const UV* uv;
        //Semestre semestre;
        Note resultat;
public:
        Inscription(const UV& u, /*const Semestre& s,*/ Note res=EC):uv(&u),/*semestre(s),*/resultat(res){}
        const UV& getUV() const { return *uv; }
        //Semestre getSemestre() const { return semestre; }
        Note getResultat() const { return resultat; }
        void setResultat(Note newres) { resultat=newres; }
        bool uvResussie(){if (resultat==A || resultat==B || resultat==C || resultat==D || resultat==E) return true; return false;}
};

#endif // INSCRIPTION_H
