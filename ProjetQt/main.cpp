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

   CursusManager& m=CursusManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   Cursus& nnewCursus=m.getCursus("GI");

   CursusEditeur fenetre(&m,&nnewCursus);
   /*fenetre.show();
   */

   /*try{m.save(chemin);}
   catch(UTProfilerException e){
      fen=new QLabel(e.getInfo());
       fen->show();
   }*/
/*
     UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);

   UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);
   fenetre.show();*/
   /*UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);*/
   /*UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/
  // UVFinder fenetre(&m);
   //********Ajout d'UV ne marche pas*******

 //  Cursus* c1 = new Cursus("Tronc commun", C_TC, 42, 36, 12, 6);
  // Cursus* c2 = new Cursus("GI", C_Branche, 42, 36, 12, 6);
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
   /*Semestre* a13 = new Semestre(Automne, 2013);
   Cursus* tabCur[2];
   tabCur[0]=c1,
   tabCur[1]=c2;
   Inscription* i1 = new Inscription(m.getUV("LO21"), *a13, A);
   Inscription* i2 = new Inscription(m.getUV("MT22"), *a13, E);
   Inscription* tabInscr[2]={i1, i2};

   QString L1[3]={"MT22", "PS04", "CM11"};
   QString L2[3]={"LO21", "NF17", "SR02"};

   CursusManager& cm = CursusManager::getInstance();
   cm.ajouterCursus("Tronc commun", L1, 3, C_TC, 42, 36, 12, 6);
   cm.ajouterCursus("GI", L2, 3, C_Branche, 42, 36, 12, 6);

   Equivalence* e1 = new Equivalence("Harvard", "Salut", 13, 3, 4);
   Equivalence* tabEq[1]={e1};
   Dossier* doss = new Dossier(cm, tabInscr, tabEq, true, false);
   DossierEditeur fenetre(m, *doss);*/
   fenetre.show();
   return app.exec();
}

