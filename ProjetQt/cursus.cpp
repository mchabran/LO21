#include "cursus.h"

TC* TC::instanceUnique=0;

void TC::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

TC& TC::donneInstance(){
    if (instanceUnique==0) instanceUnique=new TC;
    return *instanceUnique;
}


HuTech* HuTech::instanceUnique=0;

void HuTech::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

HuTech& HuTech::donneInstance(){
    if (instanceUnique==0) instanceUnique=new HuTech;
    return *instanceUnique;
}


// CursusEditeur

CursusEditeur::CursusEditeur(Cursus& c, QWidget* parent) : cursus(c){
    this->setWindowTitle(QString("Edition du cursus") +c.getNom());

    nomCursusLabel = new QLabel("nom", this);
    nomCursus = new QLineEdit(c.getNom(), this);
    categorieLabel = new QLabel("Catégorie", this);
    categorie=new QComboBox(this);
    categorie->addItem("TC");
    categorie->addItem("Branche");
    categorie->addItem("Filière");
    categorie->addItem("HuTech");
    categorie->addItem("Mineur");
    rechercher = new QPushButton("Rechercher");

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomCursusLabel);
    coucheH1->addWidget(nomCursus);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(categorieLabel);
    coucheH2->addWidget(categorie);
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(rechercher);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    setLayout(couche);

    //QObject::connect(rechercher, SIGNAL(clicked()), this, SLOT(rechercherCursus()));
}

/*
QSpinBox* categorie;
QLabel* categorieLabel;
QPushButton* rechercher;
QPushButton* annuler;*/

/*CSLabel = new QLabel("CS", this);
TMLabel = new QLabel("TM", this);
//TSHLabel = new QLabel("TSH", this);
SPLabel = new QLabel("SP", this);
categorieLabel = new QLabel("Catégorie", this);*/
