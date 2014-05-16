#include "dossier.h"

Dossier* Dossier::instanceUnique=0;

void Dossier::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

Dossier& Dossier::donneInstance(){
    if (instanceUnique==0) instanceUnique= &Dossier::donneInstance(); //pas sûre de ce que je fais là, je sais pas pourquoi ça marche avec TC & pas Dossier ??
    return *instanceUnique;
}

Dossier::~Dossier() {
    delete[] cursus;
    //delete[] inscriptions;
    //delete[] equivalences;
}
