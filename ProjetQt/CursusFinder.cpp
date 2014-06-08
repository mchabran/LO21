#include "CursusFinder.h"
#include "CursusEditeur.h"

CursusFinder::CursusFinder(CursusManager* M, QWidget* parent) : cM(M), QWidget(parent) {
    this->setWindowTitle(QString("Edition de cursus"));

    nomCursusLabel = new QLabel("Cursus :", this);
    nomCursus =new QComboBox(this);
    for (unsigned int i=0;i<M->getNbCursus();i++){
        nomCursus->addItem(M->getMesCursus()[i]->getNom());
    }

    //rechercher = new QPushButton("Rechercher");
    annuler = new QPushButton("Annuler");
    editerC = new QPushButton("Editer");
    supprimerC = new QPushButton("Supprimer");
    ajouterC=new QPushButton("Ajouter");

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomCursusLabel);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(nomCursus);

    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(supprimerC);
    coucheH3->addWidget(editerC);
    coucheH3->addWidget(ajouterC);
    //coucheH3->addWidget(rechercher);
    coucheH3->addWidget(annuler);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    setLayout(couche);

    QObject::connect(supprimerC, SIGNAL(clicked()),this, SLOT(supprimer()));
    QObject::connect(editerC, SIGNAL(clicked()),this, SLOT(editer()));
    QObject::connect(ajouterC, SIGNAL(clicked()), SLOT(ajouter()));
    //QObject::connect(rechercher, SIGNAL(clicked()), this , SLOT(rechercherCursus()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}

void CursusFinder::supprimer(){
    cM->supprimerCursus( cM->getCursus(nomCursus->currentText()));
    QMessageBox::information(this, "Supression", "Cursus supprimée");
}
void CursusFinder::editer(){}

void CursusFinder::ajouter(){
    CursusEditeur fenetre2(cM);
    fenetre2.show();
}

/*
void CursusFinder::rechercherCursus(){ // Il faudrait une fonction qui récupère les infos dans un fichier cursus.xml LOL
   if (nomCursus->text() == "Tronc commun") {
        TC& tc = TC::donneInstance();
        TCEditeur* fenetre2 = new TCEditeur(tc);
        fenetre2->show();
    }
    else if (nomCursus->text()=="HuTech") {
        HuTech& h = HuTech::donneInstance();
        HTEditeur* ht = new HTEditeur(h);
        ht->show();
    }
    //On ouvre un éditeur de cursus qui contient les infos du cursus qu'on cherche qui seront stockées dans un fichier
    QString chemin = QFileDialog::getOpenFileName();
    const QString recherche = nomCursus->text();
    QMessageBox::information(this, "Coucou", "Cursus en cours de recherche"); //ok
    Cursus& newCur = cursus.find(chemin, recherche);
    QMessageBox::information(this, "Coucou", "Cursus trouvé");//pas ok

    CursusEditeur* fenetre2 = new CursusEditeur(newCur);
    fenetre2->show();
}*/
