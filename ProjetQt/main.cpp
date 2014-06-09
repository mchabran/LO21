#include <QApplication>
#include <iostream>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"
#include "UVEditeur.h"
#include "cursus.h"
#include "dossier.h"
#include "CursusManager.h"
#include "CursusEditeur.h"
#include "Inscription.h"
#include "MenuEditeur.h"

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);
   //QLabel *fen;

   //CursusManager

   /*CursusManager& m=CursusManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   const Cursus& nnewCursus=m.getCursus("GI");

   CursusEditeur fenetre(&m,&nnewCursus);
   fenetre.show();*/



   /*UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/
  // UVFinder fenetre(&m);
   /********Ajout d'UV ne marche pas*******/

   //Cursus* c1 = new Cursus("Tronc commun", C_TC, 42, 36, 12, 6);
   //Cursus* c2 = new Cursus("GI", C_Branche, 42, 36, 12, 6);
   //(QString n, CategorieCursus cat, QString nbCS, QString nbTM, QString nbTSH, QString nbSP)
   //CursusFinder fenetre(c);

   /*Cursus** tab = new Cursus*;
   tab[0] = &c;
   Dossier& d= Dossier::donneInstance(tab);
   //d.setCursus(c);
   DossierEditeur fenetre(d);*/
   //fenetre.ajouterTC("6", "24", "3"); // ??


   /****** TEST DOSSIER *****/
   UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   Semestre* a13 = new Semestre(Automne, 2013);
   Inscription* i1 = new Inscription(m.getUV("LO21"), *a13, A);
   Inscription* i2 = new Inscription(m.getUV("MT22"), *a13, E);
   Inscription* tabInscr[2]={i1, i2};

   //InscriptionEditeur fenetre(tabInscr);

   QString L1[3]={"MT22", "PS04", "CM11"};
   QString L2[3]={"LO21", "NF17", "SR02"};

   CursusManager& cm = CursusManager::getInstance();
   cm.ajouterCursus("Tronc commun", L1, 3, C_TC, 42, 36, 12, 6);
   cm.ajouterCursus("GI", L2, 3, C_Branche, 42, 36, 12, 6);

   Equivalence* e1 = new Equivalence("Harvard", "Angleterre", 13, 3, 4);
   Equivalence* tabEq[1]={e1};
   Dossier& doss = Dossier::donneInstance(cm);
   doss.setEquivalences(tabEq);
   doss.setInscriptions(tabInscr);
   doss.setNivB2(true);
   //DossierEditeur fenetre(m, *doss);

   MenuEditeur fenetre(m);

   fenetre.show();
   return app.exec();
}

