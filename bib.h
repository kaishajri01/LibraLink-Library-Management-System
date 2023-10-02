#include <stdio.h>
#include <iostream>
#include <string.h>
//#include "etudiant.h"
#include "livre_etud_ens.h"

class bibliotheque
{
    private:
        
        
        
    public:
    int nblivre;
    int nbetud;
    int nbens;
    int enow;
    int ensnow;
    etudiant *ebib;
    enseignant *ensbib;
    livre *lbib;
    int lnow;
    bibliotheque();

    void Chargement_livre();
    void Chargement_etudiant();
    void Chargement_enseignant();

    void enregistrement_livre();
    void enregistrement_etudiant();
    void enregistrement_enseignant();

    void ajout_liv(string,string,int,int);
    void ajout_livre(livre l);
    void affiche_liv();

    void ajout_etud(string nom,string prenom,int age,int cin);
    void ajout_etudiant(etudiant a);
    void affiche_etu();



    void ajout_ens(string,string,int,int);
    void ajout_enseignant(enseignant ens);
    void affiche_ens();

    void rech_etud_nom(string nom,string preno);
    void rech_etud_cin(int cin);

    void rech_ens_nom(string nom,string preno);
    void rech_ens_cin(int cin);

    void rech_livre_nom(string nom,string aut);

    void modif_etud_cin(string,string,int c);
    void modif_etud_age(string,string,int ag);

    void modif_ens_cin(string,string,int c);
    void modif_ens_age(string,string,int ag);

    void modif_livre_code(string,string ,int );


    void supp_livre(string nom,string auteur);

    void supp_etudiant(string nom,string prenom);

    void supp_enseignant(string nom,string prenom);

    void print_livre_etud(string nom,int cin,string tit,string aut);
    void print_livre_ens(string nom,int cin,string tit,string aut);

    void affiche_printed_livre_etud(string,string);
    void affiche_printed_livre_ens(string,string);



    void statistique();

};


