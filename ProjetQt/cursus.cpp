#include "cursus.h"
#include "CursusManager.h"




void Cursus::addUV(QString u){
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


//Cursus
/*
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
}*/

