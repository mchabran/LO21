#ifndef CURSUS_H
#define CURSUS_H

/**
  * \file cursus.h
  * \brief Gestion des différents cursus
*/
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
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
#include <sstream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include "UTProfiler.h"

using namespace std;

/**
  *\enum CategorieCursus
 * \brief Contient les différentes catégories de cursus
 */
enum CategorieCursus {
 C_TC,C_Branche,C_Filiere,C_HuTech, C_Mineur, autre
};

/**
 * \class Cursus
 * \brief Contient les informations liées aux cursus
 */
class Cursus{

    QString* tabUV; /** tableau contenant le nom des uvs du cursus*/ //on stock uniquement les noms des UVs
    unsigned int nbUV; /** nombre d'uvs dans le cursus */
    unsigned int nbMaxUV; /** nb maximum d'UVs dans le cursus*/
    const Cursus *parent; /** cursus parent dans le cas des filières pour connaître la branche à laquelle elels se rattachent, 0 sinon*/
    QString nom; /** nom du cursus */
    CategorieCursus categorie; /** Catégorie du cursus*/
    unsigned int credCS; /** nb de crédits CS nécessaires à la validation du cursus */
    unsigned int credTM; /** nb de crédits TM nécessaires à la validation du cursus */
    unsigned int credTSH; /** nb de crédits TSH nécessaires à la validation du cursus */
    unsigned int credSP;/** nb de crédits SP nécessaires à la validation du cursus */

    friend class CursusManager;
public :
    /**
     * \brief Récupration du nom
     * \return le nom du cursus
     */
    QString getNom() const {return nom;}
    /**
     * \brief Récupération de la catégorie
     * \return la catégorie du cursus
     */
    CategorieCursus getCategorie() const {return categorie;}
    /**
     * \brief Récupération du tableau d'UVs
     * \return le tableau d'uvs
     */
    const QString* getTabUV()const{return tabUV;}
    /**
     * \brief Récupération de la catégorie parente
     * \return la catégorie parente
     */
    const Cursus* getParent()const{return parent;}
    /**
     * \brief Récupération du nombre d'UVs
     * \return le nombre d'UVs
     */
    unsigned int getNbUV()const{return nbUV;}
    /**
     * \brief Récupération du nombre de crédits CS
     * \return
     */
    unsigned int getCredCS()const {return credCS;}
    /**
     * \brief Récupération du nombre de crédits TM
     * \return
     */
    unsigned int getCredTM()const {return credTM;}
    /**
     * \brief Récupération du nombre de crédits TSH
     * \return
     */
    unsigned int getCredTSH() const {return credTSH;}
    /**
     * \brief Récupération du nombre de crédits SP
     * \return
     */
    unsigned int getCredSP() const {return credSP;}
    /**
     * \brief Mise à jour du nombre de crédits CS
     * \param n : nouveau nombre de crédits CS
     */
    void setCredCS(unsigned int n){credCS=n;}
    /**
     * \brief Mise à jour du nombre de crédits TM
     * \param n : nouveau nombre de crédits TM
     */
    void setCredTM(unsigned int n){credTM=n;}
    /**
     * \brief Mise à jour du nombre de crédits TSH
     * \param n : nouveau nombre de crédits TSH
     */
    void setCredTSH(unsigned int n){credTSH=n;}
    /**
     * \brief Mise à jour du nombre de crédits SP
     * \param n : nouveau nombre de crédits SP
     */
    void setCredSP(unsigned int n){credSP=n;}
    /**
     * \brief Mise à jour de la catégorie
     * \param c : nouvelle catégorie
     */
    void setCategorie(CategorieCursus c){categorie=c;}
    /**
     * \brief Mise à jour de la catégorie parents
     * \param p : nouvelle catégorie parente
     */
    void setParent(const Cursus* p){parent=p;}
    /**
     * \brief Ajout d'UV à la catégorie
     * \param u : code de la nouvelle UV à ajouter
     */
    void addUV(QString u); //ca marche
   //a mettre en privée
    /**
     * \brief Constructeur
     * \param n : nom
     * \param cat : catégorie
     * \param nbCS : nb de crédits CS
     * \param nbTM : nb de crédits TM
     * \param nbTSH : nb de crédits TSH
     * \param nbSP : nb de crédits SP
     * \param p : parent du cursus
     */
    Cursus(QString n, CategorieCursus cat, unsigned int nbCS, unsigned int nbTM, unsigned int nbTSH, unsigned int nbSP, const Cursus* p=0 ) : nom(n), categorie(cat), credCS(nbCS), credTM(nbTM), credTSH(nbTSH), credSP(nbSP),nbUV(0), nbMaxUV(4), tabUV(new QString[4]), parent(p){}
};





#endif // CURSUS_H
