
#include "UVEditeur.h"

UVEditeur::UVEditeur(UVManager *m, UV& uvToEdit, QWidget* parent): QWidget(parent), uv(uvToEdit), manager(m){


   this->setWindowTitle(QString("Edition de l'UV") +uv.getCode());

   codeLabel = new QLabel("code", this);
   titreLabel = new QLabel("titre", this);
   creditsLabel = new QLabel("credits", this);
   categorieLabel = new QLabel ("categorie", this);
   ouvertureLabel = new QLabel("ouverture", this);

   code = new QLineEdit(uv.getCode(), this);
   titre = new QTextEdit(uv.getTitre(), this);
   credits=new QSpinBox(this);
   credits->setRange(1, 8);
   credits->setValue(uv.getNbCredits());

   categorie=new QComboBox(this);
   categorie->addItem("CS");
   categorie->addItem("TM");
   categorie->addItem("SP");
   categorie->addItem("TSH");
   categorie->setCurrentIndex(int(uv.getCategorie()));
   automne=new QCheckBox("automne", this);
   automne->setChecked(uv.ouvertureAutomne());
   printemps=new QCheckBox("printemps", this);
   printemps->setChecked(uv.ouverturePrintemps());
   sauver = new QPushButton("Sauver", this);
   supprimer = new QPushButton("Supprimer", this);
   annuler = new QPushButton("Annuler", this);
   newUV = new QPushButton("Ajouter UV", this);

   coucheH1 = new QHBoxLayout;
   coucheH1->addWidget(codeLabel);
   coucheH1->addWidget(code);
   coucheH1->addWidget(categorieLabel);
   coucheH1->addWidget(categorie);
   coucheH1->addWidget(creditsLabel);
   coucheH1->addWidget(credits);
   coucheH2 = new QHBoxLayout;
   coucheH2->addWidget(titreLabel);
   coucheH2->addWidget(titre);
   coucheH3 = new QHBoxLayout;
   coucheH3->addWidget(ouvertureLabel);
   coucheH3->addWidget(automne);
   coucheH3->addWidget(printemps);
   coucheH4 = new QHBoxLayout;
   coucheH4->addWidget(annuler);
   coucheH4->addWidget(sauver);
   coucheH4->addWidget(supprimer);
   coucheH4->addWidget(newUV);
   couche= new QVBoxLayout;
   couche->addItem(coucheH1);
   couche->addItem(coucheH2);
   couche->addItem(coucheH3);
   couche->addItem(coucheH4);
   setLayout(couche);

   sauver->setEnabled(false);

   QObject::connect(newUV, SIGNAL(clicked()), this, SLOT(addUv()));
   QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(sauverUV()));
   QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(close()));
   QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(supprimerUV()));


   QObject::connect(code,SIGNAL(textEdited(QString)),this,SLOT(activerSauver(QString)));
   QObject::connect(titre,SIGNAL(textChanged()),this,SLOT(activerSauver()));
   QObject::connect(categorie,SIGNAL(currentIndexChanged(QString)),this,SLOT(activerSauver(QString)));
   QObject::connect(credits,SIGNAL(valueChanged(QString)),this,SLOT(activerSauver(QString)));
   QObject::connect(automne,SIGNAL(clicked()),this,SLOT(activerSauver()));
   QObject::connect(printemps,SIGNAL(clicked()),this,SLOT(activerSauver()));
}

void UVEditeur::activerSauver(QString){
    sauver->setEnabled(true);
}

void UVEditeur::addUv(){

    manager->ajouterUV(code->text(), titre->toPlainText(), credits->value(), (Categorie)categorie->currentIndex(), automne->isChecked(), printemps->isChecked());
    QMessageBox::information(this, "aJOUT uv", "UV ajoutée");
}

void UVEditeur::sauverUV(){
    uv.setCode(code->text());//on modifie le code avec le texte qui est dans le qlineedit qui s'appelle code
    uv.setCategorie(Categorie(categorie->currentIndex())); // parce que les catégories sont des énumérations donc renvoie un entier au lieu de CS TM TSH etc. & conversion implicite de int en categorie impossible
    uv.setNbCredits(credits->value());
    uv.setOuvertureAutomne(automne->isChecked());
    uv.setOuverturePrintemps(printemps->isChecked());
    uv.setTitre(titre->toPlainText());
    QMessageBox::information(this, "Sauvegarde", "UV sauvegardée");
}

void UVEditeur::supprimerUV(){
    manager->supprimerUV(uv);
    QMessageBox::information(this, "Supression", "UV supprimée");
}


UVFinder::UVFinder(UVManager* m, QWidget* parent) : QWidget(parent), manager(m){
    this->setWindowTitle(QString("Recherche d'e l''une UV"));

    codeLabel = new QLabel("code", this);
    code = new QLineEdit("", this);
    rechercher = new QPushButton("Rechercher", this);
    annuler = new QPushButton("Annuler", this);

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(codeLabel);
    coucheH1->addWidget(code);

    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(annuler);
    coucheH2->addWidget(rechercher);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    setLayout(couche);

    QObject::connect(rechercher,SIGNAL(clicked()), this, SLOT(rechercherUV()));
    QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(close()));

}

void UVFinder::rechercherUV(){
    UV& uv=manager->getUV(code->text());

    UVEditeur* fenetre2 = new UVEditeur(manager, uv);
    fenetre2->show();


}
