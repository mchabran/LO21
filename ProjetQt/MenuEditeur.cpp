#include "MenuEditeur.h"
#include "dossier.h"
#include "CursusEditeur.h"
#include "CursusFinder.h"


MenuEditeur::MenuEditeur(UVManager& m, QWidget* parent) : um(m){
    ajoutDoss = new QPushButton("Ajouter Dossier", this);
    consultDoss = new QPushButton("Consulter/Modifier Dossier", this);
    ajoutEqui = new QPushButton("Ajouter Equivalence", this);
    ajoutInscr = new QPushButton("Ajouter Inscription", this);
    consultUV = new QPushButton("Consulter/Modifier une UV", this);
    ajoutCursus = new QPushButton("Ajouter Cursus", this);
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
    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(ajoutCursus);

    couche = new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    setLayout(couche);

    QObject::connect(ajoutDoss, SIGNAL(clicked()), this, SLOT(ajouterDossier()));
    QObject::connect(consultDoss, SIGNAL(clicked()), this, SLOT(ajouterDossier()));
    QObject::connect(ajoutCursus, SIGNAL(clicked()), this, SLOT(ajouterCursus()));
    QObject::connect(consultCursus, SIGNAL(clicked()), this, SLOT(consulterCursus()));

}

void MenuEditeur::ajouterDossier(){
    DossierEditeur* fen = new DossierEditeur(um);
    fen->show();
}

void MenuEditeur::ajouterCursus(){
    CursusManager& cm = CursusManager::getInstance();
    CursusEditeur* fen = new CursusEditeur(&cm);
    fen->show();
}

void MenuEditeur::consulterCursus(){
    CursusManager& cm = CursusManager::getInstance();
    CursusFinder* fen = new CursusFinder(&cm);
    fen->show();
}

