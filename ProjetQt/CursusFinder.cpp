/*#include "cursus.h"
#include "CursusManager.h"
CursusFinder

CursusFinder::CursusFinder(Cursus& c, QWidget* parent) : cursus(c){
    this->setWindowTitle(QString("Edition de cursus"));

    nomCursusLabel = new QLabel("nom", this);
    nomCursus = new QLineEdit(c.getNom(), this);
    categorieLabel = new QLabel("Catégorie", this);

    categorie=new QComboBox(this);
    categorie->addItem("TC");
    categorie->addItem("Branche");
    categorie->addItem("Filière");
    categorie->addItem("HuTech");
    categorie->addItem("Mineur");
    categorie->setCurrentIndex(int(c.getCategorie()));
    rechercher = new QPushButton("Rechercher");
    annuler = new QPushButton("Annuler");

    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomCursusLabel);
    coucheH1->addWidget(nomCursus);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(categorieLabel);
    coucheH2->addWidget(categorie);
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(rechercher);
    coucheH3->addWidget(annuler);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    setLayout(couche);

    QObject::connect( rechercher, SIGNAL(clicked()), this , SLOT(rechercherCursus()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}

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
}

*/
