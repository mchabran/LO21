#include "menu.h"


void EditionCursus(){
    CursusManager& m=CursusManager::getInstance();
    QString chemin = QFileDialog::getOpenFileName();
    m.load(chemin);
    CursusFinder* fenetre=new CursusFinder(&m);
    fenetre->show();
}
