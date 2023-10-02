#include <stdio.h>
#include <iostream>
#include <string.h>
#include "bib.h"


using namespace std;

    livre::livre(string tit,string aut,int cod ,int stoc):titre(tit),auteur(aut),code(cod),stock(stoc),stat(0)
    {}

    void livre::affiche()
    {
        cout<<"\nTitre : "<<titre;
        cout<<"\nL'Auteur : "<<auteur<<"\n";
        printf("Le code : %d\n",code);
        printf("Stock : %d\n",stock);
        
    }
    livre::livre(){}
    string livre::gettitre()
    {
        return titre;
    }
    int livre::getcode()
    {
        return code;
    }
    string  livre::getauteur()
    {
        return auteur;
    }

    void livre::settitre(string ch)
    {
        titre=ch;
    }
    void livre::setcode(int c)
    {
        code=c;
    }
    void livre::setauteur(string a)
    {
        auteur=a;
    }
    int livre::getstock()
    {
        return stock;
    }
    void livre::setstock(int x)
    {
        stock=x;
    }


    