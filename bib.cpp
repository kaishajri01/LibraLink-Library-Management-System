
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "bib.h"
#include <stddef.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;


bibliotheque::bibliotheque():lbib(new livre[20]),ensbib(new enseignant[20]),ebib(new etudiant[20]),lnow(0),enow(0),ensnow(0),nblivre(0),nbetud(0),nbens(0)
{}

/* ***** IMPLEMENTAION DU BIBLIOTHEQUE LIVRE ****** */

void bibliotheque::ajout_liv(string ch,string c,int s,int a)
    {
        livre ab(ch,c,s,a);
        lbib[lnow]=ab;
        lnow++;
        nblivre++;
    }
void bibliotheque::ajout_livre(livre l)
{
    lbib[lnow]=l;
    lnow++;
    nblivre++;
}
void bibliotheque::affiche_liv()
    {
        int i;
        if(lnow!=0)
        {for(i=0;i<lnow;i++)
            lbib[i].affiche();}
        else
            cout<<"Aucun Livre dans la Bibliotheque.\n";
    }
void bibliotheque::rech_livre_nom(string nom,string aut)
    {
        for(int i=0;i<lnow;i++)
        {
                if(lbib[i].gettitre()==nom&&lbib[i].getauteur()==aut)
                {   cout<<"Le Livre Existe : \n ";
                    lbib[i].affiche();
                    return;
                }
        }
        cout<<"Le Livre n'existe pas a la Bibliotheque.\n";
    }
void bibliotheque::modif_livre_code(string tit,string aut,int c)
    {
       for(int i=0;i<lnow;i++)
        {
            if(lbib[i].gettitre()==tit&&lbib[i].getauteur()==aut)
                {
                    lbib[i].setcode(c);
                    return;
                }
        }
        cout<<"Le livre n'existe pas a la Bibliotheque.\n";
                
    }
void bibliotheque::supp_livre(string titre,string aut)
    {
for(int i=0;i<lnow;i++)
        {
            if(lbib[i].gettitre()==titre&&lbib[i].getauteur()==aut)
                {
                    for(int j=i;j<lnow-1;j++)
                        {lbib[j]=lbib[j+1];}
                    nblivre--;
                    lnow--;
                    cout<<"\nSupression du Livre "<<titre<<" avec Succees.\n";
                    return ;
                }   
        }
        cout<<"Le Livre n'existe pas a la Bibliotheque !\n";

    }




/* ***** IMPLEMENTAION DU BIBLIOTHEQUE ETUDIANT ****** */

void bibliotheque::ajout_etud(string nom,string prenom,int cin,int age)
    {
        etudiant a(nom,prenom,cin,age);
        ebib[enow]=a;
        enow++;
        nbetud++;
    }
void bibliotheque::ajout_etudiant(etudiant a)
    {
        ebib[enow]=a;
        enow++;
        nbetud++;
    }

void bibliotheque::affiche_etu()
    {
        int i;
        if(enow!=0)
        {for(i=0;i<enow;i++)
            {
                ebib[i].affiche();
                printf("\n");
            }}
        cout<<"Aucun Etudiant dans la Bibliotheque.\n";

    }

void bibliotheque::rech_etud_nom(string nom,string prenom)
    {
        for(int i=0;i<enow;i++)
        {  
            if(ebib[i].getNom()==nom&&ebib[i].getPrenom()==prenom)
                {
                    cout<<"L'Etudiant est inscrit a la Bibliotheque : \n ";
                    ebib[i].affiche();
                    return;
                }
        }
        cout<<"L'Etudiant "<<nom<<" n'est pas inscrit a la Bibliotheque.\n";
    }

void bibliotheque::rech_etud_cin(int cin)
    {
        for(int i=0;i<enow;i++)
        {  
            if(ebib[i].getCin()==cin)
                {
                    cout<<"L'Etudiant est inscrit a la Bibliotheque : \n ";
                    ebib[i].affiche();
                    return;
                }
        }
        cout<<"L'Etudiant portant la Cin "<<cin<<" n'est pas inscrit a la Bibliotheque.\n";
    }
void bibliotheque::modif_etud_cin(string n,string p,int c)
    {
        for(int i=0;i<enow;i++)
        {
            if(ebib[i].getNom()==n&&ebib[i].getPrenom()==p)
                {
                    ebib[i].setCin(c);
                    cout<<"Changement Du Cin de "<<n<<" Avec Succees";
                    return;
                }
        }
        cout<<"L'Etudiant n'est pas inscrit a la Bibliotheque.\n";
    }

void bibliotheque::modif_etud_age(string n,string p,int ag)
    {
        for(int i=0;i<enow;i++)
        {
            if(ebib[i].getNom()==n&&ebib[i].getPrenom()==p)
                {
                    ebib[i].setAge(ag);
                    cout<<"Changement D'Age de "<<n<<" Avec Succees";
                    return;
                }
        }
        cout<<"L'Etudiant n'est pas inscrit a la Bibliotheque.\n";
    }
void bibliotheque::supp_etudiant(string nom,string prenom)
    {
        for(int i=0;i<enow;i++)
        {
            if(ebib[i].getNom()==nom&&ebib[i].getPrenom()==prenom)
                {
                    for(int j=i;j<enow-1;j++)
                       { ebib[j]=ebib[j+1]; }
                    nbetud--;
                    enow--;
                    cout<<"\nSupression d'Etudiant "<<nom<<" avec Succees.\n";
                    return ;
                }   
        }
        cout<<"L' Etudiant n'est pas inscrit a la Bibliotheque !\n";

    }


/* ***** IMPLEMENTAION DU BIBLIOTHEQUE LENSEIGNANT ****** */

void bibliotheque::ajout_ens(string nom,string prenom,int cin,int age)
{
    enseignant a(nom,prenom,cin,age);
    ensbib[ensnow]=a;
    ensnow++;
    nbens++;

}
void bibliotheque::ajout_enseignant(enseignant ens)
{
    ensbib[ensnow]=ens;
    ensnow++;
    nbens++;

}
void bibliotheque::affiche_ens()
{
    int i;
        if(ensnow!=0)
        {for(i=0;i<ensnow;i++)
            {
                ensbib[i].affiche();
                printf("\n");
            }}
        else
            cout<<"Aucun Enseignant dans la Bibliotheque.\n";
}


void bibliotheque::rech_ens_nom(string nom,string prenom)
{
        for(int i=0;i<ensnow;i++)
        {
            if(ensbib[i].getNom()==nom&&ensbib[i].getPrenom()==prenom)
                {
                    cout<<"L'Enseignant est inscrit a la Bibliotheque : \n ";
                    ensbib[i].affiche();
                    return;
                }
        }
        cout<<"L'Enseignant " <<nom<<" n'est pas inscrit a la Bibliotheque.\n";

}
void bibliotheque::rech_ens_cin(int cin)
{
    for(int i=0;i<ensnow;i++)
        {
            if(ensbib[i].getCin()==cin)
                {
                    cout<<"L'Enseignant est inscrit a la Bibliotheque : \n ";
                    ensbib[i].affiche();
                    return;
                }
        }
        cout<<"L'Enseignant portant La Cin "<<cin<<" n'est pas inscrit a la Bibliotheque.\n";
}
void bibliotheque::modif_ens_cin(string n ,string p,int c)
    {
        for(int i=0;i<ensnow;i++)
        {
            if(ensbib[i].getNom()==n&&ensbib[i].getPrenom()==p)
                {
                    ensbib[i].setCin(c);
                    cout<<"Changement Du Cin de "<<n<<" Avec Succees";
                    return;
                }
        }
        cout<<"L'Enseignant n'est pas inscrit a la Bibliotheque.\n";
    }

void bibliotheque::modif_ens_age(string n,string p,int ag)
    {
        for(int i=0;i<ensnow;i++)
        {
            if(ensbib[i].getNom()==n&&ensbib[i].getPrenom()==p)
                {
                    ensbib[i].setAge(ag);
                    cout<<"Changement D'Age de "<<n<<" Avec Succees";
                    return;
                }
        }
        cout<<"L'Enseignant n'est pas inscrit a la Bibliotheque.\n";
    }

void bibliotheque::supp_enseignant(string nom,string prenom)
{
for(int i=0;i<ensnow;i++)
        {
            if(ensbib[i].getNom()==nom&&ensbib[i].getPrenom()==prenom)
                {
                    for(int j=i;j<ensnow-1;j++)
                       { ensbib[j]=ensbib[j+1]; }
                    nbens--;
                    ensnow--;
                    cout<<"\nSupression d'Enseignant "<<nom<<" avec succees";
                    return ;
                }   
        }
    cout<<"L' Enseignant n'est pas inscrit a la Bibliotheque !\n";

}

void bibliotheque::print_livre_etud(string nom,int cin,string tit,string aut)
{
    for(int i=0;i<enow;i++)
    {
        if(ebib[i].getNom()==nom&&ebib[i].getCin()==cin)
            {
                for(int j=0;j<lnow;j++)
                {
                    if(lbib[j].gettitre()==tit&&lbib[j].getauteur()==aut)
                    {
                        if(lbib[j].getstock()>0)
                        {
                            lbib[j].stock--;
                            lbib[j].stat++;
                            ebib[i].printed_livre[ebib[i].livnow]=lbib[j];
                            ebib[i].livnow++;
                            ebib[i].setactif(ebib[i].getactif()+1);
                            return;
                        }
                        else
                        {
                            cout<<"Desole "<<nom<<" Epuise de Stock Du livre "<<lbib[j].gettitre()<<".\n";
                            return;
                        }
                    }
                }      
                cout<<"Desole "<<ebib[i].getNom()<<" le livre Desire n'exite pas !"<<"\n";
                return;    
            }
    }
    cout<<"L'Etudiant n'est pas inscrit a la bibliotheque !"<<"\n";
    
}


void bibliotheque::print_livre_ens(string nom,int cin,string tit,string aut)
{
    for(int i=0;i<ensnow;i++)
    {
        if(ensbib[i].getNom()==nom&&ensbib[i].getCin()==cin)
            {
                for(int j=0;j<lnow;j++)
                {
                    if(lbib[j].gettitre()==tit&&lbib[j].getauteur()==aut)
                    {
                        if(lbib[j].getstock()>0)
                        { 
                            lbib[j].stat++;
                            lbib[j].stock--;
                            ensbib[i].printed_livre[ensbib[i].livnow]=lbib[j];
                            ensbib[i].livnow++;
                            ensbib[i].setactif(ensbib[i].getactif()+1);
                            return;
                        }
                        else
                            {
                                cout<<"Desole "<<nom<<" Epuise de Stock Du livre "<<lbib[j].gettitre()<<".\n";
                                return;
                            }
                    }
                }
                cout<<"Desole "<<ensbib[i].getNom()<<" le livre Desire n'exite pas !"<<"\n";
                return;

            }
    }
    cout<<"L'Enseignant n'est pas inscrit a la bibliotheque !"<<"\n";
}


void bibliotheque::statistique()
{
    int livemp=0; //nombre des livres emprinté au totale

    int etuactif=0;
    etudiant etuactiff;

    int ensactif=0;
    enseignant ensactiff;

    int livpemp=lbib[0].stat; // le livre le plus emprinté
    livre l=lbib[0];
    
    for(int i=0;i<lnow;i++)
    {
        if(lbib[i].stat!=0)
            livemp=lbib[i].stat+livemp;
    }

    for(int i=0;i<lnow;i++)
    {
        if(lbib[i].stat>livpemp)
            {
                livpemp=lbib[i].stat;
                l=lbib[i];
            }
    } 


    for(int i=0;i<enow;i++)
    {
        if(ebib[i].getactif()>etuactif)
           {
                etuactif=ebib[i].getactif();
                etuactiff=ebib[i];
           }
    }

    for(int i=0;i<ensnow;i++)
    {
        if(ensbib[i].getactif()>ensactif)
           {
                ensactif=ensbib[i].getactif();
                ensactiff=ensbib[i];
           }
    }
    cout<<"\nLe Nombre Totale des livres Dans la Bibliotheque : "<<nblivre;
    cout<<"\nLe Nombre Totale des Etudiants Inscrit a la Bibliotheque : "<<nbetud;
    cout<<"\nLe Nombre Totale des Enseignant Inscrit a la Bibliotheque : "<<nbens;
    if(livemp!=0)
        {
            cout<<"\nLe nombre des Livre Emprinte : "<<livemp;
            cout<<"\nLe livre le plus Emprinte ("<<livpemp<<" fois) : \n";
            l.affiche();
        }
    else
        {cout<<"\nPas de livre Emprinte pour le moment !";}



    if(etuactif!=0)
    {
        cout<<"\nL'etudiant Le Plus Actif ("<<etuactif<<" Livres) : \n";
        etuactiff.affiche();
    }
    else
        {cout<<"\nPas d'etudiant Actif pour le moment !\n";}




    if(ensactif!=0)
    {
            cout<<"\nL'enseignant Le Plus Actif ("<<ensactif<<" Livres) : \n";
            ensactiff.affiche();
    }
   else
            cout<<"Pas d'enseignant Actif pour le moment !\n";

}

    void bibliotheque::affiche_printed_livre_etud(string n,string p)
     {
    for(int i=0;i<enow;i++)
    {
        if(ebib[i].getNom()==n&&ebib[i].getPrenom()==p)
            {
            if(ebib[i].livnow!=0)
                    {
                            cout<<"Les livre printe par l'etudiant "<<ebib[i].getNom()<<" :";
                            for(int j=0;j<ebib[i].livnow;j++)
                                {
                                    ebib[i].printed_livre[j].affiche();
                                }
                            return;
                    }
         else
            cout<<"l'Etudiant "<< ebib[i].getNom()<< " n'a emprinte aucun livre !\n";
            }
    }
    cout<<"L'Etudiant n'est pas inscrit a la Bibliotheque.\n";
    }
    
    void bibliotheque::affiche_printed_livre_ens(string n,string p)
    {
    for(int i=0;i<ensnow;i++)
    {
        if(ensbib[i].getNom()==n&&ensbib[i].getPrenom()==p)
        {
            if(ensbib[i].livnow!=0)
                    {
                            cout<<"Les livre printe par l'enseignant "<<ensbib[i].getNom()<<" :";
                            for(int j=0;j<ensbib[i].livnow;j++)
                                {
                                    ensbib[i].printed_livre[j].affiche();
                                }
                            return;
                    }
         else
            {
                cout<<"l'Enseignant "<< ensbib[i].getNom()<< " n'a emprinte aucun livre !\n";
                return;
            }
        }
    }
    cout<<"L'Enseignant n'est pas inscrit a la Bibliotheque.\n";
    }












/*  LES CHARGEMENTS ET ENREGISTREMENT */


void bibliotheque::enregistrement_livre()
{
    ofstream outdata ;
    outdata.open("livre.csv");
    if(!outdata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

    for (int i=0; i<lnow; i++)
        outdata << lbib[i].gettitre()<<";"<<lbib[i].getauteur()<<";"<<lbib[i].getcode()<<";"<<lbib[i].getstock()<<"\n";
    outdata.close();
}

void bibliotheque::enregistrement_etudiant()
{
    ofstream outdata ;
    outdata.open("etudiant.csv");
    if(!outdata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

    for (int i=0; i<enow; i++)
        outdata << ebib[i].getNom()<<";"<<ebib[i].getPrenom()<<";"<<ebib[i].getCin()<<";"<<ebib[i].getAge()<<"\n";
    outdata.close();
}

void bibliotheque::enregistrement_enseignant()
{
    ofstream outdata ;
    outdata.open("enseignant.csv");//,std::ios::app ; Pour ne pas effacer et ajouter à la suite
    if(!outdata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

    for (int i=0; i<ensnow; i++)
        outdata << ensbib[i].getNom()<<";"<<ensbib[i].getPrenom()<<";"<<ensbib[i].getCin()<<";"<<ensbib[i].getAge()<<"\n";
    outdata.close();
}





/**************** CHARGEMENT ********/

void bibliotheque::Chargement_livre()
{ 
    string ch1,ch2,n1,n2;
    
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file ("livre.csv", ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ';'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        int j=0;
        while(j<content[i].size())
        {
            ch1=content[i][j];
            j++;
            ch2=content[i][j];
            j++;
            n1=content[i][j];
            j++;
            n2=content[i][j];
            j++;
        }
        ajout_liv(ch1,ch2,stoi(n1),stoi(n2));

	}
    

}
void bibliotheque::Chargement_etudiant()
{
    string ch1,ch2,n1,n2;
    
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file ("etudiant.csv", ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ';'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        int j=0;
        while(j<content[i].size())
        {
            ch1=content[i][j];
            j++;
            ch2=content[i][j];
            j++;
            n1=content[i][j];
            j++;
            n2=content[i][j];
            j++;
        }
        ajout_etud(ch1,ch2,stoi(n1),stoi(n2));

	}
    
}
void bibliotheque::Chargement_enseignant()
{
    string ch1,ch2,n1,n2;
    
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file ("enseignant.csv", ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ';'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        int j=0;
        while(j<content[i].size())
        {
            ch1=content[i][j];
            j++;
            ch2=content[i][j];
            j++;
            n1=content[i][j];
            j++;
            n2=content[i][j];
            j++;
        }
        ajout_ens(ch1,ch2,stoi(n1),stoi(n2));

	}
    
}

    





