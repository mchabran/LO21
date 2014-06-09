#include "dossier.h"
#include "Equivalence.h"
#include "CursusEditeur.h"
#include <QDesktopWidget>

Dossier* Dossier::instanceUnique=0;

void Dossier::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

Dossier& Dossier::donneInstance(CursusManager &c){
    if (instanceUnique==0) instanceUnique= new Dossier;

    return *instanceUnique;
}

Dossier::~Dossier() {
    delete[] inscriptions;
    delete[] equivalences;
}

DossierEditeur::DossierEditeur(UVManager& m, QWidget* parent) : manager(m), QWidget(parent), doss(Dossier::donneInstance(CursusManager::getInstance())){
    this->setWindowTitle(QString("Consultation du dossier"));
    cursusLabel = new QLabel("Cursus", this);
    equivalencesLabel = new QLabel("Equivalences", this);
    UVLabel = new QLabel("Inscriptions", this);
    recapLabel = new QLabel("Total crédits", this);
    //resultatLabel = new QLabel("Résultat", this);

    nomNouvCur = new QLineEdit("Cursus à modifier", this);
    activiteES = new QCheckBox("Activité extra-scolaire", this);
    activiteES->setChecked(doss.getActiviteES());
    B2 = new QCheckBox("Niveau B2 validé", this);
    B2->setChecked(doss.getnivB2());
    modifInscr = new QPushButton("Modifier", this);
    nomInscrAModif = new QLineEdit("Inscription à modifier", this);
    modifEqui = new QPushButton("Modifier", this);
    nomEquiAModif = new QLineEdit("Nom Etablissement", this);
    ajouterCursus = new QPushButton("Modifier", this);
    sauver = new QPushButton("Sauver", this);
    annuler = new QPushButton("Annuler", this);

    couche= new QVBoxLayout;

    Cursus** cur = doss.getCursusManager().getMesCursus();
    cursus = new QComboBox(this);
    unsigned int i=0;
    while(i<doss.getCursusManager().getNbCursus()){
        cursus->addItem(cur[i]->getNom());
        i++;
    }

    unsigned int totCredCS=0, totCredTM = 0, totCredTSH=0, totCredSP=0;

    coucheH6 = new QHBoxLayout;

    Equivalence** equi = doss.getEquivalences();
    equivalences = new QTableWidget(this);
    equivalences->setColumnCount(6);
    equivalences->setRowCount(1);
    equivalences->setGeometry(QApplication::desktop()->screenGeometry());
    equivalences->setItem(0, 0, new QTableWidgetItem("Etablissement"));
    equivalences->setItem(0, 1, new QTableWidgetItem("Pays"));
    equivalences->setItem(0, 2, new QTableWidgetItem("CS"));
    equivalences->setItem(0, 3, new QTableWidgetItem("TM"));
    equivalences->setItem(0, 4, new QTableWidgetItem("TSH"));
    equivalences->setItem(0, 5, new QTableWidgetItem("SP"));
    i=0;
    while(i<doss.getNbEq()){
        QTableWidgetItem* nomEt = new QTableWidgetItem((QTableWidgetItem)equi[i]->getNomEtablissement());
        QTableWidgetItem* nomPays = new QTableWidgetItem((QTableWidgetItem)equi[i]->getPays());
        QTableWidgetItem* crCS = new QTableWidgetItem(QString::number(equi[i]->getEquiCS()));
        QTableWidgetItem* crTM = new QTableWidgetItem(QString::number(equi[i]->getEquiTM()));
        QTableWidgetItem* crTSH = new QTableWidgetItem(QString::number(equi[i]->getEquiTSH()));
        QTableWidgetItem* crSP = new QTableWidgetItem(QString::number(equi[i]->getEquiSP()));
        equivalences->insertRow(i+1);
        equivalences->setItem(i+1, 0, nomEt);
        equivalences->setItem(i+1, 1, nomPays);
        equivalences->setItem(i+1, 2, crCS);
        equivalences->setItem(i+1, 3, crTM);
        equivalences->setItem(i+1, 4, crTSH);
        equivalences->setItem(i+1, 5, crSP);

        totCredCS+=equi[i]->getEquiCS();
        totCredTM+=equi[i]->getEquiTM();
        totCredTSH+=equi[i]->getEquiTSH();
        totCredSP+=equi[i]->getEquiSP();
        i++;


    }

    coucheH6->addWidget(equivalencesLabel);
    coucheH6->addWidget(equivalences);
    coucheH6->addWidget(nomEquiAModif);
    coucheH6->addWidget(modifEqui);


    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(cursusLabel);
    coucheH1->addWidget(cursus);
    coucheH1->addWidget(nomNouvCur);
    coucheH1->addWidget(ajouterCursus);


    Inscription** ins=doss.getInscriptions();
    tabUV = new QTableWidget(this);
    tabUV->setColumnCount(3);
    tabUV->setRowCount(1);
    tabUV->setItem(0, 0, new QTableWidgetItem("UVs suivies"));
    tabUV->setItem(0, 1, new QTableWidgetItem("Résultat"));
    tabUV->setItem(0, 2, new QTableWidgetItem("Semestre"));
    i=0;

    while(i<doss.getNbIns()){
        QTableWidgetItem* nomUV = new QTableWidgetItem((QTableWidgetItem)ins[i]->getUV().getCode());
        QTableWidgetItem* resUV = new QTableWidgetItem((QTableWidgetItem)NoteToString(ins[i]->getResultat()));
        QString semestre = semestreToString(ins[i]->getSemestre());
        QTableWidgetItem* sem = new QTableWidgetItem((QTableWidgetItem)semestre);
        tabUV->insertRow(i+1);
        tabUV->setItem(i+1, 0, nomUV);
        tabUV->setItem(i+1, 1, resUV);
        tabUV->setItem(i+1, 2, sem);

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
    coucheH2->addWidget(UVLabel);
    coucheH2->addWidget(tabUV);
    coucheH2->addWidget(nomInscrAModif);
    coucheH2->addWidget(modifInscr);




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
    coucheH3->addWidget(recapLabel);
    coucheH3->addWidget(recapCred);



    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(activiteES);
    coucheH4->addWidget(B2);
    coucheH5 = new QHBoxLayout;
    coucheH5->addWidget(sauver);
    coucheH5->addWidget(annuler);
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH6);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    setLayout(couche);

    QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(sauverDossier()));
    QObject::connect(annuler,SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ajouterCursus,SIGNAL(clicked()), this, SLOT(modifCursus()));
    QObject::connect(modifInscr,SIGNAL(clicked()), this, SLOT(modifierInscription()));
    QObject::connect(modifEqui,SIGNAL(clicked()), this, SLOT(modifierEquivalence()));
}


void DossierEditeur::sauverDossier(){
    doss.setAES(activiteES->isChecked());
    doss.setNivB2(B2->isChecked());
    QMessageBox::information(this, "Sauvegarde Dossier", "Dossier sauvegardé");
    close();
}


void DossierEditeur::modifCursus(){
    Cursus* newCur = new Cursus(nomNouvCur->text(), C_Branche, 0, 0, 0, 0);
    CursusEditeur* newFen = new CursusEditeur(&doss.getCursusManager(), newCur);
    newFen->show();
}

void DossierEditeur::modifierInscription(){
    unsigned int i=0;
    while(doss.getInscriptions()[i]->getUV().getCode()!=nomInscrAModif->text()) i++;
    InscriptionEditeur* fen2 = new InscriptionEditeur(doss.getInscriptions()[i]);
    fen2->show();
}

void DossierEditeur::modifierEquivalence(){
    unsigned int i=0;
    while(doss.getEquivalences()[i]->getNomEtablissement()!=nomEquiAModif->text()) i++;
    EquivalenceEditeur* fen2 = new EquivalenceEditeur(doss.getEquivalences()[i]);
    fen2->show();
}


