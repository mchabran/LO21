#ifndef DOSSIEREDITEUR_H
#define DOSSIEREDITEUR_H
/**
  *\file DossierEditeur.h
  * \brief Contient la classe permettant d'éditer un dossier graphiquement
  */
#include"dossier.h"

/**
 * \class DossierEditeur
 * \brief Permet d'éditer un dossier graphiquement, hérite de la classe QWidget
 */
class DossierEditeur : public QWidget{
    Q_OBJECT
    UVManager& manager;/** instance unique d'UVManager*/
    CursusManager& CM;/** Instance unique de CursusManager*/
    Dossier& doss;/** référence vers l'instance unique de Dossier*/
    QLabel* cursusLabel;
    QLabel* nomCursusLabel;
    QLineEdit* nomNouvCur;/** zone de texte contenant le nom d'un cursus à ajouter*/
    QTableWidget* equivalences;/** tableau récapitulatif des équivalences*/
    QLabel* equivalencesLabel;
    QComboBox* cursus;/** liste déroulante contenant les cursus auxquels l'étudiant est inscrit*/
    QLabel* UVLabel;
    QTableWidget* tabUV;/** tableau récapitulatif des UVs auxquelles est insrit l'étudiant*/
    QLabel* UV;
    //QLabel* resultatLabel;
    //QComboBox* resultat;
    QTableWidget* recapCred;/** tableau récapitulatif des crédits obtenus par l'étudiant*/
    QLabel* recapLabel;
    QCheckBox* activiteES;/** validation de l'activité extra-universitaire*/
    QCheckBox* B2;/** validation du niveau B2*/
    QPushButton* modifInscr;/** bouton de modification d'une inscription*/
    QPushButton* ajoutInscr;/** bouton d'ajout d'une inscription*/
    QLineEdit* nomInscrAModif;/** zone de texte contenant le nom de l'UV pour modifier l'inscription*/
    QPushButton* modifEqui;/** Bouton pour modifier l'équivalence*/
    QPushButton* ajoutEqui;/** bouton pour ajouter une équivalence*/
    QLineEdit* nomEquiAModif;/** zone de texte où rentrer le nom de l'établissement pour modifier l'équivalence*/
    QPushButton* ajouterCursus;/** bouton pour ajouter un cursus*/
    QPushButton* supprimerCursus;/** bouton pour supprimer un cursus*/
    QPushButton* sauver;/** bouton pour sauver le dossier*/
    QPushButton* annuler;/** bouton pour annuler les modificaions faites au dossier et fermer la fenêtre d'édition*/
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;
public :
    /**
     * \brief Constructeur sans arguments
     * \param m : instance unique d'UVManager
     * \param parent : QWidget parent
     */
    DossierEditeur(UVManager& m, QWidget* parent=0);

public slots :
    /**
     * \brief Sauvegarde les modifications faites au dossier
     */
    void sauverDossier();
    /**
     * \brief Ajout d'une inscription, ouverture de l'éditeur d'inscriptions
     */
    void ajoutInscription();
    /**
     * \brief Ajout d'une équivalence, ouverture de l'éditeur d'équivalences
     */
    void ajoutEquivalence();
    /**
     * \brief Ajout d'un cursus, ouverture d'un CursusFinder
     */
    void ajoutCursus();
    /**
     * \brief Suppression du cursus dont le nom est entré dans la zone de texte
     */
    void supprimerCur();
    /**
     * \brief Modification d'une inscription dont le nom de l'UV est entré dans la zone de texte
     * \param j : booléen permettant de savoir si on créé ou on modifie une inscription
     */
    void modifierInscription(bool j=0);
    /**
     * \brief Modification d'une équivalence dont le nom de l'établissement est entré dans la zone de texte
     * \param j : booléen permettant de savoir si on créé ou on modifie une équivalence
     */
    void modifierEquivalence(bool j=0);
};


#endif // DOSSIEREDITEUR_H
