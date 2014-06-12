#ifndef CURSUSEDITEUR_H
#define CURSUSEDITEUR_H
/**
  *\file CursusEditeur.h
  * \brief Permet d'éditer graphiquement un cursus
  */
#include "cursus.h"
#include "CursusManager.h"

/**
 * \class CursusEditeur
 * \brief contient les éléments nécessaires à l'édition de cursus, hérite de QWidget
 *
 */
class CursusEditeur :  public QWidget {
    /**
     *\brief nécéssaire à la création d'une fenêtre
     */
    Q_OBJECT
    CursusManager* cM;/** CursusManager nécessaire pour la gestion du cursus que l'on édite*/
    const Cursus* cu;/** cursus à éditer */
    QLineEdit* nomCursus;/** zone de texte où le nouveau nom du cursus sera rentré */
    QLabel* nomLabel; /** Label indquant le nom du cursus*/
    QSpinBox* credCS;/** nouveau nombre de crédits CS*/
    QLabel* CSLabel;
    QSpinBox* credTM; /** nouveau nombre de crédits TM*/
    QLabel* TMLabel;
    QSpinBox* credTSH;/** nouveau nombre de crédits TSH*/
    QLabel* TSHLabel;
    QSpinBox* credSP; /** nouveau nombre de crédits SP*/
    QLabel* SPLabel;
    QComboBox* categorie;/** menu déroulant donnant les différente scatégories auxquelles appartient le cursus*/
    QLabel* categorieLabel;

    QComboBox* UVs;/** menu déroulant donnant les différente UVs  cursus*/
    QLabel* UVsLabel;
    QPushButton* supprimerUV; /** boutton permettant de supprimer du cursus l'UV sélectionnée*/

    QLineEdit* newUV; /** ligne de texte permettant d'insérer une nouvelle UV dans le cursus*/
    QLabel* UVLabel;
    QPushButton* ok; /** bouton permettant d'ajouter un nouvelle UV*/

    QPushButton* sauver; /** bouton permettant de sauvegarder les modifications*/
    QPushButton* annuler;/** boton permettant de fermer la fenêtre*/
    QPushButton* ajouter;/** bouton permettant d'ajouter un nouveau cursus*/
    //QPushButton* supprimerCursus; //a implémenter avec toutes les méthodes nécessaires dans CursusManager
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;
    QHBoxLayout* coucheH7;
    QHBoxLayout* coucheH8;


public :
    /**
     * \brief CursusEditeur
     * \param m : CursusManager
     * \param c : Cursus à éditer
     * \param parent : QWidget parent
     */
    CursusEditeur(CursusManager* m, const Cursus* c=0,QWidget* parent=0);

public slots :
    /**
    * \brief Ajout d'un nouveau cursus
    */
   void ajouterCursus();
   /**
    * \brief Sauvegarde du cursus
    */
   void sauverCursus();
   /**
    * \brief ajout d'UV au cursus
    */
   void ajoutUV();
};

#endif // CURSUSEDITEUR_H
