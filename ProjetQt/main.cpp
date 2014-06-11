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
#include "CursusFinder.h"
#include "MenuEditeur.h"

int main(int argc, char* argv[]) {
   QApplication app(argc, argv);

   //********CursusManager************//
   /*CursusManager& m=CursusManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);
   CursusEditeur fenetre(&m);
   fenetre.show();*/

   //***********Fin*CursusManager********//

   QMessageBox::information(0, "Chargement Fichier", "Chargez le fichier UV_UTC.xml");
   UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);

   /*UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);
   fenetre.show();*/
   /*UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);*/
   /*UV& uv=m.getUV("LO21");
   UVEditeur fenetre(&m,uv);*/
  // UVFinder fenetre(&m);
   //********Ajout d'UV ne marche pas*******

   /*Cursus* c1 = new Cursus("Tronc commun", C_TC, 42, 36, 12, 6);
   Cursus* c2 = new Cursus("GI", C_Branche, 42, 36, 12, 6);*/

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
   Semestre* a13 = new Semestre(Automne, 2013);
   //Inscription* i1 = new Inscription(m.getUV("LO21"), *a13, A);
   //Inscription* i2 = new Inscription(m.getUV("MT22"), *a13, E);


   QString L1[3]={"MT22", "PS04", "CM11"};
   QString L2[3]={"LO21", "NF17", "SR02"};

   CursusManager& cm = CursusManager::getInstance();
   cm.ajouterCursus("Tronc commun", L1, 3, C_TC, 42, 36, 12, 6);
   cm.ajouterCursus("GI", L2, 3, C_Branche, 42, 36, 12, 6);

   Equivalence* e1 = new Equivalence("Harvard", "Angleterre", 12, 6, 8);
   Dossier& doss = Dossier::donneInstance(cm, m);
   doss.addEquivalence(e1);
   //doss.addInscription(i1);
   //doss.addInscription(i2);
   doss.setNivB2(true);

   QString chemin2 = QFileDialog::getOpenFileName();
   doss.loadInscription(chemin2);
   //DossierEditeur fenetre(m);


    //doss.libereInstance();
   MenuEditeur fenetre(m);
   fenetre.show();
   return app.exec();
}

