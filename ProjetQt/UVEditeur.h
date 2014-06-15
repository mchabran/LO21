#ifndef UVEDITEUR_H
#define UVEDITEUR_H
/**
  *\file UVEditeur.h
  *\brief Contient la classe permettant d'éditer une UV
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
 * \class UVEditeur
 * \desc Permet d'éditer une UV, hérite de la classe QWidget
 */
class UVEditeur : public QWidget {
   Q_OBJECT
   UV& uv;/** uv à éditer*/
   QLineEdit* code;/** zone de texte contenant le code de l'UV à éditer*/
   QLabel* codeLabel;
   QTextEdit* titre;/** zone de texte contenant le titre de l'UV à éditer*/
   QLabel* titreLabel;
   QSpinBox* credits;/** crédits de l'UV à éditer*/
   QLabel* creditsLabel;
   QComboBox* categorie;/** catégorie de l'UV à éditer*/
   QLabel* categorieLabel;
   QLabel* ouvertureLabel;
   QCheckBox* automne;/** CheckBox concernant l'ouverture à l'automne*/
   QCheckBox* printemps;/** CheckBox concernant l'ouverture au printemps*/
   //QPushButton* newUV;//plus besoin car on créé une uv avec 0 crédits & on la modifie donc juste besoin de "sauver"
   QPushButton* sauver;/** bouton permettant de sauvegarder les modifications faites à l'UV*/
   QPushButton* annuler;/** bouton permettant d'annuler les modifications faites à l'UV et de fermer la fenêtre de l'éditeur*/
   QPushButton* supprimer;/** bouton permettant de supprimer l'UV et de fermer la fenêtre de l'éditeur*/
   QVBoxLayout* couche;
   QHBoxLayout* coucheH1;
   QHBoxLayout* coucheH2;
   QHBoxLayout* coucheH3;
   QHBoxLayout* coucheH4;

   UVManager* manager;/** référence vers l'instance unique d'UVManager*/
private slots :
   /** Activation du bouton sauver uniquement si des modifications ont été faites sur la page*/
   void activerSauver (QString str="");

public :
   /**
    * \brief constructeur avec paramètres
    * \param m : adresse de l'instance unique d'UVManager
    * \param u : référence vers l'UV à éditer
    * \param parent : QWidget parent
    */
   UVEditeur(UVManager* m, UV& u, QWidget* parent=0);
public slots :
   /**
    * \brief Enregistrer les modifications faites à l'UV
    */
   void sauverUV();
   /**
    * \brief Ajouter l'UV si elle n'existe pas déjà*/
   void addUv();
   /**
    * \brief Supprimer l'UV si elle existe
    */
   void supprimerUV();

};


/**
 * \class UVFinder
 * \brief Classe permettant de rechercher une UV, hérite de QWidget
 */
class UVFinder : public QWidget{
    Q_OBJECT
    UVManager* manager;/** adresse de l'instance unique d'UVManager*/
    QLineEdit* code;/** zone de texte contenant l'UV à rechercher*/
    QLabel* codeLabel;
    QPushButton* ajouter;/** bouton permettant d'ajouter l'UV dont le code est entré dans la zone de texte si elle n'existe pas*/
    QPushButton* rechercher;/** boutton permettant de rechercher l'UV dont le code est entré dans la zone de texte si elle existe*/
    QPushButton* annuler;/** bouton permettant de fermer l'éditeur*/
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
public :
    /**
    * \brief Constructeur
    * \param m : adresse de l'instance unique d'UVManager
    * \param parent : QWidget parent
    */
   UVFinder(UVManager* m, QWidget* parent=0);
public slots :
   /**
    * \brief Rechercher l'UV dont le code est entré dans la zone de texte
    */
   void rechercherUV();
   /**
    * \brief Ajouter l'UV dont le code est entré dans la zone de texte si elle n'existe pas
    */
   void ajouterUV();
};


#endif // UVEDITEUR_H
