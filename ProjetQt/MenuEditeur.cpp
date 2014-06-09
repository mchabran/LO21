#include "MenuEditeur.h"
#include "dossier.h"


MenuEditeur::MenuEditeur(UVManager& m, QWidget* parent) : um(m){
    ajoutDoss = new QPushButton("Ajouter Dossier", this);
    consultDoss = new QPushButton("Consulter/Modifier Dossier", this);
    ajoutEqui = new QPushButton("Ajouter Equivalence", this);
    ajoutInscr = new QPushButton("Ajouter Inscription", this);
    consultUV = new QPushButton("Consulter/Modifier une UV", this);
    consultCursus = new QPushButton("Consulter/Modifier un cursus", this);

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(ajoutDoss);
    coucheH1->addWidget(consultDoss);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(ajoutEqui);
    coucheH2->addWidget(ajoutInscr);
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(consultUV);
    coucheH3->addWidget(consultCursus);

    couche = new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    setLayout(couche);

    QObject::connect(ajoutDoss, SIGNAL(clicked()), this, SLOT(ajouterDossier()));
    QObject::connect(consultDoss, SIGNAL(clicked()), this, SLOT(consulterDossier()));

}

void MenuEditeur::ajouterDossier(){
    CursusManager& cm = CursusManager::getInstance();
    DossierEditeur* fen = new DossierEditeur(um);
    fen->show();
}

void MenuEditeur::consulterDossier(){

}

