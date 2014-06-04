#include <QApplication>
#include <iostream>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"
#include "UVEditeur.h"
#include "cursus.h"
/*#include "TC.h"
#include "HuTech.h"*/
#include "dossier.h"
#include "CursusManager.h"
#include "CursusEditeur.h"

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);
   QLabel *fen;

   //CursusManager
   /*
   CursusManager& m=CursusManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   const Cursus& nnewCursus=m.getCursus("GI");

   CursusEditeur fenetre(&m,&nnewCursus);
   fenetre.show();
   */


   UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   /*UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/
  // UVFinder fenetre(&m);
   //********Ajout d'UV ne marche pas*******

   Cursus* c = new Cursus("Tronc commun", C_TC, 42, 36, 12, 6);
   //(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP)
   //CursusFinder fenetre(c);

   //TC& t = TC::donneInstance();
   //QString chemin = QFileDialog::getOpenFileName();
   //t.load(chemin);
   //Je suis pas tout à fait au point avec les fichiers --"
   //TCEditeur fenetre(t);

   //HuTech& hu = HuTech::donneInstance();
   //QString chemin = QFileDialog::getOpenFileName();
   //hu.load(chemin);
   //HTEditeur fenetre(hu);

   /*Cursus** tab = new Cursus*;
   tab[0] = &c;
   Dossier& d= Dossier::donneInstance(tab);
   //d.setCursus(c);
   DossierEditeur fenetre(d);*/
   //fenetre.ajouterTC("6", "24", "3"); // ??


   /****** TEST DOSSIER *****/
   Inscription* i1 = new Inscription(m.getUV("LO21"), A);
   Inscription* i2 = new Inscription(m.getUV("MT22"), E);
   Inscription* tabInscr[2]={i1, i2};
   Dossier* doss = new Dossier(&c, tabInscr, NULL, true, false);
   DossierEditeur fenetre(m, *doss);
   fenetre.show();
   return app.exec();
}

