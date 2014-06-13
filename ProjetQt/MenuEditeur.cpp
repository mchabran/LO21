#include "MenuEditeur.h"
#include "dossier.h"
#include "CursusEditeur.h"
#include "CursusFinder.h"
#include "UVEditeur.h"
#include "Inscription.h"


MenuEditeur::MenuEditeur(UVManager& m, QWidget* parent) : um(m){
    ajoutDoss = new QPushButton("Ajouter Dossier", this);
    consultDoss = new QPushButton("Consulter/Modifier Dossier", this);
    consultUV = new QPushButton("Consulter/Modifier une UV", this);
    consultCursus = new QPushButton("Edition de cursus", this);
    fermeture= new QPushButton("Terminer", this);


    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(ajoutDoss);
    coucheH1->addWidget(consultDoss);
    coucheH2 = new QHBoxLayout;
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(consultUV);
    coucheH3->addWidget(consultCursus);
    coucheH4 = new QHBoxLayout;
    coucheH5=new QHBoxLayout;
    coucheH5->addWidget(fermeture);

    couche = new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    setLayout(couche);

    QObject::connect(ajoutDoss, SIGNAL(clicked()), this, SLOT(ajouterDossier()));
    QObject::connect(consultDoss, SIGNAL(clicked()), this, SLOT(ajouterDossier()));
    QObject::connect(consultCursus, SIGNAL(clicked()), this, SLOT(consulterCursus()));
    QObject::connect(consultUV, SIGNAL(clicked()), this, SLOT(consulterUV()));
    QObject::connect(fermeture, SIGNAL(clicked()), this, SLOT(fin()));
}

void MenuEditeur::ajouterDossier(){
    DossierEditeur* fen = new DossierEditeur(um);
    fen->show();
}


void MenuEditeur::consulterCursus(){
    CursusManager& cm2=CursusManager::getInstance();
    /*if (cm2.file==0){
        QMessageBox::information(this, "Chargement fichier", "Charger le fichier cursus.xml");
        QString chemin3 = QFileDialog::getOpenFileName();
        cm2.load(chemin3);
    }*/
    CursusFinder* fenetre=new CursusFinder(&cm2);
    fenetre->show();
}


void MenuEditeur::consulterUV(){
    UVFinder* fen = new UVFinder(&um);
    fen->show();
}

void MenuEditeur::fin(){
    Dossier& d=Dossier::donneInstance();
    UVManager& u=UVManager::getInstance();
    CursusManager& c=CursusManager::getInstance();
    d.saveInscription();
    d.saveEquivalence();
    d.saveDossier();
    u.save();
    c.save();
    this->close();
}
