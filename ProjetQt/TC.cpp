#include "cursus.h"
#include "TC.h"

/*TC::TC(): Cursus("Tronc Commun", C_TC, "48", "24", "0", "6"){}

TC* TC::instanceUnique=0;

void TC::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

TC& TC::donneInstance(){
    if (instanceUnique==0) instanceUnique=new TC;
    return *instanceUnique;
}



TCEditeur::TCEditeur(TC& t, QWidget* parent) : QWidget(parent), tc(t){
    this->setWindowTitle(QString("Edition de cursus "));

    nomLabel = new QLabel("Nom cursus", this);
    CSLabel = new QLabel("CS", this);
    TMLabel = new QLabel("TM", this);
    //TSHLabel = new QLabel("TSH", this);
    SPLabel = new QLabel("SP", this);
    categorieLabel = new QLabel("Catégorie", this);

    nom = new QLineEdit(t.getNom(), this);
    credCS=new QLineEdit(t.getCredCS(), this);
    credTM=new QLineEdit(t.getCredTM(), this);
    //credTSH=new QLineEdit(tc.getCredTSH(), this);
    credSP=new QLineEdit(t.getCredSP(), this);
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
    //coucheH4 = new QHBoxLayout;
    //coucheH4->addWidget(credTSH);
    //coucheH4->addWidget(TSHLabel);
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
    //couche->addItem(coucheH4);
    couche->addItem(coucheH5);
    couche->addItem(coucheH6);
    setLayout(couche);


    QObject::connect(sauver, SIGNAL(clicked()), this, SLOT(sauverTC()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}


void TCEditeur::ajouterTC(QString nbCS, QString nbTM, /*QString nbTSH,* QString nbSP){
    TC& tc = TC::donneInstance();
    tc.setCredCS(nbCS);
    tc.setCredTM(nbTM);
    //tc.setCredTSH(nbTSH);
    tc.setCredSP(nbSP);
}


void TCEditeur::sauverTC(){
    tc.setCredCS(credCS->text());
    tc.setCredTM(credTM->text());
    //tc->setCredTSH(credTSH->text());
    tc.setCredSP(credSP->text());
    QMessageBox::information(this, "Sauvegarde", "TC sauvegardé");
}



void TC::save(const QString& f){
    QFile newfile(file);
    file=f;
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw ("erreur ouverture fichier xml");
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("TC");
     stream.writeAttribute("CS", (getCredCS()));
     stream.writeAttribute("TM", (getCredTM()));
     //stream.writeTextElement("TSH",(getCredTSH));
     stream.writeTextElement("SP",getCredSP());
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}

*/

/********* ca ne marche pas **************/
/*
void TC::load(const QString& f){
    if (file!=f) this->~TC();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw ("Erreur ouverture fichier UV");
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
            //********if(xml.name() == "uvs") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "TC") {
                QString credCS;
                QString credTM;
                //QString credTSH; //comment on fait pour les TSH sachant qu'il faut 52 crédits branche + TC confondus ? (:
                QString credSP;

                //*********QXmlStreamAttributes attributes = xml.attributes();
                /* Let's check that uvs has attribute. */
                //if(attributes.hasAttribute("automne")) {
                //    QString val =attributes.value("automne").toString();
                //    automne=(val == "true" ? true : false);
                //}
                //if(attributes.hasAttribute("printemps")) {
                //    QString val =attributes.value("printemps").toString();
                //    printemps=(val == "true" ? true : false);
                //}

         //       xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.
/*

                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "TC")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "CS") {
                            xml.readNext(); credCS=xml.text().toString();
                        }
                        // We've found titre.
                        if(xml.name() == "TM") {
                            xml.readNext(); credTM=xml.text().toString();
                        }
                        /*if(xml.name() == "TSH") {
                            xml.readNext(); credTSH=xml.text().toString();
                        }*/
                        // We've found titre.
/*
                      if(xml.name() == "SP") {
                            xml.readNext(); credSP=xml.text().toString();
                        }

                    }
                    // ...and next...
                    xml.readNext();
                }
                //ajouterUV(code,titre,nbCredits,cat,automne,printemps); // Pourquoi est-ce qu'on ajoute une UV quand on a trouvé ?

               TC& tc = TC::donneInstance();
               tc.setCredCS(credCS);
               tc.setCredTM(credTM);
               //tc.setCredTSH(credTSH);
               tc.setCredSP(credSP);
               TCEditeur t(tc);
               t.show();
            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}*/

