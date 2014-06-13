#ifndef MENUEDITEUR_H
#define MENUEDITEUR_H
/**
  *\file MenuEditeur.h
  * \brief Menu initial de l'application
  */
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>
#include "UTProfiler.h"

/**
 * \class MenuEditeur
 * \brief Editeur du menu permettant d'accéder aux différentes fonctions de l'application
 */
class MenuEditeur : public QWidget{
    Q_OBJECT
    UVManager& um;/** référence vers l'unique instance d'UVManager*/
    QPushButton* ajoutDoss; /** bouton permettant d'ajouter un dossier*/
    QPushButton* consultDoss; /** bouton permettant d'ajouter un dossier*/
    QPushButton* ajoutEqui;/** bouton permettant d'ajouter une équivalence*/
    QPushButton* ajoutInscr;/** bouton permettant d'ajouter une inscription*/
    QPushButton* consultUV;/** bouton permettant de rechercher une UV*/
    QPushButton* fermeture;/** bouton permettant de lancer la sauvegarde des fichiers et de quitter l'application*/
   // QPushButton* ajoutCursus;
    QPushButton* consultCursus;/** bouton permettant d'éditer un cursus*/
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;

public :
    /**
     * \brief Constructeur
     * \param u : référence vers l'unique instance d'UVManager
     * \param parent : QWidget parent
     */
    MenuEditeur(UVManager &u, QWidget* parent=0);
public slots :
    /**
     * \brief ajout d'une nouvelle instance unique de Dossier
     */
    void ajouterDossier();
    //void EditionCursus();
    //void ajouterEquivalence();
    //void ajouterInscription();
    /**
     * \brief recherche d'une UV
     */
    void consulterUV();
    /**
     * \brief recherche d'un cursus
     */
    void consulterCursus();
    void fin();
};

#endif // MENUEDITEUR_H
