#ifndef INSCRIPTION_H
#define INSCRIPTION_H
/**
  *\file Inscriptions.h
  *\brief Contient la classe permettant d'implémenter les inscriptions
  */
#include "UTProfiler.h"
#include "dossier.h"
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

/**
 * \class Inscription
 */
class Inscription {
        const UV* uv;/** UV concernée par l'inscription*/
        Semestre semestre;/** semestre de l'inscription à l'UV*/
        Note resultat;/** résultat de l'inscription*/
public:
        /**
         * \brief Constructeur avec paramètres
         * \param u : UV à laquelle est inscrit l'étudiant
         * \param s : semestre de l'inscription
         * \param res : résultat pour cette inscription
         */
        const UV& getUV() const { return *uv; }
        /**
         * \brief Récupéraion du semestre
         * \return un objet de la classe semestre correspondant au semestre de l'inscription
         */
        Semestre getSemestre() const { return semestre; }
        /**
         * \brief Récupération du résultat
         * \return  un objet de type Note
         */
        Note getResultat() const { return resultat; }
        /**
         * \brief mise à jour du semestre de l'inscription
         * \param newsem : nouveau semestre pour l'inscription
         */
        void setSemestre(Semestre newsem) {semestre = newsem;}
        /**
         * \brief mise à jour du résultat
         * \param newres : nouveau résultat
         */
        void setResultat(Note newres) { resultat=newres; }
        /**
         * \brief Vérification de la résussite de l'UV
         * \return true si l'UV est réussie
         */
        bool uvResussie(){if (resultat==A || resultat==B || resultat==C || resultat==D || resultat==E) return true; return false;}
};

class Dossier;

/**
 * \class InscriptionEditeur
 * \brief Editeur d'inscription, hérite de la classe QWidget
 */
class InscriptionEditeur : public QWidget{
    Q_OBJECT
    Dossier* unDossier;/** unique instance de la classe Dossier*/
    Inscription* inscription;/** inscription à éditer*/
    QLabel* UVLabel;
    QLineEdit* uv;/** zone de texte contenant l'UV dont l'inscription est à modifier*/
    QLabel* semestreLabel;
    QLineEdit* semestre;/** zone de texte contenant le semestre à modifier*/
    QLabel* resultatLabel;
    QComboBox* resultat;/** liste déroulante des résultats possibles à une inscription*/
    QVBoxLayout* couche;
    QHBoxLayout* coucheh;
    QPushButton* sauver;/** bouton permettant de sauver les modifications*/
public :
    /**
     * \brief constructeur avec arguments
     * \param d : adresse de l'instance unique de Dossier
     * \param ins : inscription à éditer
     * \param parent : QWidget parent
     */
    InscriptionEditeur(Dossier* d, Inscription *ins=0, QWidget* parent=0);
public slots :
    /**
     * \brief Enregistrement des modifications faites graphiquements
     */
    void modifRes();
};

#endif // INSCRIPTION_H
