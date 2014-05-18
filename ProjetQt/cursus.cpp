#include "cursus.h"
#include "TC.h"
#include "HuTech.h"


CursusEditeur::CursusEditeur(Cursus& c, QWidget* parent) : cursus(c){
    this->setWindowTitle(QString("Edition de cursus"));

    nomCursusLabel = new QLabel("nom", this);
    nomCursus = new QLineEdit(c.getNom(), this);
    categorieLabel = new QLabel("Catégorie", this);

    categorie=new QComboBox(this);
    categorie->addItem("TC");
    categorie->addItem("Branche");
    categorie->addItem("Filière");
    categorie->addItem("HuTech");
    categorie->addItem("Mineur");
    categorie->setCurrentIndex(int(c.getCategorie()));
    rechercher = new QPushButton("Rechercher");
    annuler = new QPushButton("Annuler");

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

    QObject::connect(rechercher, SIGNAL(clicked()), this, SLOT(rechercherCursus()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}





void CursusEditeur::rechercherCursus(){ // Fenêtre ne reste pas affichée
   //if (str == "Tronc commun") {
        TC& tc = TC::donneInstance();
        TCEditeur fenetre(tc);
        fenetre.show();
    //}
    /*else if (c=="HuTech") {
        HuTechEditeur ht = new HuTech::donneInstance();
        ht.show();
    }*/
}


