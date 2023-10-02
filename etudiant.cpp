#include <stdio.h>
#include <iostream>
#include <string.h>
#include "bib.h"


using namespace std;

    etudiant::etudiant(string n,string p,int c,int a):nom(n),prenom(p),cin(c),age(a),livnow(0),actif(0),printed_livre(new livre[100])
    {
    }

    
    etudiant::etudiant(){}
    string etudiant::getNom() {
        return nom;
    }
    int etudiant::getactif()
    {
        return actif;
    }
    void etudiant::setactif(int x)
    {
        actif=x;
    }
    void etudiant::setNom(string n) {
        nom = n;
    }
    string etudiant::getPrenom() {
        return prenom;
    }
    void etudiant::setPrenom(string p) {
        prenom = p;
    }
    int etudiant::getAge() {
        return age;
    }
    void etudiant::setAge(int a) {
        age = a;
    }
    int etudiant::getCin() {
        return cin;
    }
    void etudiant::setCin(int c) {
        cin = c;
    }
    void etudiant::affiche()
    {
        cout<<"nom : "<<nom<<"\n"<<"prenom : "<<prenom<<"\n"<<"cin = "<<cin<<"\n"<<"age : "<<age<<"\n";
    }


    