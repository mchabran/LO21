#include "cursus.h"
#include "HuTech.h"

HuTech::HuTech(): Cursus("Humanites et Technologie", C_HuTech), credCS("48"), credTM("24"), credSP("0"){} //reste à initialiser credTSH si on en met

HuTech* HuTech::instanceUnique=0;

void HuTech::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

HuTech& HuTech::donneInstance(){
    if (instanceUnique==0) instanceUnique=new HuTech;
    return *instanceUnique;
}



HTEditeur::HTEditeur(HuTech& t, QWidget* parent) : ht(t){
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
    categorie->addItem("HuTech");
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


    QObject::connect(sauver, SIGNAL(clicked()), this, SLOT(sauverHT()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(close()));
}


void HTEditeur::sauverHT(){
    ht.setCredCS(credCS->text());
    ht.setCredTM(credTM->text());
    //ht->setCredTSH(credTSH->text());
    ht.setCredSP(credSP->text());
}



void HuTech::save(const QString& f){
    QFile newfile(file);
    file=f;
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw ("erreur ouverture fichier xml");
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("HuTech");
     stream.writeAttribute("CS", (getCredCS()));
     stream.writeAttribute("TM", (getCredTM()));
     //stream.writeTextElement("TSH",(getCredTSH));
     stream.writeTextElement("SP",getCredSP());
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}




void HuTech::load(const QString& f){//pas d'erreur de compilation :)
    if (file!=f) this->~Cursus();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw "Erreur ouverture fichier cursus";
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
            // If it's named HuTech, we'll dig the information from there.
            if(xml.name() == "HuTech"  ) {
                QString credCS;
                QString credTM;
                //QString credTSH; //Idem que pour TC (:
                QString credSP;

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "HuTech")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found CS.
                        if(xml.name() == "CS") {
                            xml.readNext(); credCS=xml.text().toString();
                        }
                        // We've found TM.
                        if(xml.name() == "TM") {
                            xml.readNext(); credTM=xml.text().toString();
                        }
                        // We've found TSH.
                        /*if(xml.name() == "TSH") {
                            xml.readNext(); credTSH=xml.text().toString().toString();
                        }*/
                        // We've found SP
                        if(xml.name() == "SP") {
                            xml.readNext(); credSP=xml.text().toString();
                        }
                    }
                    // ...and next...
                    xml.readNext();
                }
                //**************CLEMENCE QUI COMMENTE********************
                //pas besoin de changer qc ?

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw "Erreur lecteur fichier UV, parser xml";
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}

