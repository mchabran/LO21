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
   //chargement de UV_UTC.xml
   QMessageBox::information(0, "Chargement Fichier", "Chargez le fichier UV_UTC.xml");
   UVManager& m=UVManager::getInstance();
   QString chemin = QFileDialog::getOpenFileName();
   m.load(chemin);

   //chargement de cursus.xml
   CursusManager& cm = CursusManager::getInstance();
   QMessageBox::information(0, "Chargement Fichier", "Chargez le fichier cursus.xml");
   QString chemin3 = QFileDialog::getOpenFileName();
   cm.load(chemin3);

   //chargement de dossier.xml
   Dossier& doss = Dossier::donneInstance(/*cm, m*/);
   QMessageBox::information(0, "Chargement fichier", "Chargez le fichier dossier.xml");
   QString chemin2 = QFileDialog::getOpenFileName();
   doss.loadDossier(chemin2);

   //chargement inscriptions.xml
   QMessageBox::information(0, "Chargement fichier", "Chargez le fichier inscriptions.xml");
   QString chemin4 = QFileDialog::getOpenFileName();
   doss.loadInscription(chemin4);

   //chargement equivalence.xml
   QMessageBox::information(0, "Chargement fichier", "Chargez le fichier equivalences.xml");
   QString chemin5 = QFileDialog::getOpenFileName();
   doss.loadEquivalence(chemin5);

   MenuEditeur fenetre(m);
   fenetre.show();
   return app.exec();
}

