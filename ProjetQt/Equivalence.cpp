#include "Equivalence.h"

Equivalence::Equivalence(Equivalence* e){
    nomEtablissement = e->getNomEtablissement();
    pays = e->getPays();
    equiCS = e->getEquiCS();
    equiTM = e->getEquiTM();
    equiTSH = e->getEquiTSH();
    equiSP = e->getEquiSP();
}

EquivalenceEditeur::EquivalenceEditeur(Dossier* d, Equivalence* eq, QWidget* parent) : equivalence(eq){
    nomEtLabel = new QLabel("Etablissement", this);
    paysLabel = new QLabel("Pays", this);
    csLabel = new QLabel("CS", this);
    tmLabel = new QLabel("TM", this);
    tshLabel = new QLabel("TSH", this);
    spLabel = new QLabel("SP", this);
    nomEt = new QLineEdit;
    pays = new QLineEdit;
    cs = new QLineEdit;
    tm = new QLineEdit;
    tsh = new QLineEdit;
    sp = new QLineEdit;

    if(equivalence!=0){
        nomEt->setText(equivalence->getNomEtablissement());
        pays->setText(equivalence->getPays());
        cs->setText(QString::number(equivalence->getEquiCS()));
        tm->setText(QString::number(equivalence->getEquiTM()));
        tsh->setText(QString::number(equivalence->getEquiTSH()));
        sp->setText(QString::number(equivalence->getEquiSP()));
    }

    sauver = new QPushButton("Sauver", this);
    couche = new QVBoxLayout;
    coucheh = new QHBoxLayout;

    coucheh->addWidget(nomEtLabel);
    coucheh->addWidget(nomEt);
    coucheh->addWidget(paysLabel);
    coucheh->addWidget(pays);
    coucheh->addWidget(csLabel);
    coucheh->addWidget(cs);
    coucheh->addWidget(tmLabel);
    coucheh->addWidget(tm);
    coucheh->addWidget(tshLabel);
    coucheh->addWidget(tsh);
    coucheh->addWidget(spLabel);
    coucheh->addWidget(sp);
    coucheh->addWidget(sauver);

    couche->addItem(coucheh);

    setLayout(couche);

    QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(modifEqui()));
}

void EquivalenceEditeur::modifEqui(){
    if(equivalence!=0){
    equivalence->setEquiCS(cs->text().toInt());
    equivalence->setEquiTM(tm->text().toInt());
    equivalence->setEquiTSH(tsh->text().toInt());
    equivalence->setEquiSP(sp->text().toInt());
    QMessageBox::information(this, "Equivalence Sauvegardée", "Equivalence Sauvegardée");
    }

    else{
        equivalence = new Equivalence(nomEt->text(), pays->text(), cs->text().toUInt(), tm->text().toUInt(), tsh->text().toUInt(), sp->text().toUInt());
        QMessageBox::information(this, "Equivalence Sauvegardée", "Equivalence ajoutée");
        unDossier->addEquivalence(equivalence);
    }
    close();
}
