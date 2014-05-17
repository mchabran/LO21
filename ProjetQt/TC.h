#ifndef TCEDITEUR_H
#define TCEDITEUR_H
#include <QString>
#include <QTextStream>
#include <QFile>
#include "cursus.h"

using namespace std;

class TC : public Cursus{ //Singleton (un seul cursus TC à créer)
    QString credCS;
    QString credTM;
    //QString credTSH; //comment on fait pour les TSH sachant qu'il faut 52 crédits branche + TC confondus ? (:
    QString credSP;
        //Implémentation du Singleton
    static TC* instanceUnique;
    TC();
    TC(const TC* instance);
    virtual ~TC() {}
    virtual void operator=(const TC&){}
public :
    QString getCredCS()const {return credCS;}
    QString getCredTM()const {return credTM;}
    //QString getCredTSH() const {return credTSH;}
    QString getCredSP() const {return credSP;}
        //Implémentation du singleton
    void setCredCS(QString n){credCS=n;}
    void setCredTM(QString n){credTM=n;}
    //void setCredTSH(QString n){credTSH=n;}
    void setCredSP(QString n){credSP=n;}

    static TC& donneInstance();
    static void libereInstance();

    void save(const QString& f); //sauvegarder le TC dans un fichier
    void load(const QString &f);
};


class TCEditeur : public QWidget{
    //Q_OBJECT
    TC& tc;
    QLineEdit* nom;
    QLabel* nomLabel;
    QLineEdit* credCS;
    QLabel* CSLabel;
    QLineEdit* credTM;
    QLabel* TMLabel;
    /*QLineEdit* credTSH;
    QLabel* TSHLabel;*/
    QLineEdit* credSP;
    QLabel* SPLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QPushButton* sauver;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
    QHBoxLayout* coucheH5;
    QHBoxLayout* coucheH6;


public :
    TCEditeur(TC& t, QWidget* parent=0); //Le parent par défaut est 0 : nouvelle fenêtre

public slots :
   void sauverTC();
};
#endif // TCEDITEUR_H
