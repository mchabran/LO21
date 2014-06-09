#include "Equivalence.h"

EquivalenceEditeur::EquivalenceEditeur(Equivalence* eq, QWidget* parent) : equivalence(eq){
    nomEtLabel = new QLabel("Etablissement", this);
    paysLabel = new QLabel("Pays", this);
    csLabel = new QLabel("CS", this);
    tmLabel = new QLabel("TM", this);
    tshLabel = new QLabel("TSH", this);
    spLabel = new QLabel("SP", this);
    nomEt = new QLineEdit(equivalence->getNomEtablissement(), this);
    pays = new QLineEdit(equivalence->getPays(), this);
    cs = new QLineEdit(QString::number(equivalence->getEquiCS()), this);
    tm = new QLineEdit(QString::number(equivalence->getEquiTM()), this);
    tsh = new QLineEdit(QString::number(equivalence->getEquiTSH()), this);
    sp = new QLineEdit(QString::number(equivalence->getEquiSP()), this);
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
    equivalence->setEquiCS(cs->text().toInt());
    equivalence->setEquiTM(tm->text().toInt());
    equivalence->setEquiTSH(tsh->text().toInt());
    equivalence->setEquiSP(sp->text().toInt());
    QMessageBox::information(this, "Equivalence Sauvegardée", "Equivalence Sauvegardée");
    close();
}
