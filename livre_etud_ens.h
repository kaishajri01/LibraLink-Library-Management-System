#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


class livre
{
    private:
    string auteur;
    string titre;
    int code;
    
    


    public:
    int stock;
    int stat; //Combien de fois a ete emprinté
    livre();
    livre(string,string,int,int);
    void affiche();
    string gettitre();
    int getcode();
    string getauteur();
    int getstock();
    void setstock(int);
    void settitre(string ch);
    void setcode(int c);
    void setauteur(string a);

};





class etudiant 
{
    private:

    string nom;
    string prenom;
    int cin;
    int age;
    int actif; //Combien de livre a emprinté
    
    
    public:
    livre *printed_livre;
    int livnow; // indice du tableau des livre emprinté
    etudiant(string,string,int,int);
    etudiant();
    string getNom();
    void setNom(string);
    string getPrenom();
    int getactif();
    void setactif(int);
    void setPrenom(string);
    int getAge();
    void setAge(int);
    int getCin();
    void setCin(int);
    void affiche();



};






class enseignant : public etudiant
{
    public:
    
    enseignant(string,string,int,int);
    enseignant();
    void affiche();
};





