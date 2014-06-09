#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H
#include "cursus.h"

QString CategorieCursusToString(CategorieCursus c);

class CursusManager{
    Cursus** mesCursus;
    unsigned int nbCursus;
    unsigned int nbMaxCursus;

    void addItem(Cursus* newcursus);
    //bool modification;
    CursusManager(const CursusManager& cm);//pas à faire
    CursusManager& operator=(const CursusManager& cm);//pas à faire
    CursusManager();//pas à faire
    ~CursusManager();//fait
    friend struct Handler;
    struct Handler{
        CursusManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;

public:
    QString file;
    Cursus* trouverCursus(const QString& c) const; //fait mais pas vérifier
    void load(const QString& f); //fait mais pas vérifier
    void save(const QString& f); // fait
    static CursusManager& getInstance(); // fait
    static void libererInstance(); // fait
    void ajouterCursus(const QString n, const QString* t, unsigned int nbU, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP); //fait et vérifié
    void ajouterCursus(Cursus *cur);
    const Cursus& getCursus(const QString& nom) const;// fait et vérifié
    Cursus** getMesCursus() const {return mesCursus;}
    unsigned int getNbCursus() const {return nbCursus;}
    Cursus& getCursus(const QString& nom);// fait et vérifié
    void supprimerCursus(const Cursus& cu);

    class Iterator {
        friend class CursusManager;
        Cursus** currentCursus;
        unsigned int nbRemain;
        Iterator(Cursus** c, unsigned nb):currentCursus(c),nbRemain(nb){}
       public:
            Iterator():nbRemain(0),currentCursus(0){}
            bool isDone() const { return nbRemain==0; }
            void next() {
                if (isDone())
                        throw UTProfilerException("error, next on an iterator which is done");
                nbRemain--;
                currentCursus++;
            }
            Cursus& current() const {
                if (isDone())
                    throw UTProfilerException("error, indirection on an iterator which is done");
                return **currentCursus;
            }
    };
    Iterator getIterator() {
        return Iterator(mesCursus,nbCursus);
   };
};


#endif // CURSUSMANAGER_H
