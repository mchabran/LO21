#ifndef UT_PROFILER_h
#define UT_PROFILER_h
/**
  *\file UTProfiler.h
  * \brief Fichier contenant les classes nécessaires à la définition d'une UV
  */
#include <QString>
#include <QTextStream>
using namespace std;

/**
 * \class UTProfilerException
 * \brief Classe permettant de lever des exceptions
 */
class UTProfilerException{
public:
    /**
     * \brief constructeurs avec arguments
     * \param message : message à envoyer avec l'exception
     * \param f : fichier
     * \param l : ligne du fichier dans lequel l'exception a été levée
     */
    UTProfilerException(const QString& message, const QString &f="na", unsigned int l=0):
        info(message),file(f),line(l){}
    /**
     * \brief Récupérer une info d'une exception
     * \return une QString contenant le message de l'exception
     */
    QString getInfo() const { return info; }
#ifndef NDEBUG
    /**
     * \brief Récupérer le fichier dans lequel cettte exception a été levée
     * \return le fichier dans lequel cettte exception a été levée
     */
    QString getFile() const { return file; }
    // retourne la ligne du fichier à laquelle cette exception a été levée.
    /**
     * \brief Récupère la ligne concernée par l'exception
     * \return le numéro de la ligne concernée par l'exception
     */
    unsigned int getLine() const { return line; }
#endif
private:
    QString info;/** message à envoyer avec l'exception*/
    QString file;/** fichier dans lequel se trouve l'exception*/
    unsigned int line;/** ligne concernée par l'exception*/

};

/**
 * \enum Categorie
 */
enum Categorie {
 CS,TM,TSH,SP
};

/**
 * \brief Surcharge de l'opérateur <<
 * \param f : flux de sortie
 * \param s : catégorie à ajouter à ce flux
 * \return une référence sur le flux de sortie contenant la catégorie ajoutée
 */
QTextStream& operator<<(QTextStream& f, const Categorie& s);
/**
 * \brief Convertion d'une QString en Categorie
 * \param s : QSting à convertir
 * \return Categorie correspondant à la chaine de caractères passée
 */
Categorie StringToCategorie(const QString& s);
/**
 * \brief Convertion d'une Catégorie en QString
 * \param c : Catégorie à convertir
 * \return QString correspondant à la catégorie passée en argument
 */
QString CategorieToString(Categorie c);
/**
 * \brief Surcharge de l'opérateur >>
 * \param f : fichier d'entrée
 * \param cat : catégorie à ajouter à ce fichier
 * \return une référence sur le fichier modifié
 */
QTextStream& operator>>(QTextStream& f, Categorie& cat);

/**
 * \enum Note
 */
enum Note { A, B, C, D, E, F, FX, RES, ABS, EC};
/**
 * \brief Convertion d'une note en QString
 * \param n : note à convertir
 * \return QString correspondant à la note passée en argument
 */
QString NoteToString(const Note& n);
/**
 * \brief Convertion d'un QString en note
 * \param n : QString à convertir
 * \return Note correspondant à la chaine de caractères passée en argument
 */
Note StringToNote(const QString &n);

/**
 * \enum Saison
 */
enum Saison { Automne, Printemps };
/**
 * \brief surcharge de l'opérateur <<
 * \param f : flux de sortie
 * \param s : saison à ajouter à ce flux de sortie
 * \return  : référence sur le flux de sortie contenant la saison à ajouter
 */
inline QTextStream& operator<<(QTextStream& f, const Saison& s) { if (s==Automne) f<<"A"; else f<<"P"; return f;}
/**
 * \brief Convertion d'une saison en QString
 * \param s : saison à convertir
 * \return QString correspondant à la saison passée en argument
 */
inline QString saisonToString(const Saison& s) { QString sais; if (s==Automne) sais="A"; else sais="P"; return sais;}

/**
 * \class Semestre
 */
class Semestre {
        Saison saison;/** saison du semestre*/
        unsigned int annee;/** année du semestre*/
public:
        /**
         * \brief Constructeur sans arguments
         */
        Semestre(){}
        /**
         * \brief Surcharge de l'opérateur =
         * \param s : semestre à copier
         * \return Référence sur le semestre modifié
         */
        Semestre& operator=(const Semestre& s){saison=s.saison;annee=s.annee; return *this;}
        /**
         * \brief Constructeur avec arguments
         * \param s : saison
         * \param a : année
         */
        Semestre(Saison s, unsigned int a):saison(s),annee(a){ if (annee<1972||annee>2099) throw UTProfilerException("annee non valide"); }
        /**
         * \brief Récupérer la saison d'un semeste
         * \return la saison du semestre
         */
        Saison getSaison() const { return saison; }
        /**
         * \brief récupérer l'année du semestre
         * \return  l'année du semestre
         */
        unsigned int getAnnee() const { return annee; }
};

/**
 * \brief surcharge de l'opérateur <<
 * \param f : flux d'entrée
 * \param s : semestre à ajouter au flux d'entrée
 * \return référence sur le flux d'entrée contenant le semestre
 */
inline QTextStream& operator<<(QTextStream& f, const Semestre& s) { return f<<s.getSaison()<<s.getAnnee()%100; }
/**
 * \brief conversion d'un semestre en QString
 * \param s : semestre à convertir
 * \return QString correspondant au semestre passé en argument
 */
inline QString semestreToString(const Semestre& s) { QString saison=saisonToString(s.getSaison()); saison.append(QString::number(s.getAnnee()));return saison; }
/**
 * \brief Conversion d'une QString en Semestre
 * \param s : QString à convertir
 * \return Semestre correspondant à la chaine de caractères passée en argument
 */
inline Semestre StringToSemestre(const QString s){ Saison sais; if (s[0]==A) sais = Automne; else sais = Printemps;
                                                   QString ann = s[1]; ann.append(s[2]); ann.append(s[3]); ann.append(s[4]);
                                                   Semestre sem(sais, ann.toUInt());
                                                    return sem;}

/**
 * \class UV
 * \brief Classe permettant de définir des UVs
 */
class UV {
    QString code;/** code de l'UV*/
    QString titre;/** titre de l'UV*/
    unsigned int nbCredits;/** nd de crédits apportés apr l'UV*/
    Categorie categorie;/** catégorie de l'UV*/
    bool automne;/** true si UV enseignée à l'automne*/
    bool printemps;/** true si l'UV est enseignée au printemps*/
    /**
     * \brief constructeur de recopie
     * \param u : UV à copier
     */
    UV(const UV& u);
    /**
     * \brief Surcharge de l'opérateur =
     * \param u : uv à affecter
     * \return référence sur l'UV avec les valeurs de l'UV passée en argument
     */
    UV& operator=(const UV& u);
    /**
     * \brief Constructeur avec arguments
     * \param c : code de l'UV
     * \param t : titre de l'UV
     * \param nbc : nb de crédits approtés par l'UV
     * \param cat : catégorie de l'UV
     * \param a : true si UV enseignée à l'automne
     * \param p : true si UV enseignée au printemps
     */
    UV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p):code(c),titre(t),nbCredits(nbc),categorie(cat),automne(a),printemps(p){}
    friend class UVManager;
public:
    /**
     * \brief Récupération du code de l'UV
     * \return le code de l'UV
     */
    QString getCode() const { return code; }
    /**
     * \brief Récupération du titre de l'UV
     * \return le titre de l'UV
     */
    QString getTitre() const { return titre; }
    /**
     * \brief Récupération du nombre de crédits
     * \return le nb de crédits
     */
    unsigned int getNbCredits() const { return nbCredits; }
    /**
     * \brief Récupération de la catégorie
     * \return la catégorie
     */
    Categorie getCategorie() const { return categorie; }
    /**
     * \brief Vérification de l'ouverture de l'UV à automne
     * \return true si l'UV est enseignée à l'automne
     */
    bool ouvertureAutomne() const { return automne; }
    /**
     * \brief Vérification de l'ouverture de l'UV au printemps
     * \return true si l'UV est enseignée au printemps
     */
    bool ouverturePrintemps() const { return printemps; }
    /**
     * \brief Mise à jour du code de l'UV
     * \param c : nouveau code de l'UV
     */
    void setCode(const QString& c) { code=c; }
    /**
     * \brief Mise à jour du titre de l'UV
     * \param t : nouveau titre de l'UV
     */
    void setTitre(const QString& t) { titre=t; }
    /**
     * \brief Mise à jour du nb de crédite de l'UV
     * \param n : nouveau nb de crédits
     */
    void setNbCredits(unsigned int n) { nbCredits=n; }
    /**
     * \brief Mise à jour de la catégorie de l'UV
     * \param c : nouvelle catégorie de l'UV
     */
    void setCategorie(Categorie c) { categorie=c; }
    /**
     * \brief Mise à jour de l'ouverture à l'automne
     * \param b : true ou false
     */
    void setOuvertureAutomne(bool b) { automne=b; }
    /**
     * \brief Mise à jour de l'ouverture au printemps
     * \param b : true ou false
     */
    void setOuverturePrintemps(bool b) { printemps=b; }
};

/**
 * \brief surcharge de l'opérateur <<
 * \param f : flux d'entrée
 * \param uv : uv à ajouter au flux de sortie
 * \return flux d'entrée contenant l'UV
 */
QTextStream& operator<<(QTextStream& f, const UV& uv);




/**
 * \class UVManager
 * \brief Singleton gérant l'ensemble des UVs proposées
 */
class UVManager {
private:
    UV** uvs; /** tableau contenant les adresses de l'ensemble des UVs existantes*/
    unsigned int nbUV;/** nombre d'UVs existantes*/
    unsigned int nbMaxUV;/** nombre maximum d'UVs*/
    /**
     * \brief Ajout d'une UV
     * \param uv : UV à ajouter
     */
    void addItem(UV* uv);
    bool modification;/** true si une modification a été effectuée*/
    /**
     * \brief Rechercher une UV
     * \param c : code de l'UV recherchée
     * \return  l'adresse de l'UV recherchée
     */
    UV* trouverUV(const QString& c) const;
    /**
     * \brief Constructeur par recopie, mis en privé pour ne pas être utilisé
     * \param um : UVManager à recopier => impossible
     */
    UVManager(const UVManager& um);
    /**
     * \brief Surcharge de l'opérateur =
     * \param um : UVManager à affecter au nouveau UVManager
     * \return référence sur le nouvel UVManager
     */
    UVManager& operator=(const UVManager& um);
    /**
     * \brief Constructeur sans argument
     */
    UVManager();
    /**
      *\brief Destructeur
      */
    ~UVManager();
    QString file;/** fichier contenant l'ensemble des UVs existantes*/
    friend struct Handler;
    /**
     * \struct Handler
     */
    struct Handler{
        UVManager* instance; /** instance de l'UVManager*/
        /**
         * \brief constructeur
         */
        Handler():instance(0){}
        /**
          *\brief destructeur
          */
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;/** handler*/

public:
    /**
     * \brief Charger le fichier contenant les UVs
     * \param f : chemin du fichier contenant les UVs
     */
    void load(const QString& f);
    /**
     * \brief Sauver le fichier contenant les UVs
     */
    void save();
    /**
     * \brief Obtenir l'instance unique d'UVManager
     * \return une référence sur l'instance unique
     */
    static UVManager& getInstance();
    /**
     * \brief Libérer l'instance unique
     */
    static void libererInstance();
    /**
     * \brief Ajouter une UV
     * \param c : code de l'UV
     * \param t : titre de l'UV
     * \param nbc : nb de crédits
     * \param cat : catégorie de l'UV
     * \param a : true si l'UV est enseignée à l'automne
     * \param p : true si l'UV est enseignée au printemps
     */
    void ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    /**
     * \brief Supprimer une UV
     * \param u : UV à supprimer
     */
    void supprimerUV(UV& u);
    /**
     * \brief Récupérer une UV
     * \param code : code de l'UV recherchée
     * \return référence constante sur l'UV recherchée
     */
    const UV& getUV(const QString& code) const;
    /**
     * \brief Récupérer une UV
     * \param code : code de l'UV recherchée
     * \return référence sur l'UV recherchée
     */
    UV& getUV(const QString& code);

    /**
     * \class Iterator
     * \brief Permet d'itérer sur les différentes UVs d'UVManager
     */
    class Iterator {
        friend class UVManager;
        UV** currentUV; /** adresse de l'UV pointée*/
        unsigned int nbRemain;/** nb d'UVs restantes avans la fin du tableau*/
        /**
         * \brief constructeur
         * \param u : UV par laquelle commencer
         * \param nb : nb d'UVs restantes avant la fin du tableau
         */
        Iterator(UV** u, unsigned nb):currentUV(u),nbRemain(nb){}
       public:
            /**
             * \brief Constructeur sans aguments
             */
            Iterator():nbRemain(0),currentUV(0){}
            /**
             * \brief Vérifie si la fin du tableau est atteinte
             * \return true si la fin du tableau est atteinte
             */
            bool isDone() const { return nbRemain==0; }
            /**
             * \brief Accéder à l'élément suivant dans le tableau, s'il en existe un
             */
            void next() {
                if (isDone())
                        throw UTProfilerException("error, next on an iterator which is done");
                nbRemain--;
                currentUV++;
            }
            /**
             * \brief Accéder à l'élément pointé
             * \return une référence vers l'UV pointée
             */
            UV& current() const {
                if (isDone())
                    throw UTProfilerException("error, indirection on an iterator which is done");
                return **currentUV;
            }
    };
    /**
     * \brief Récupérer un itérateur sur la classe UVManager
     * \return  l'itérateur créé
     */
    Iterator getIterator() {
        return Iterator(uvs,nbUV);
   }
};





#endif
