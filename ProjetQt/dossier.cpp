#include "dossier.h"
#include <QDesktopWidget>

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


DossierEditeur::DossierEditeur(UVManager& m, Dossier& d, QWidget* parent) : manager(m), QWidget(parent), doss(d){
    this->setWindowTitle(QString("Consultation du dossier"));
    cursusLabel = new QLabel("Cursus", this);
    /*resultatLabel = new QLabel("Résultat", this);
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
    resultat->addItem("RES");*/
    activiteES = new QCheckBox("Activité extra-scolaire", this);
    activiteES->setChecked(d.getActiviteES());
    B2 = new QCheckBox("Niveau B2 validé", this);
    B2->setChecked(d.getnivB2());
    sauver = new QPushButton("Sauver", this);
    annuler = new QPushButton("Annuler", this);



    Cursus** cur = d.getCursus();
    cursus = new QComboBox(this);
    unsigned int i=0;
    while(i<1){
        cursus->addItem(cur[i]->getNom());
        i++;
    }

    unsigned int totCredCS=0, totCredTM = 0, totCredTSH=0, totCredSP=0;

    /*
    Equivalence** equi = d.getEquivalences();
    equivalences = new QTableWidget(this);
    equivalences->setColumnCount(5);
    equivalences->setRowCount(1);
    equivalences->setGeometry(QApplication::desktop()->screenGeometry());
    equivalences->setItem(0, 0, new QTableWidgetItem("Nom établissement"));
    equivalences->setItem(0, 1, new QTableWidgetItem("CS"));
    equivalences->setItem(0, 2, new QTableWidgetItem("TM"));
    equivalences->setItem(0, 3, new QTableWidgetItem("TSH"));
    equivalences->setItem(0, 4, new QTableWidgetItem("SP"));
    i=0;
    while(i<2){
        QTableWidgetItem* nomEt = new QTableWidgetItem((QTableWidgetItem)equi[i]->getNomEtablissement());
        QTableWidgetItem* crCS = new QTableWidgetItem((QTableWidgetItem)equi[i]->getEquiCS());
        QTableWidgetItem* crTM = new QTableWidgetItem((QTableWidgetItem)equi[i]->getEquiTM());
        QTableWidgetItem* crTSH = new QTableWidgetItem((QTableWidgetItem)equi[i]->getEquiTSH());
        QTableWidgetItem* crSP = new QTableWidgetItem((QTableWidgetItem)equi[i]->getEquiSP());
        equivalences->insertRow(i+1);
        equivalences->setItem(i+1, 0, nomEt);
        equivalences->setItem(i+1, 1, crCS);
        equivalences->setItem(i+1, 1, crTM);
        equivalences->setItem(i+1, 1, crTSH);
        equivalences->setItem(i+1, 1, crSP);

        totCredCS+=equi[i]->getEquiCS();
        totCredTM+=equi[i]->getEquiTM();
        totCredTSH+=equi[i]->getEquiTSH();
        totCredSP+=equi[i]->getEquiSP();
    }
    coucheH6 = new QHBoxLayout;
    coucheH6->addWidget(equivalences);*/

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(cursusLabel);
    coucheH1->addWidget(cursus);



    Inscription** ins=d.getInscriptions();
    tabUV = new QTableWidget(this);
    tabUV->setColumnCount(2);
    tabUV->setRowCount(1);
    tabUV->setGeometry(QApplication::desktop()->screenGeometry());
    tabUV->setItem(0, 0, new QTableWidgetItem("UVs suivies"));
    tabUV->setItem(0, 1, new QTableWidgetItem("Résultat"));
    i=0;
    while(i<2){
        QTableWidgetItem* nomUV = new QTableWidgetItem((QTableWidgetItem)ins[i]->getUV().getCode());
        QTableWidgetItem* resUV = new QTableWidgetItem((QTableWidgetItem)NoteToString(ins[i]->getResultat()));
        //QString res = (QString)A;
       // QTableWidgetItem* resUV = new QTableWidgetItem((QTableWidgetItem)res);
        tabUV->insertRow(i+1);
        tabUV->setItem(i+1, 0, nomUV);
        tabUV->setItem(i+1, 1, resUV);

        if (ins[i]->getUV().getCategorie() == CS && ins[i]->uvResussie())
            totCredCS+=ins[i]->getUV().getNbCredits();
        else if (ins[i]->getUV().getCategorie() == TM && ins[i]->uvResussie())
            totCredTM+=ins[i]->getUV().getNbCredits();
        else if (ins[i]->getUV().getCategorie() == TSH && ins[i]->uvResussie())
            totCredTSH+=ins[i]->getUV().getNbCredits();
        else if (ins[i]->getUV().getCategorie() == SP && ins[i]->uvResussie())
            totCredSP+=ins[i]->getUV().getNbCredits();
        i++;
    }
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(tabUV);


    recapCred = new QTableWidget(this);
    recapCred->setColumnCount(5);
    recapCred->setRowCount(2);
    recapCred->setGeometry(QApplication::desktop()->screenGeometry());
    recapCred->setItem(0, 0, new QTableWidgetItem("CS"));
    recapCred->setItem(0, 1, new QTableWidgetItem("TM"));
    recapCred->setItem(0, 2, new QTableWidgetItem("TSH"));
    recapCred->setItem(0, 3, new QTableWidgetItem("SP"));
    recapCred->setItem(0, 4, new QTableWidgetItem("Total"));
    recapCred->setItem(1, 0, new QTableWidgetItem(QString::number(totCredCS)));
    recapCred->setItem(1, 1, new QTableWidgetItem(QString::number(totCredTM)));
    recapCred->setItem(1, 2, new QTableWidgetItem(QString::number(totCredTSH)));
    recapCred->setItem(1, 3, new QTableWidgetItem(QString::number(totCredSP)));
    unsigned int grandTotal = totCredCS + totCredSP + totCredTM + totCredTSH;
    recapCred->setItem(1, 4, new QTableWidgetItem(QString::number(grandTotal)));


    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(recapCred);


    couche= new QVBoxLayout;
    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(activiteES);
    coucheH4->addWidget(B2);
    coucheH5 = new QHBoxLayout;
    coucheH5->addWidget(sauver);
    coucheH5->addWidget(annuler);
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    //couche->addItem(coucheH6);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    setLayout(couche);

    //QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(sauverDossier()));
    QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(close()));
}


/*void DossierEditeur::sauverDossier(){
    cur = Cursus::
    doss.setCursus();
}*/
