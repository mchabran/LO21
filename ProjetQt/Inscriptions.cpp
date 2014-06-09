#include "Inscription.h"

QLabel* UVLabel;
QLineEdit* uv;
QLabel* semestreLabel;
QLineEdit* semestre;
QLabel* noteLabel;
QComboBox* note;

InscriptionEditeur::InscriptionEditeur(Inscription* ins, QWidget* parent) : inscription(ins){
    UVLabel = new QLabel("UV", this);
    uv = new QLineEdit;
    semestreLabel = new QLabel("Semestre", this);
    semestre = new QLineEdit;
    resultatLabel = new QLabel("Note", this);
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
    sauver = new QPushButton("Sauver", this);
    int i=0;
    couche = new QVBoxLayout;

    while(i<2){
        if(inscription!=0){
        uv->setText(inscription->getUV().getCode());
        semestre->setText(semestreToString(inscription->getSemestre()));
        resultat->setCurrentIndex(inscription->getResultat());}

        coucheh = new QHBoxLayout;
        coucheh->addWidget(UVLabel);
        coucheh->addWidget(uv);
        coucheh->addWidget(semestreLabel);
        coucheh->addWidget(semestre);
        coucheh->addWidget(resultatLabel);
        coucheh->addWidget(resultat);
        coucheh->addWidget(sauver);

        couche->addItem(coucheh);
        i++;
    }

    setLayout(couche);

    QObject::connect(sauver,SIGNAL(clicked()), this, SLOT(modifRes()));

}

void InscriptionEditeur::modifRes(){ //La modification ne se voit pas dans le tableau quand la fenêtre de modif se ferme
    if(inscription!=0){
    QString res = resultat->currentText();
    Note newnote = StringToNote(res);
    inscription->setResultat(newnote);
    QMessageBox::information(this, "Note Sauvegardée", "Note Sauvegardée");}

    else{
        const QString s = uv->text();
        UVManager& man = UVManager::getInstance();
        UV& nuv = man.getUV(s);
        Semestre sem = StringToSemestre(semestre->text());
        Note res = StringToNote(resultat->currentText());
        inscription = new Inscription(nuv, sem, res);
    }
    close();
}
