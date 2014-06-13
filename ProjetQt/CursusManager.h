#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H
/**
  *\file CursusManager.h
  *\brief gestion des cursus existant
  */
#include "cursus.h"

/**
 * \brief Convertion d'une categorie de cursus en string
 * \param c  :catégorir de cursus à convertit
 * \return une QString contenant le nom de la catégorie du cursus
 */
QString CategorieCursusToString(CategorieCursus c);

/**
 * \class CursusManager
 * \brief singleton qui gère les différents cursus existant
 */
class CursusManager{
    Cursus** mesCursus;/** tableau contenant les cursus existant*/
    unsigned int nbCursus; /** nombre de cursus existant*/
    unsigned int nbMaxCursus;/** nombre maximum de cursus*/

    /**
     * \brief Ajout de cursus dans le tableau
     * \param newcursus : cursus à ajouter
     */
    void addItem(Cursus* newcursus);
    /**
     * \brief Constructeur par recopie mis en privé pour ne pas pouvoir l'utiliser
     * \param cm : constructeur à recopier
     */
    CursusManager(const CursusManager& cm);//pas à faire
    /**
     * \brief Surcharge de l'opérateur = mis en privé pour ne pas pouvoir l'utiliser
     * \param cm : CursusManager
     * \return une référence sur le cursusManager
     */
    CursusManager& operator=(const CursusManager& cm);//pas à faire
    /**
     * \brief Constructeur sans arguments
     */
    CursusManager();//pas à faire
    /**
      *\brief destructeur
      */
    ~CursusManager();//fait
    friend struct Handler;
    /**
     * \struct Handler
     */
    struct Handler{
        CursusManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;/** handler */

public:
    QString file; /** fichier contenant les cursus exitants*/
    /**
     * \brief trouver un cursus
     * \param c : nom du cursus recherché
     * \return l'adresse du cursus recherché, 0 s'il n'est pas trouvé
     */
    Cursus* trouverCursus(const QString& c) const;
    /**
     * \brief Charge le fichier contenant la description des cursus
     * \param f : chemin contenant le fichier
     */
    void load(const QString& f);
    /**
     * \brief Sauvegarde et met à jour le fichier contenant les cursus
     */
    void save();
    /**
     * \brief Donne l'instance unique de CursusManager
     * \return une référence sur l'instance unique
     */
    static CursusManager& getInstance();
    /**
     * \brief Libère l'instance unique
     */
    static void libererInstance();
    /**
     * \brief ajout de cursus au cursusManager
     * \param n : nom du cursus
     * \param t : tableau d'UVs du cursus à ajouter
     * \param nbU : nombre d'UVs dans le cursus
     * \param c : catégorie du cursus
     * \param CS : nombre de crédits CS
     * \param TM : nombre de crédits TM
     * \param TSH : nombre de crédits TSH
     * \param SP : nombre de crédits SP
     */
    void ajouterCursus(const QString n, const QString* t, unsigned int nbU, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP); //fait et vérifié*
    /**
     * \brief ajout de cursus par recopie
     * \param cur : cursus à recopier
     */
    void ajouterCursus(Cursus *cur);
    /**
     * \brief Récupération du cursus d'un nom donné
     * \param nom : nom du cursus recherché
     * \return une référence constante sur le cursus trouvé
     */
    const Cursus& getCursus(const QString& nom) const;
    /**
     * \brief Récupération des cursus existants
     * \return un tableau de pointeurs des différents cursus
     */
    Cursus** getMesCursus() const {return mesCursus;}
    /**
     * \brief Récupération du nombre de cursus
     * \return le nombre de cursus existant
     */
    unsigned int getNbCursus() const {return nbCursus;}
    /**
     * \brief Récupération des cursus existant
     * \param nom : nom du cursus recherché
     * \return une référence constante sur le cursus recherché
     */
    Cursus& getCursus(const QString& nom);
    /**
     * \brief Suppression du cursus
     * \param cu : cursus à supprimer
     */
    void supprimerCursus(const Cursus& cu);

    /**
     * \class Iterator
     * \brief Permet d'avoir un itérateur sur les cursus
     */
    class Iterator {
        friend class CursusManager;/** définition de la classe CursusManager en ami pour pouvoir itérer sur ses éléments*/
        Cursus** currentCursus; /** pointeur sur un cursus*/
        unsigned int nbRemain;/** nb de cursus restant avant d'atteindre la fin du tableau*/
        /**
         * \brief Constructeur
         * \param c : cursus sur lequel commencer l'itération
         * \param nb : nombre de cursus restant avant la fin du tableau
         */
        Iterator(Cursus** c, unsigned nb):currentCursus(c),nbRemain(nb){}
       public:
            /**
             * \brief Constructeur sans argument qui initialise les éléments à 0
             */
            Iterator():nbRemain(0),currentCursus(0){}
            /**
             * \brief Teste si la fin du tableau est atteinte
             * \return true si la fin du tableau est atteinte, 0 sinon
             */
            bool isDone() const { return nbRemain==0; }
            /**
             * \brief Passe au cursus suivant dans le tableau
             */
            void next() {
                if (isDone())
                        throw UTProfilerException("error, next on an iterator which is done");
                nbRemain--;
                currentCursus++;
            }
            /**
             * \brief Cursus actuellement pointé
             * \return le cursus sur lequel l'itérateur pointe
             */
            Cursus& current() const {
                if (isDone())
                    throw UTProfilerException("error, indirection on an iterator which is done");
                return **currentCursus;
            }
    };
    /**
     * \brief Création d'un itérateur
     * \return un itérateur sur les cursus créés
     */
    Iterator getIterator() {
        return Iterator(mesCursus,nbCursus);
   };
};


#endif // CURSUSMANAGER_H
