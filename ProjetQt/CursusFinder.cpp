#include "CursusFinder.h"
#include "CursusEditeur.h"

CursusFinder::CursusFinder(CursusManager* M, QWidget* parent) : cM(M), QWidget(parent) {
    this->setWindowTitle(QString("Edition de cursus"));

    nomCursusLabel = new QLabel("Cursus :", this);
    nomCursus =new QComboBox(this);
    cu=cM->getMesCursus()[0];

    CSLabel = new QLabel("Crédits CS", this);
    TMLabel = new QLabel("Crédits TM", this);
    TSHLabel = new QLabel("Crédits TSH", this);
    SPLabel = new QLabel("Crédits SP" , this);
    categorieLabel = new QLabel("Catégorie", this);
    UVsLabel = new QLabel("UVs", this);

    credCS=new QSpinBox(this);
    credTM=new QSpinBox(this);
    credTSH=new QSpinBox(this);
    credSP=new QSpinBox(this);
    categorie=new QComboBox(this);
    UVs=new QComboBox(this);

    credCS->setReadOnly(true);
    credTM->setReadOnly(true);
    credTSH->setReadOnly(true);
    credSP->setReadOnly(true);

    this->actualisation();

    actualiserC= new QPushButton("Actualiser");
    annuler = new QPushButton("Annuler");
    editerC = new QPushButton("Editer");
    supprimerC = new QPushButton("Supprimer");
    ajouterC=new QPushButton("Ajouter");

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomCursusLabel);
    coucheH1->addWidget(nomCursus);
    coucheH1->addWidget(actualiserC);


    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(supprimerC);
    coucheH3->addWidget(editerC);
    coucheH3->addWidget(ajouterC);
    coucheH3->addWidget(annuler);

    coucheH4=new QHBoxLayout;
    coucheH4->addWidget(CSLabel);
    coucheH4->addWidget(credCS);
    coucheH5=new QHBoxLayout;
    coucheH5->addWidget(TMLabel);
    coucheH5->addWidget(credTM);
    coucheH6=new QHBoxLayout;
    coucheH6->addWidget(TSHLabel);
    coucheH6->addWidget(credTSH);
    coucheH7=new QHBoxLayout;
    coucheH7->addWidget(SPLabel);
    coucheH7->addWidget(credSP);
    coucheH8=new QHBoxLayout;
    coucheH8->addWidget(categorieLabel);
    coucheH8->addWidget(categorie);
    coucheH9=new QHBoxLayout;
    coucheH9->addWidget(UVsLabel);
    coucheH9->addWidget(UVs);


    //


    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH8);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    couche->addItem(coucheH6);
    couche->addItem(coucheH7);
    couche->addItem(coucheH9);
    couche->addItem(coucheH3);
    setLayout(couche);

    QObject::connect(supprimerC, SIGNAL(clicked()),this, SLOT(supprimer()));
    QObject::connect(editerC, SIGNAL(clicked()),this, SLOT(editer()));
    QObject::connect(ajouterC, SIGNAL(clicked()), SLOT(ajouter()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(nomCursus, SIGNAL(currentIndexChanged(QString)),this, SLOT(afficher(QString)));
    QObject::connect(actualiserC, SIGNAL(clicked()), this, SLOT(afficher()));
}

void CursusFinder::supprimer(){
    cM->supprimerCursus( cM->getCursus(nomCursus->currentText()));
    nomCursus->removeItem(nomCursus->currentIndex());
    QMessageBox::information(this, "Supression", "Cursus supprimée");
}
void CursusFinder::editer(){
    CursusEditeur* fenetre2=new CursusEditeur(cM, &(cM->getCursus(nomCursus->currentText())));
    fenetre2->show();
}

void CursusFinder::ajouter(){
    CursusEditeur* fenetre2=new CursusEditeur(cM);
    fenetre2->show();
}

void CursusFinder::afficher(QString cursusN){
    if (cursusN==0) cursusN=nomCursus->currentText();
    Cursus& cursusA=cM->getCursus(cursusN);
    credCS->setValue(cursusA.getCredCS());
    credTM->setValue(cursusA.getCredTM());
    credTSH->setValue(cursusA.getCredTSH());
    credSP->setValue(cursusA.getCredSP());
    QString cat=CategorieCursusToString(cursusA.getCategorie());
    categorie->clear();
    categorie->addItem(cat);
    categorie->setCurrentText(cat);
    UVs->clear();
    for(unsigned int i=0; i<cursusA.getNbUV();i++){
        const QString* s=cursusA.getTabUV();
        UVs->addItem(s[i]);
    }
}

void CursusFinder::actualisation(){
    nomCursus->clear();
    for (unsigned int i=0;i<cM->getNbCursus();i++){
        nomCursus->addItem(cM->getMesCursus()[i]->getNom());
    }
    afficher(nomCursus->itemText(0));
}

