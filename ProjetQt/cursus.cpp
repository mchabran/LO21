#include "cursus.h"
#include "CursusManager.h"




void Cursus::addUV(QString u){
    try{
        UVManager& m = UVManager::getInstance();
        UV& uv = m.getUV(u);
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
    catch(UTProfilerException e){
        QMessageBox::information(0, "Erreur Cursus::addUV", e.getInfo());
    }
}


