#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"
#include "UVEditeur.h"
#include "cursus.h"
#include "TC.h"
#include "HuTech.h"

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);
   /*
   UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/

   //Cursus c("Tronc commun");
   //CursusEditeur fenetre(c);

   /*TC& t = TC::donneInstance();
   //QString chemin = QFileDialog::getOpenFileName();
   //t.load(chemin);
   //Je suis pas tout à fait au point avec les fichiers --"
   TCEditeur fenetre(t); // marche pas*/

   HuTech& hu = HuTech::donneInstance();
   HTEditeur fenetre(hu);



   fenetre.show();
   return app.exec();
}

