#ifndef CURSUSFINDER_H
#define CURSUSFINDER_H
/**
  *\file CursusFinder.h
  * \brief Affichage des caractéristiques d'un cursus
  */
#include "CursusManager.h"

/**
 * \class CursusFinder
 * \brief Affichage des caractéristiques d'une classe, hérite de QWidget
 */
class CursusFinder : public QWidget{
    Q_OBJECT
    CursusManager* cM; /** CursusManager*/
    QComboBox* nomCursus;/** nom du cursus*/
    QLabel* nomCursusLabel;
    const Cursus* cu;/** cursus à afficher*/
    QSpinBox* credCS; /** nb de crédits CS du cursus*/
    QLabel* CSLabel;
    QSpinBox* credTM;/** nb de crédits TM du cursus*/
    QLabel* TMLabel;
    QSpinBox* credTSH;/** nb de crédits TSH du cursus*/
    QLabel* TSHLabel;
    QSpinBox* credSP; /** nb de crédits SP du cursus*/
    QLabel* SPLabel;
    QComboBox* categorie;/** Catégorie du cursus*/
    QLabel* categorieLabel;

    QComboBox* UVs;/** Uvs du cursus*/
    QLabel* UVsLabel;

    QPushButton* annuler;/** Bouton annuler*/
    QPushButton* supprimerC;/** Bouton supprimer*/
    QPushButton* ajouterC; /** Bouton ajout*/
    QPushButton* editerC;/** Bouton édition*/
    QPushButton* actualiserC;/** Bouton actualisation*/

    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
   // QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;
    QHBoxLayout* coucheH7;
    QHBoxLayout* coucheH8;
    QHBoxLayout* coucheH9;

public :
    /**
     * \class CursusFinder
     * \param M : CursusManager
     * \param parent : QWidget parent, 0 par défaut
     */
    CursusFinder(CursusManager* M, QWidget* parent=0);
public slots :
    /**
     * \brief Ajout d'un nouveau cursus
     */
    void ajouter();
    /**
     * \brief Edition du cursus sélectionné
     */
    void editer();
    /**
     * \brief Suppression du cursus sélectionné
     */
    void supprimer();
    /**
     * \brief Actualisation de l'affichage
     * \param cursusN
     */
    void afficher(QString cursusN=0);
    /**
     * \brief actualisation de la fenêtre
     */
    void actualisation();
};

#endif // CURSUSFINDER_H
