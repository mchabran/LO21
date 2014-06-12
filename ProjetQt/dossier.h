#ifndef DOSSIER_H
#define DOSSIER_H
/**
  *\file dossier.h
  * \brief contient la classe permettant de créer un dossier
  */
#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"
#include "Inscription.h"
#include "Equivalence.h"
#include "CursusManager.h"
#include <QTableWidget>
#include <QListView>
#include <QLineEdit>

using namespace std;

class Inscription;
class Equivalence;

/**
 * \class Dossier
 * \brief Singleton permettant de créer le dossier à gérer dans l'application
 */
class Dossier{
    QString fileI;/** fichier d'inscriptions*/
    QString fileE; /** fichier d'Equivalence*/
    QString fileD; /** fichier de Dossier */
    CursusManager& CM;/** référence vers le CursusManager*/
    UVManager& UVM; /** référence vers l'UVManager*/
    Cursus** cursus;/** tableau contenant les cursus suivi par l'étudiant*/
    Inscription** inscriptions;/** inscriptions de l'étudiant*/
    Equivalence** equivalences;/** équivalences de l'étudiant*/
    bool activiteExtraScolaire;/** validation de l'activité extra scolaire*/
    bool niveauB2;/** validation du niveau B2*/
    unsigned int nbCur;/** nb de cursus suivis par l'étudiant*/
    unsigned int nbMaxCur;/** nb maximum de cursus que suit l'étudiant*/
    unsigned int nbIns;/** nb d'inscriptions d'un étudiant*/
    unsigned int nbMaxIns;/** nb maximum d'inscriptions d'un étudiant*/
    unsigned int nbEq;/** nb d'équivalences obtenues par un étudiant*/
    unsigned int nbMaxEq;/** nb maximum d'équivalences obtenues par un étudiant*/
    static Dossier* instanceUnique; /** unique instance de la classe dossier*/
    /**
     * \brief Constructeur
     * \param c : CursusManager
     * \param u : UVManager
     * \param tabCur : tableau de cursus dans lesquels est inscrit l'étudiant
     * \param tabI : tableau d'inscriptions de l'étudiant
     * \param tabE : tableau d'équivalences obtenues par l'étudiant
     * \param aes : validation de l'activité extra-scolaire
     * \param B2 : validation du niveau B2
     * \param nc : nombre de cursus suivis par l'étudiant
     * \param ni : nb d'inscritptions de l'étudiant
     * \param ne : nb d'équivalences obtenues par l'étudiant
     */
    Dossier(CursusManager& c, UVManager& u, Cursus** tabCur, Inscription** tabI, Equivalence** tabE, bool aes, bool B2, unsigned int nc, unsigned int ni, unsigned int ne);
    /**
     * \brief Constructeur sans arguments
     * \param c : CursusManager
     * \param u : UVManager
     */
    Dossier(CursusManager& c=CursusManager::getInstance(), UVManager& u=UVManager::getInstance()): CM(c), UVM(u), inscriptions(new Inscription*), equivalences(new Equivalence*), activiteExtraScolaire(false), niveauB2(false), nbCur(0), nbIns(0), nbEq(0), nbMaxCur(0), nbMaxIns(0), nbMaxEq(0),fileI(""), fileE(""), fileD("") {}
    /**
     * \brief Constructeur par recopie mis en privé pour ne pas pouvoir être utilisé
     * \param instance : instance à recopier => impossible
     */
    Dossier(const Dossier* instance);
    /**
     * \brief Destructeur
     */
    virtual ~Dossier();
    /**
     * \brief Surcharge de l'opérateur =
     */
    virtual void operator=(const Dossier&){}
public :
    /**
     * \brief Récupération du CursusManager
     * \return référence sur l'unique instance du cursusManager
     */
    CursusManager& getCursusManager() const {return CM;}
    /**
     * \brief Récupération du tableau de cursus
     * \return tableau de pointeurs sur les différents cursus suivis par l'étudiant
     */
    Cursus** getCursus() const {return cursus;}
    /**
     * \brief Récupération du tableau d'e cursus'inscriptions
     * \return tableau de pointeurs sur les différentes inscriptions de l'étudiant
     */
    Inscription** getInscriptions() const {return inscriptions;}
    /**
     * \brief Chargement du fichier contenant les inscriptions dans le dossier
     * \param f : chemin du fichier
     */
    void loadInscription(const QString& f);
    /**
     * \brief Mise à jour et sauvegarde du fichier contenant les inscriptions dans le dossier
     * \param f : chemin du fichier
     */
    void saveInscription(const QString &f);
    /**
     * \brief Chargement du fichier contenant les équivalences dans le dossier
     * \param f : chemin du fichier
     */
    void loadEquivalence(const QString& f);
    /**
     * \brief Mise à jour et sauvegarde du fichier contenant les équivalences dans le dossier
     * \param f : chemin du fichier
     */
    void saveEquivalence(const QString& f);
    /**
     * \brief Chargement du fichier contenant le dossier
     * \param f : chemin du fichier
     */
    void loadDossier(const QString &f);
    /**
     * \brief Mise à jour et sauvegarde du fichier contenant le dossier
     * \param f : chemin du fichier
     */
    void saveDossier(const QString &f);
    /**
     * \brief Récupération des équivalences obtenues
     * \return un tableau de pointeurs vers les équivalences obtenues par l'étudiant
     */
    Equivalence** getEquivalences() const {return equivalences;}
    /**
     * \brief Récupération du nb de cursus suivis par l'étudiant
     * \return le nb de cursus suivis par l'étudiant
     */
    unsigned int getNbCur() const{return nbCur;}
    /**
     * \brief Récupération du nb d'inscriptions de l'étudiant
     * \return le nb d'inscriptions de l'étudiant
     */
    unsigned int getNbIns() const{return nbIns;}
    /**
     * \brief Récupération du nb d'équivalences obtenues par l'étudiant
     * \return le nb d'équivalences obtenues par l'étudiant
     */
    unsigned int getNbEq() const{return nbEq;}
    /**
     * \brief Vérification de la validation de l'activité extra-universitaire
     * \return true si l'activité extra-universitaire est validée
     */
    bool getActiviteES(){return activiteExtraScolaire;}
    /**
     * \brief Vérification de la validation du niveau B2
     * \return true si le niveau B2 a été validé
     */
    bool getnivB2(){return niveauB2;}
    /**
     * \brief Ajout d'un cursus
     * \param c : cursus à ajouter
     */
    void addCursus(Cursus* c);
    /**
     * \brief suppression d'un cursus
     * \param c : cursus à supprimer
     */
    void supprCur(Cursus* c);
    /**
     * \brief ajout d'une inscription
     * \param i  :Inscription à ajouter
     */
    void addInscription(Inscription* i);
    /**
     * \brief ajout d'une équivalence
     * \param e : équivalence à ajouter
     */
    void addEquivalence(Equivalence* e);
    /**
     * \brief mise à jour de l'activité extra-scolaire
     * \param val : true ou false
     */
    void setAES(bool val){activiteExtraScolaire = val;}
    /**
     * \brief mise à jour de la validation du niveau B2
     * \param val : true ou false
     */
    void setNivB2(bool val){niveauB2 = val;}
    /**
     * \brief Donner l'instance unique de Dossier
     * \param c : instance unique de CursusManager
     * \param u : instance unique de UVManager
     * \return référence sur l'instance unique de Dossier
     */
    static Dossier& donneInstance(CursusManager& c, UVManager& u);
    /**
     * \brief libération de l'instance unique de Dossier
     */
    static void libereInstance();
    /**
     * \brief Chargement du fichier contenant le dossier
     * \param f : chemin vers le fichier
     */
    void load(const QString& f);
    //void save(const QString& f);
};





#endif // DOSSIER_H

