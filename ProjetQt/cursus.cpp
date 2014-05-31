#include "cursus.h"
#include "TC.h"
#include "HuTech.h"


QString CategorieCursusToString(CategorieCursus c){
    switch(c){
    case C_TC: return "C_TC";
    case C_Filiere: return "C_Filiere";
        case C_Branche: return "C_Branche";
    case C_HuTech: return "C_HuTech";
    case C_Mineur: return "C_Mineur";
    case autre:return "autre";
    default: throw UTProfilerException("erreur, categorie non traitee",__FILE__,__LINE__);
    }
}

CategorieCursus StringToCategorieCursus(const QString& str){
    if (str=="C_TC") return C_TC;
    else
    if (str=="C_Branche") return C_Branche;
    else
    if (str=="C_Filiere") return C_Filiere;
    else
    if (str=="C_HuTech") return C_HuTech;
    else
    if (str=="C_Mineur") return C_Mineur;
    if (str=="autre")return autre;
    else {
        throw UTProfilerException(QString("erreur, StringToCategorie, categorie ")+str+" inexistante");
    }
}

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
   /*if (nomCursus->text() == "Tronc commun") {
        TC& tc = TC::donneInstance();
        TCEditeur* fenetre2 = new TCEditeur(tc);
        fenetre2->show();
    }
    else if (nomCursus->text()=="HuTech") {
        HuTech& h = HuTech::donneInstance();
        HTEditeur* ht = new HTEditeur(h);
        ht->show();
    }*/
    //On ouvre un éditeur de cursus qui contient les infos du cursus qu'on cherche qui seront stockées dans un fichier
    QString chemin = QFileDialog::getOpenFileName();
    const QString recherche = nomCursus->text();
    QMessageBox::information(this, "Coucou", "Cursus en cours de recherche"); //ok
    Cursus& newCur = cursus.find(chemin, recherche);
    QMessageBox::information(this, "Coucou", "Cursus trouvé");//pas ok

    CursusEditeur* fenetre2 = new CursusEditeur(newCur);
    fenetre2->show();
}

CursusEditeur::CursusEditeur(Cursus& cur, QWidget* parent) : QWidget(parent), c(cur){
    this->setWindowTitle(QString("Edition de cursus "));

    nomLabel = new QLabel("Nom cursus", this);
    CSLabel = new QLabel("CS", this);
    TMLabel = new QLabel("TM", this);
    TSHLabel = new QLabel("TSH", this);
    SPLabel = new QLabel("SP", this);
    categorieLabel = new QLabel("Catégorie", this);

    nom = new QLineEdit(c.getNom(), this);
    credCS=new QLineEdit(c.getCredCS(), this);
    credTM=new QLineEdit(c.getCredTM(), this);
    credTSH=new QLineEdit(c.getCredTSH(), this);
    credSP=new QLineEdit(c.getCredSP(), this);
    categorie=new QComboBox(this);
    categorie->addItem("TC");
    sauver = new QPushButton("Sauver", this);
    annuler = new QPushButton("Annuler", this);


    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(nomLabel);
    coucheH1->addWidget(nom);
    coucheH1->addWidget(categorieLabel);
    coucheH1->addWidget(categorie);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(CSLabel);
    coucheH2->addWidget(credCS);
    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(TMLabel);
    coucheH3->addWidget(credTM);
    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(credTSH);
    coucheH4->addWidget(TSHLabel);
    coucheH5 = new QHBoxLayout;
    coucheH5->addWidget(SPLabel);
    coucheH5->addWidget(credSP);
    coucheH6 = new QHBoxLayout;
    coucheH6->addWidget(sauver);
    coucheH6->addWidget(annuler);
    couche= new QVBoxLayout;
    couche->addItem(coucheH1);
    couche->addItem(coucheH2);
    couche->addItem(coucheH3);
    couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    couche->addItem(coucheH6);
    setLayout(couche);


    QObject::connect(sauver, SIGNAL(clicked()), this, SLOT(sauverCursus()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}

void CursusEditeur::sauverCursus(){
    c.setCredCS(credCS->text());
    c.setCredTM(credTM->text());
    c.setCredTSH(credTSH->text());
    c.setCredSP(credSP->text());
    QMessageBox::information(this, "Sauvegarde", "Cursus sauvegardé");
}

Cursus& Cursus::find(const QString& f, const QString& nomcherche){
    //if (file!=f) this->~Cursus();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw UTProfilerException("Erreur ouverture fichier UV");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named cursus, we'll go to the next.
            if(xml.name() == "ListeCursus") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "cursus") {
                QString nom;
                CategorieCursus categorie;
                QString credCS;
                QString credTM;
                QString credTSH;
                QString credSP;

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "cursus")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found nom.
                        if(xml.name() == "nom")
                            xml.readNext();
                        if(xml.text().toString() == nomcherche) { //Si le nom lu correspond au nom recherché
                            nom=xml.text().toString();

                            // We've found categorie.
                            if(xml.name() == "cat") {
                                xml.readNext(); categorie=StringToCategorieCursus(xml.text().toString());
                            }
                            // We've found credCS.
                            if(xml.name() == "CS") {
                                xml.readNext(); credCS=xml.text().toString().toUInt();
                            }
                            // We've found credTM.
                            if(xml.name() == "TM") {
                                xml.readNext(); credTM=xml.text().toString().toUInt();
                            }
                            // We've found credTSH.
                            if(xml.name() == "TSH") {
                                xml.readNext(); credTSH=xml.text().toString().toUInt();
                            }
                            // We've found credSP.
                            if(xml.name() == "SP") {
                                xml.readNext(); credSP=xml.text().toString().toUInt();
                            }
                        }
                        else xml.readNext(); xml.readNext(); xml.readNext();xml.readNext();xml.readNext();

                    }
                    // ...and next...
                    xml.readNext();
                }
                Cursus* c = new Cursus(nom, categorie, credCS, credTM, credTSH, credSP);
                return *c;

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier cursus, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}

Cursus* CursusManager::trouverCursus(const QString &c) const{
    for(unsigned int i=0; i<nbCursus;i++){
        if (mesCursus[i]->nom==c) return mesCursus[i];
    };
    return 0;

}

CursusManager::~CursusManager(){
    if (file!="") save(file);
        for(unsigned int i=0; i<nbCursus; i++) delete mesCursus[i];
        delete[] mesCursus;
}

//modif
void CursusManager::load(const QSring& f){
    if (file!=f) this->~CursusManager();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw UTProfilerException("Erreur ouverture fichier UV");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named uvs, we'll go to the next.
            if(xml.name() == "Cursus") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "cursus") {
                QString nom;
                CategorieCursus cat;
                QString* uvs;
                unsigned int nUV=0; //nb d'UV
                unsigned int nMUV=0;//nb MAX d'UV
                QString codeUV;
                unsigned int nbCS;
                unsigned int nbTM;
                unsigned int nbTSH;
                unsigned int nbSP;
                Cursus p;

                xml.readNext();
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "cursus")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "nom") {
                            xml.readNext(); nom=xml.text().toString();
                        }
                        if(xml.name()=="categorie"){
                            xml.readNext(); cat=StringToCategorieCursus(xml.text().toString());
                        }
                        if(xml.name() == "CS") {
                            xml.readNext(); nbCS=xml.text().toString().toUInt();
                        }
                        if(xml.name() == "TM") {
                            xml.readNext(); nbTM=xml.text().toString().toUInt();
                        }
                        if(xml.name() == "TSH") {
                            xml.readNext(); nbTSH=xml.text().toString().toUInt();
                        }
                        if(xml.name() == "SP") {
                            xml.readNext(); nbSP=xml.text().toString().toUInt();
                        }
                        if(xml.name()=="UVs"){
                                xml.readNext();
                                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "UVs")) {
                                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                                         QXmlStreamAttributes attributes = xml.attributes();
                                         if(attributes.hasAttribute("code")) {
                                             codeUV =attributes.value("code").toString();
                                         }
                                    }
                                    if (nUV==nMUV){
                                            QString* newtab=new QString[nMUV+10];
                                            for(unsigned int i=0; i<nUV; i++) newtab[i]=uvs[i];
                                            nMUV+=10;
                                            QString* old=uvs;
                                            uvs=newtab;
                                            delete[] old;
                                    }
                                    uvs[nbUV++]=codeUV;
                                }
                        }


                    }
                }
                xml.readNext();
            }//fin cursus
            ajouterCursus(nom, uvs, nUV, cat, nbCS, nbTM, nbTSH, nbSP,p);

        }
    }
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}

void CursusManager::ajouterCursus(const QString n, const QString* t, unsigned int nbU, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP, Cursus p){
    if (trouverCursus(n)) {
    throw UTProfilerException(QString("erreur, CursusManager, Cursus")+n+QString("déja existant"));
    }
    else{
    Cursus* newcursus=new Cursus(n,c,CS,TM,TSH,SP,p);
    for(unsigned int i=0;i<nbU;i++)
        newcursus->addUV(t[i]);
    addItem(newcursus);
    }
}

void Cursus::addUV(UV u){
    if (nbUV==nbMaxUV){
            QString* newtab=new QString[nbMaxUV+10];
            for(unsigned int i=0; i<nbUV; i++) newtab[i]=tabUV[i];
            nbMaxUV+=10;
            QString* old=tabUV;
            tabUV=newtab;
            delete[] old;
    }
    tabUV[nbUV++]=u;
}
