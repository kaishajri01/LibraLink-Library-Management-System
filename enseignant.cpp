#include <stdio.h>
#include <iostream>
#include <string.h>
#include "bib.h"


enseignant::enseignant(string n,string p,int c,int a):etudiant(n,p,c,a)
{
}
enseignant::enseignant():etudiant()
{}

void enseignant::affiche()
{
    cout<<"L'enseignant : \n";etudiant::affiche();
}





