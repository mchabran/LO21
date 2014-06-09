#include "CursusEditeur.h"
#define MAXCredit 100

CursusEditeur::CursusEditeur(CursusManager* m, const Cursus* c,QWidget* parent) : cM(m), cu(c), QWidget(parent){
    this->setWindowTitle(QString("Edition de cursus "));

    nomLabel = new QLabel("Nom cursus", this);
    CSLabel = new QLabel("Crédits CS à valider", this);
    TMLabel = new QLabel("Créidts TM à valider", this);
    TSHLabel = new QLabel("Crédits TSH à valider", this);
    SPLabel = new QLabel("Crédits SP à valider" , this);
    categorieLabel = new QLabel("Catégorie de Cursus", this);
    UVsLabel = new QLabel("Liste des UVs", this);
    UVLabel = new QLabel ("Ajouter UV au cursus", this);

    nomCursus= new QLineEdit(cu->getNom(), this);
    credCS=new QSpinBox(this);
    credCS->setRange(0,MAXCredit);
    credCS->setValue(cu->getCredCS());
    credTM=new QSpinBox(this);
    credTM->setRange(0,MAXCredit);
    credTM->setValue(cu->getCredTM());
    credTSH=new QSpinBox(this);
    credTSH->setRange(0,MAXCredit);
    credTSH->setValue(cu->getCredTSH());
    credSP=new QSpinBox(this);
    credSP->setRange(0,MAXCredit);
    credSP->setValue(cu->getCredSP());

    categorie=new QComboBox(this);
    categorie->addItem("C_TC");
    categorie->addItem("C_Branche");
    categorie->addItem("C_HuTech");
    categorie->addItem("C_Mineur");
    categorie->addItem("autre");
    QString cat=CategorieCursusToString(c->getCategorie());
    categorie->setCurrentText(cat);

    UVs=new QComboBox(this);
    for(unsigned int i=0; i<cu->getNbUV();i++){
        const QString* s=cu->getTabUV();
        UVs->addItem(s[i]);
    }
    newUV=new QLineEdit("",this);

    sauver = new QPushButton("Sauver", this);
    annuler = new QPushButton("Annuler", this);
    //supprimerCursus=new QPushButton("Supprimer UV", this); //a implémenter
    ok=new QPushButton("OK", this);


    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomLabel);
    coucheH1->addWidget(nomCursus);
    coucheH1->addWidget(categorieLabel);
    coucheH1->addWidget(categorie);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(CSLabel);
    coucheH2->addWidget(credCS);
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(TMLabel);
    coucheH3->addWidget(credTM);
    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(TSHLabel);
    coucheH4->addWidget(credTSH);
    coucheH5 = new QHBoxLayout;
    coucheH5->addWidget(SPLabel);
    coucheH5->addWidget(credSP);

    coucheH7=new QHBoxLayout;
    coucheH7->addWidget(UVsLabel);
    coucheH7->addWidget(UVs);
    //coucheH7->addWidget(supprimerUV);

    coucheH8=new QHBoxLayout;
    coucheH8->addWidget(UVLabel);
    coucheH8->addWidget(newUV);
    coucheH8->addWidget(ok);

    coucheH6 = new QHBoxLayout;
    coucheH6->addWidget(sauver);
    coucheH6->addWidget(annuler);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    couche->addItem(coucheH7);
    couche->addItem(coucheH8);
    couche->addItem(coucheH6);
    setLayout(couche);


    //QObject::connect(sauver, SIGNAL(clicked()), this, SLOT(sauverCursus()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ok, SIGNAL(clicked()),this, SLOT(ajoutUV()));
}

void CursusEditeur::ajoutUV(){
    QString cu=nomCursus->text();
    Cursus& cursusA=cM->getCursus(cu);
    QString uv=newUV->text();
    newUV->setText("");
    cursusA.addUV(uv);
    UVs->addItem(uv);
    return;
}

//uv.setCategorie(Categorie(categorie->currentIndex()))
//void ajouterCursus(const QString n, const QString* t, unsigned int nbU, unsigned int nbMax, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP); //fait mais pas vérifié

void CursusEditeur::sauverCursus(){
    QString cu=nomCursus->text();
    CategorieCursus cat=CategorieCursus(categorie->currentIndex());
    Cursus& cursusA=cM->getCursus(cu);
    cursusA.setCategorie(cat);
    cursusA.setCredCS(credCS->value());
    cursusA.setCredTM(credTM->value());
    cursusA.setCredTSH(credTSH->value());
    cursusA.setCredSP(credSP->value());
    QMessageBox::information(this, "Sauvegarde", "Cursus sauvegardé");
    close();
}
