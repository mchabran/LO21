#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"
#include "UVEditeur.h"
#include "cursus.h"
#include "TC.h"
#include "HuTech.h"
#include "dossier.h"

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);

   /*UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/

   Cursus c("Tronc commun");
   CursusEditeur fenetre(c);



   //TC& t = TC::donneInstance();
   //QString chemin = QFileDialog::getOpenFileName();
   //t.load(chemin);
   //Je suis pas tout à fait au point avec les fichiers --"
   //TCEditeur fenetre(t);

   /*HuTech& hu = HuTech::donneInstance();
   QString chemin = QFileDialog::getOpenFileName();
   hu.load(chemin);
   HTEditeur fenetre(hu);*/

   //Cursus** tab = new Cursus*;
   //*tab[0] = c;
   /*Dossier& d= Dossier::donneInstance();
   d.setCursus(tab);
   DossierEditeur fenetre(d);*/




   fenetre.show();
   return app.exec();
}

