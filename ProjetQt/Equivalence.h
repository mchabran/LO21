#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H
/**
  *\file Equivalence.h
  * \brief Fichier contenant l'éditeur d'équivalence
  */
#include <QString>
#include <QTextStream>
#include "cursus.h"
#include "UTProfiler.h"
#include "dossier.h"

/**
 * \class Equivalence
 * \brief Permet à l'étudiant d'ajouter des crédits qu'il aurait obtenu en équivalence dans d'autres établissements que l'UTC
 */
class Equivalence{
    QString nomEtablissement;/** nom de l'établissement*/
    QString pays;/** pays où l'équivalence a été obtenue*/
    unsigned int equiCS;/** nb de crédits CS obtenus*/
    unsigned int equiTM;/** nb de crédits TM obtenus*/
    unsigned int equiTSH;/** nb de crédits TSH obtenus*/
    unsigned int equiSP;/** nb de crédits SP obtenus*/
public :
    /**
     * \brief Constructeur par recopie
     * \param e : adresse de l'équivalence à recopier
     */
    Equivalence(Equivalence* e);
    /**
     * \brief Constructeur avec arguments
     * \param nom : nom de l'établissement
     * \param p : pays
     * \param Cs : nb de crédits CS obtenus
     * \param Tm : nb de crédits TM obtenus
     * \param TSH : nb de crédits TSH obtenus
     * \param Sp : nb de crédits SP obtenus
     */
    Equivalence(QString nom, QString p, unsigned int Cs, unsigned int Tm, unsigned int Tsh, unsigned int Sp=0):nomEtablissement(nom), pays(p), equiCS(Cs), equiTM(Tm), equiTSH(Tsh), equiSP(Sp){}
    /**
     * \brief Récupérer le nom de l'établissement
     * \return une QString contenant le nom de l'établissement
     */
    QString getNomEtablissement()const{return nomEtablissement;}
    /**
     * \brief Récupérer le nom du pays
     * \return une QString contenant le nom du pays
     */
    QString getPays()const{return pays;}
    /**
     * \brief Récupérer le nombre de crédits CS obtenus
     * \return le nombre de crédits CS obtenus
     */
    unsigned int getEquiCS()const{return equiCS;}
    /**
     * \brief Récupérer le nombre de crédits TM obtenus
     * \return le nombre de crédits TM obtenus
     */
    unsigned int getEquiTM()const{return equiTM;}
    /**
     * \brief Récupérer le nombre de crédits TSH obtenus
     * \return le nombre de crédits TSH obtenus
     */
    unsigned int getEquiTSH()const{return equiTSH;}
    /**
     * \brief Récupérer le nombre de crédits SP obtenus
     * \return le nombre de crédits SP obtenus
     */
    unsigned int getEquiSP()const{return equiSP;}
    /**
     * \brief mise à jour du nom de l'établissement
     * \param n : nom du nouvel établissement
     */
    void setNomEtablissement(QString n){nomEtablissement=n;}
    /**
     * \brief mise à jour du nom du pays
     * \param p : nom du nouveau pays
     */
    void setPays(QString p){pays=p;}
    /**
     * \brief mise à jour du nombre de crédits CS obtenus
     * \param C : nouveau nb de crédits CS
     */
    void setEquiCS(unsigned int C){equiCS=C;}
    /**
     * \brief mise à jour du nombre de crédits TM obtenus
     * \param T : nouveau nb de crédits TM
     */
    void setEquiTM(unsigned int T){equiTM=T;}
    /**
     * \brief mise à jour du nombre de crédits TSH obtenus
     * \param Tsh : nouveau nb de crédits TSH
     */
    void setEquiTSH(unsigned int Tsh){equiTSH=Tsh;}
    /**
     * \brief mise à jour du nombre de crédits SP obtenus
     * \param S : nouveau nombre de crédits SP obtenus
     */
    void setEquiSP(unsigned int S){equiSP=S;}

};

class Dossier;

/**
 * \class EquivalenceEditeur
 * \brief Editeur d'équivalence, dérive de la classe QWidget
 */
class EquivalenceEditeur : public QWidget{
    Q_OBJECT
    Dossier* unDossier;/** instance unique de Dossier*/
    Equivalence* equivalence;/** équivalence à éditer*/
    QLabel* nomEtLabel;
    QLineEdit* nomEt;/** zone de texte contenant le nom de l'établissement*/
    QLabel* paysLabel;
    QLineEdit* pays;/** zone de texte contenant le nom du pays*/
    QLabel* csLabel;
    QSpinBox* cs;/** nombre de crédits CS obtenus*/
    QLabel* tmLabel;
    QSpinBox* tm;/** nombre de crédits TM obtenus*/
    QLabel* tshLabel;
    QSpinBox* tsh;/** nombre de crédits TSH obtnenus*/
    QLabel* spLabel;
    QSpinBox* sp;/** nombre de crédits SP obtenus*/
    QVBoxLayout* couche;
    QHBoxLayout* coucheh;
    QPushButton* sauver;/** bouton permettant de sauver l'équivalence*/
    QPushButton* ajouter;/** bouton permettant d'ajouter une nouvelle équivalence*/
public :
    /**
     * \brief constructeur avec paramètres
     * \param d : adresse de l'instance unique de Dossier
     * \param eq : adresse de l'équivalence à modifier
     * \param parent : QWidget parent
     */
    EquivalenceEditeur(Dossier* d,Equivalence *eq=0, QWidget* parent=0);
public slots :
    /**
     * \brief Met à jour l'équivalence avec les paramètres rentrés dans l'éditeur et ferme la fenêtre d'édition
     */
    void modifEqui();
};


#endif // EQUIVALENCE_H
