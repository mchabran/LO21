#include "dossier.h"

Dossier* Dossier::instanceUnique=0;

void Dossier::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

Dossier& Dossier::donneInstance(Cursus** c){
    if (instanceUnique==0) instanceUnique= new Dossier;
    instanceUnique->setCursus(c);
    return *instanceUnique;
}

Dossier::~Dossier() {
    delete[] cursus;
    //delete[] inscriptions;
    //delete[] equivalences;
}


DossierEditeur::DossierEditeur(Dossier& d, Cursus **c, QWidget* parent) : QWidget(parent), doss(d), cur(c){
    this->setWindowTitle(QString("Consultation du dossier"));
    nomCursusLabel = new QLabel("Nom Cursus", this);
    categorieUVLabel = new QLabel("Catégorie UV", this);
    categorieCursusLabel = new QLabel("Catégorie Cursus", this);
    nomUVLabel = new QLabel("UV", this);
    resultatLabel = new QLabel("Résultat", this);
    categorieCursus=new QComboBox(this);
    categorieCursus->addItem("TC");
    categorieCursus->addItem("HuTech");
    categorieCursus->addItem("Branche");
    categorieCursus->addItem("Filière");
    categorieCursus->addItem("Mineur");
    categorieUV=new QComboBox(this);
    categorieUV->addItem("CS");
    categorieUV->addItem("TM");
    categorieUV->addItem("SP");
    categorieUV->addItem("TSH");
    resultat = new QComboBox(this);
    resultat->addItem("A");
    resultat->addItem("B");
    resultat->addItem("C");
    resultat->addItem("D");
    resultat->addItem("E");
    resultat->addItem("F");
    resultat->addItem("FX");
    resultat->addItem("EC");
    resultat->addItem("ABS");
    resultat->addItem("RES");
    activiteES = new QCheckBox("Activité extra-scolaire", this);
    activiteES->setChecked(d.getActiviteES());
    B2 = new QCheckBox("Niveau B2 validé", this);
    B2->setChecked(d.getnivB2());
    sauver = new QPushButton("Sauver", this);
    annuler = new QPushButton("Annuler", this);

    couche= new QVBoxLayout;

    Cursus** cur = d.getCursus();
    unsigned int i=0;
    while(cur[i]!=0){
        nomCursus = new QLineEdit(cur[i]->getNom(), this);
        categorieCursus->setCurrentIndex(1); // A REMODIFIER
        QHBoxLayout* coucheH = new QHBoxLayout;
        coucheH->addWidget(nomCursusLabel);
        coucheH->addWidget(nomCursus);
        coucheH->addWidget(categorieCursusLabel);
        coucheH->addWidget(categorieCursus);
        couche->addItem(coucheH);
        i++;
    }

    Inscription** ins=d.getInscriptions();
    i=0;
    while(ins[i]!=0){
        nomUV = new QLineEdit("LO21", this); // A REMODIFIER, LO21 c'est pas vrai tout le temps !!
        resultat->setCurrentIndex((int)ins[i]->getResultat());
        QHBoxLayout* coucheHbis = new QHBoxLayout;
        coucheHbis->addWidget(nomUVLabel);
        coucheHbis->addWidget(nomUV);
        coucheHbis->addWidget(resultatLabel);
        coucheHbis->addWidget(resultat);
        couche->addItem(coucheHbis);
        i++;
    }

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(activiteES);
    coucheH1->addWidget(B2);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(sauver);
    coucheH2->addWidget(annuler);
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    setLayout(couche);

    //QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(sauverDossier()));
    QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(close()));
}


/*void DossierEditeur::sauverDossier(){
    cur = Cursus::
    doss.setCursus();
}*/
