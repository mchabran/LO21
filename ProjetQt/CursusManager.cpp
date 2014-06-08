#include "CursusManager.h"
#include"cursus.h"

//CAST
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

const Cursus* StringToCursus(const CursusManager& m, const QString& str){
    Cursus* cu=m.trouverCursus(str);
    if (cu==0) throw UTProfilerException("Cursus non existant");
    return cu;
}

QString CursusToString(Cursus cu){
    return cu.getNom();
}

CursusManager::CursusManager():mesCursus(new Cursus*[10]),nbCursus(0),nbMaxCursus(10),file(""){}

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

void CursusManager::load(const QString& f){
    if (file!=f) {
        this->~CursusManager();
    }
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
        if(token == QXmlStreamReader::StartElement){
            // If it's named uvs, we'll go to the next.
            if(xml.name() == "Cursus") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "unCursus") {
                QString nom;
                CategorieCursus cat;
                static QString* uvs=new QString[2];
                unsigned int nUV=0; //nb d'UV
                unsigned int nMUV=2;//nb MAX d'UV
                QString codeUV;
                unsigned int nbCS;
                unsigned int nbTM;
                unsigned int nbTSH;
                unsigned int nbSP;
                const Cursus* p;
                QString* newtab;
                unsigned int i;

                xml.readNext();
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "unCursus")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        /*
                        if(xml.name()=="parent"){
                            xml.readNext();p=StringToCursus(xml.text().toString());
                        }*/
                        if(xml.name() == "nom") {
                            xml.readNext(); nom=xml.text().toString();
                            QLabel *fen1=new QLabel(nom);
                            fen1->show();
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
                                        if(xml.name()=="uv"){
                                            xml.readNext();codeUV=xml.text().toString();
                                            uvs[nUV++]=codeUV;
                                        }
                                        if (nUV==nMUV){
                                            newtab=new QString[nMUV+10];
                                            for(i=0; i<nUV; i++) newtab[i]=uvs[i];
                                            nMUV+=10;
                                            QString* old=uvs;
                                            uvs=newtab;
                                            delete[] old;
                                        }
                                    }
                                    xml.readNext();
                               }
                        }
                    }
                    xml.readNext();

                }
                this->ajouterCursus(nom, uvs, nUV, cat, nbCS, nbTM, nbTSH, nbSP);
                nUV=0;
                QString* old=uvs;
                uvs=new QString[10];
                delete[] old;
            }//fin unCursus
        }
    }
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}

void CursusManager::addItem(Cursus* cu){
        if (nbCursus==nbMaxCursus){
                Cursus** newtab=new Cursus*[nbMaxCursus+10];
                for(unsigned int i=0; i<nbCursus; i++) newtab[i]=mesCursus[i];
                nbMaxCursus+=10;
                Cursus** old=mesCursus;
                mesCursus=newtab;
                delete[] old;
        }
        mesCursus[nbCursus++]=cu;
}

void CursusManager::ajouterCursus(const QString n, const QString* t, unsigned int nbU, CategorieCursus c, unsigned int CS, unsigned int TM, unsigned int TSH, unsigned int SP){
    if (trouverCursus(n)) throw UTProfilerException(QString("erreur, CursusManager, Cursus")+n+QString("déja existant"));
    Cursus* newcursus=new Cursus(n,c,CS,TM,TSH,SP);

    for(unsigned int i=0;i<nbU;i++){
        newcursus->addUV(t[i]);
    }
    addItem(newcursus);
    return;
}


Cursus& CursusManager::getCursus(const QString& nom){
        Cursus* cu=trouverCursus(nom);
    if (!cu) throw UTProfilerException("erreur, CursusManager, Cursus inexistante",__FILE__,__LINE__);
        return *cu;
}

const Cursus& CursusManager::getCursus(const QString& nom) const {
    return const_cast<CursusManager*>(this)->getCursus(nom);
}

CursusManager::Handler CursusManager::handler=Handler();

CursusManager& CursusManager::getInstance(){
    if (!handler.instance) handler.instance = new CursusManager; /* instance créée une seule fois lors de la première utilisation*/
    return *handler.instance;
}

void CursusManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}

void CursusManager::save(const QString& f){
    QLabel *fen=new QLabel("putain de bordel de merde !");
    fen->show();

    file=f;
    QFile newfile(file);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("coucou");
     /*for(unsigned int i=0; i<nbCursus; i++){
         stream.writeStartElement("unCursus");
         stream.writeTextElement("nom",mesCursus[i]->getNom());
         stream.writeTextElement("categorie",CategorieCursusToString(mesCursus[i]->getCategorie()));
         QString cr; cr.setNum(mesCursus[i]->getCredCS());
         stream.writeTextElement("CS",cr);
         cr.setNum(mesCursus[i]->getCredTM());
         stream.writeTextElement("TM", cr);
         cr.setNum(mesCursus[i]->getCredTSH());
         stream.writeTextElement("TSH", cr);
         cr.setNum(mesCursus[i]->getCredSP());
         stream.writeTextElement("SP", cr);
         stream.writeStartElement("UVs");
         for(unsigned int j=0; j<mesCursus[i]->getNbUV();i++){
             stream.writeTextElement("uv",mesCursus[i]->getTabUV()[j]);
         }
         stream.writeEndElement();
     }*/
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();
}
