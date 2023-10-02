#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdexcept>
#include <tchar.h>
#include <limits>
#include <conio.h>
#include <windows.h>
#include "myconio.h"
#include <winuser.h>
#include "Win32InputBox.h"
#include "bib.h"
#include <imagehlp.h>
#include <cstdint>
#include <wingdi.h>
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
using namespace std;
HDC hdc;
static HBITMAP bmpSource = NULL;
static HDC hdcSource = NULL;


 HBITMAP bitmap;	


PAINTSTRUCT ps;
HDC hdcDestination;

bibliotheque b;
etudiant e;
enseignant ens;
livre l; 
int verif=0;
char repet;
string tit,aut,nom;
int stock,code;
int choix;
int chargerliv=0,chargerens=0,chargeretu=0;
int enreliv=0,enreetu=0,enreens=0;

wstring stemp;
LPCWSTR resultt;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd);

HWND hname, hage, hout, hogo, Add, Finnish;

HMENU hmenu;

HBITMAP hlogoImage, hgenerateImage;
int intro = 1;
char ch[30];
long p;
char buff[100];
/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("Gestion du Bibliotheque");

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow)
{
    HWND hwnd;        /* This is the handle for our window */
    MSG messages;     /* Here messages to the application are saved */
    WNDCLASSEX wincl; /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS;            /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* No menu */
    wincl.cbClsExtra = 0;      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND + 7;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx(
        0,                           /* Extended possibilites for variation */
        szClassName,                 /* Classname */
        _T("Gestion du Bibliotheque"), /* Title Text */
        WS_OVERLAPPEDWINDOW,         /* default window */
        CW_USEDEFAULT,               /* Windows decides the position */
        CW_USEDEFAULT,               /* where the window ends up on the screen */
        1920,                        /* The programs width */
        1080,                        /* and height in pixels */
        HWND_DESKTOP,                /* The window is a child-window to desktop */
        NULL,                        /* No menu */
        hThisInstance,               /* Program Instance handler */
        NULL                         /* No Window Creation data */
    );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HBITMAP hBmp;


    /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/
    

    switch (message) /* handle the messages */
{


    case WM_COMMAND:
        switch (wParam)
    {
        
        case 1:
            if(verif==0)
                {MessageBox(hwnd,"Bibliotheque Cree Avec Success","Creation Du Bibliotheque", MB_OK|MB_ICONINFORMATION);
                verif++;}
            else
                {MessageBox(hwnd, "Bibliotheque Deja Cree !","Attention", MB_OK | MB_ICONHAND);}


            break;


        case 211:

         if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{  
        system("cls");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n           ****** Ajout d'un Livre ******\n";
        cout<<"#############################################################\n";
        do{
            cout<<"- Saisit Le Titre : ";
            cin>>tit;
            cout<<"- Saisit L'auteur : ";
            cin>>aut;
            cout<<"- Saisit Le Code : ";
            cin>>code;
            while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "\nInput Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
            cout<<"- Saisit Le Stock : ";
            cin>>stock;
            while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "\nInput Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
            //b.ajout_liv(tit,aut,code,stock);
            do{
                cout<<"- Voulez-vous ajouter un autre livre ? (Y/N) : ";
                cin>>repet;
                }while(repet!='Y'&&repet!='N');
                }while(repet=='Y');  
                system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Ajout Du Livre Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }       
            break;
        case 212:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
         system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n      ****** Modifier CODE d'un Livre ******\n";
        cout<<"#############################################################\n";
                    cout<<"- Saisit Le Titre: ";
                    cin>>tit;
                    cout<<"- Saisit L'Auteur: ";
                    cin>>aut;
                    cout<<"- Saisit Le nouveau Code: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_livre_code(tit,aut,code);
                system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Modification Du Code Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }
            break;




        case 213:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
         system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n       ****** Supression d'un Livre ******\n";
        cout<<"#############################################################\n";
                    do{
                    cout<<"- Saisit Le Titre: ";
                    cin>>tit;
                    cout<<"- Saisit L'Auteur: ";
                    cin>>aut;
                    b.supp_livre(tit,aut);
                    do{
                    cout<<"- Voulez-vous Supprimer un autre livre ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                     system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Supression Du Livre Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
            
        }
        break;



        case 221:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n        ****** Ajout d'un Etudiant ******\n";
        cout<<"#############################################################\n";
                    do{
                    cout<<"- Saisit Le Nom : ";
                    cin>>tit;
                    cout<<"- Saisit Le Prenom : ";
                    cin>>aut;
                    cout<<"- Saisit La Cin : ";
                    cin>>stock;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
                    cout<<"- Saisit L'Age : ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.ajout_etud(tit,aut,stock,code);
                    do{
                    cout<<"Voulez-vous ajouter un autre Etudiant ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                    system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Ajout De l'Etudiant Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
            
        }
        
        break;


        case 222:


        if(verif==0)
            {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        system("color 4F");
        //system("color 9F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n      ****** Recherche Etudiant par Nom ******\n";
        cout<<"#############################################################\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le prenom: ";
                    cin>>aut;
                    b.rech_etud_nom(tit,aut);
         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
           
        }
        break;


        case 223:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
            cout<<"#############################################################";
            cout<<"\n      ****** Recherche Etudiant par CIN ******\n";
            cout<<"#############################################################\n";
                    cout<<"- Saisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.rech_etud_cin(code);

                system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        }
        break;



        case 224:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n      ****** Modifier CIN d'un Etudiant ******\n";
        cout<<"#############################################################\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit La Nouvelle  Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_etud_cin(tit,aut,code);
                    cout<<"La Cin de "<<tit<<" Est Bien Modifie.\n";

        system("pause");
        ShowWindow(hwnd, SW_NORMAL);
        system("cls");
        MessageBox(hwnd, "Modification Du CIN Avec Success", " Modification", MB_OK|MB_ICONINFORMATION);
           
        }
        break;


        case 225:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);

cout<<"\n****** Modifier AGE d'un Etudiant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit Le Nouveau Age: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_etud_age(tit,aut,code);

         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Modification'Age Avec Success", " Modification", MB_OK|MB_ICONINFORMATION);
           
        }
        break;


        case 226:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        
        cout<<"#############################################################";
        cout<<"\n         ****** Supression d'un Etudiant ******\n";     
        cout<<"#############################################################\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>aut;
                    b.supp_etudiant(tit,aut);
                    do{
                    cout<<"Voulez-vous Supprimer un autre Etudiant ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y');
                     system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Supression D'Etudiant Avec Success", " Suppression", MB_OK|MB_ICONINFORMATION);
        }
        break;



        case 231:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"\n****** Ajout d'un Enseignant ******\n";
                    do{
                    cout<<"Saisit Le Nom : ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom : ";
                    cin>>aut;
                    cout<<"Saisit La Cin : ";
                    cin>>stock;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
                    cout<<"Saisit L'Age : ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.ajout_ens(tit,aut,stock,code);
                    do{
                    cout<<"Voulez-vous ajouter un autre Enseignant ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 


         system("pause");
        ShowWindow(hwnd, SW_NORMAL);
        system("cls");
        MessageBox(hwnd, "Ajout D'Enseignant' Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
           
        }break;



        case 232:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);

         cout<<"\n****** Recherche Enseignant par Nom ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le prenom: ";
                    cin>>aut;
                    b.rech_ens_nom(tit,aut);




         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
           
        }break;



        case 233:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);

        
        cout<<"#############################################################";
        cout<<"\n      ****** Recherche Enseignant par CIN ******\n";   
        cout<<"#############################################################\n";
                    cout<<"Saisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.rech_ens_cin(code);


system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        }break;



        case 234:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);

 cout<<"\n****** Modifier CIN d'un Enseignant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit La Nouvelle  Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_ens_cin(tit,aut,code);
        system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Modification du CIN Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }break;



        case 235:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
    cout<<"\n****** Modifier AGE d'un Enseignant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit Le Nouveau Age: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_ens_age(tit,aut,code);



        system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Modification d'AGE Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }break;



        case 236:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);

        cout<<"\n****** Supression d'un Enseignant ******\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>aut;
                    b.supp_enseignant(tit,aut);
                    do{
                    cout<<"Voulez-vous Supprimer un autre Enseignant ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y');

        system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Supression  D'Enseignant Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }break;



        case 31:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout << "#############################################################";
        cout<<"\n          ****** La Liste Des Livres ******\n";
        cout << "#############################################################\n";
                    b.affiche_liv();

        system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        }break;



        case 32:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout << "#############################################################\n";
        cout<<"\n           ****** La Liste Des Etudiants ******\n";
        cout << "\n#############################################################\n";
                b.affiche_etu();

         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        cout << "\n#############################################################\n";
           
        }break;



        case 33:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout << "\n#############################################################\n";
        cout<<"\n          ****** La Liste Des Enseignants ******\n";
        cout << "\n#############################################################\n";
                    b.affiche_ens();


         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        cout << "\n#############################################################\n";
           
        }break;



        case 34:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargeretu==0||chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        cout << "#############################################################";
        cout<<"\n      ****** Les Livre emprunte par un Etudiant ******\n";
        cout << "#############################################################\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>tit;

                    b.affiche_printed_livre_etud(nom,tit);
        cout << "\n#############################################################\n";

         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");

            
        }break;



        case 35:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0||chargerliv==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
            cout << "#############################################################";
            cout<<"\n     ****** Les Livre emprunte par un Enseignant ******\n";
            cout << "#############################################################\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>tit;

                    b.affiche_printed_livre_ens(nom,tit);
            cout << "\n#############################################################\n";


            system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");

        }break;



        case 36:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens==0||chargerliv==0||chargeretu==0)
        {
             MessageBox(hwnd, "Chargement Des Donnes Necessaire ", "Attention", MB_OK | MB_ICONHAND);
        }
        else{
        system("cls");
        system("color 4F");
        //system("color 9F");
        ShowWindow(hwnd, SW_HIDE);
        cout<<"#############################################################";
        cout<<"\n     ****** Les Statistiques De la Bibliotheque ******\n";
        cout<<"#############################################################";
                b.statistique();
        cout<<"\n#############################################################\n";

         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
        }break;


        case 41:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        
        cout<<"#############################################################";   
        cout<<"\n        ****** Etudiant Emprunte un Livre ******\n"; 
        cout<<"#############################################################\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    cout<<"\nSaisit Le Titre: ";
                    cin>>tit;
                    cout<<"\nSaisit L'Auteur: ";
                    cin>>aut;
                    b.print_livre_etud(nom,code,tit,aut);
                    do{
                    cout<<nom<<" Voulez-vous Emprunte un autre livre ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 

            system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Operaion effectue Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
        }break;



        case 42:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
        system("cls");
        //system("color 9F");
        system("color 4F");
        ShowWindow(hwnd, SW_HIDE);
        
        cout<<"#############################################################";
        cout<<"\n       ****** Enseignant Emprunte un Livre ******\n";        
        cout<<"#############################################################\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    cout<<"\nSaisit Le Titre: ";
                    cin>>tit;
                    cout<<"\nSaisit L'Auteur: ";
                    cin>>aut;
                    b.print_livre_ens(nom,code,tit,aut);
                    do{
                    cout<<nom <<" Voulez-vous Emprunte un autre livre ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 

         system("pause");
                ShowWindow(hwnd, SW_NORMAL);
                system("cls");
                MessageBox(hwnd, "Operation effectue  Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
           
        }break;


        case 51:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
            b.Chargement_livre();

        chargerliv++;

            MessageBox(hwnd, "Chargement effeectue Avec Success", "Chargement", MB_OK|MB_ICONINFORMATION);
           
        }break;



        case 52:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
                    b.Chargement_etudiant();
                    chargeretu++;
                    MessageBox(hwnd, "Chargement effeectue Avec Success", "Chargement", MB_OK|MB_ICONINFORMATION);  
        }break;
        case 53:
        if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
                b.Chargement_enseignant();
                chargerens++;
                MessageBox(hwnd, "Chargement effeectue Avec Success", "Chargement", MB_OK|MB_ICONINFORMATION); 
        }break;
            case 54:
            if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
                b.enregistrement_livre();
                enreliv++;
                MessageBox(hwnd, "Enregistrement effeectue Avec Success", "Enregistrement", MB_OK|MB_ICONINFORMATION);
        }break;
            case 55:
            if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{
            b.enregistrement_etudiant();
            enreetu++;
            MessageBox(hwnd, "Enregistrement effeectue Avec Success", "Enregistrement", MB_OK|MB_ICONINFORMATION);
        }break;
            case 56:
            if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else{

                b.enregistrement_enseignant();
                enreens++;
                MessageBox(hwnd, "Enregistrement effeectue Avec Success", "Enregistrement", MB_OK|MB_ICONINFORMATION);
        }
        break;
        case 57:
            if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(enreens!=0&&enreliv!=0&&enreetu!=0)
        {
            MessageBox(hwnd, "Les Donnes Sont deja Enregistres !", "Enregistrement", MB_OK|MB_ICONINFORMATION);
        }
        else{

                b.enregistrement_etudiant();
                b.enregistrement_enseignant();
                b.enregistrement_livre();
                enreens++;
                enreliv++;
                enreetu++;
                MessageBox(hwnd, "Enregistrement effeectue Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
            }
        break;
        case 58:
            if(verif==0)
                {MessageBox(hwnd, "Cree La Bibliotheque !", " Attention ", MB_OK|MB_ICONHAND);}
        else if(chargerens!=0&&chargeretu!=0&&chargerliv!=0)
        {
            MessageBox(hwnd, "Les Donnes Sont deja Charges !", " Ajout", MB_OK|MB_ICONINFORMATION);

        }
        else{
                b.Chargement_enseignant();
                b.Chargement_etudiant();
                b.Chargement_livre();
                chargerens++;
                chargeretu++;
                chargerliv++;
                MessageBox(hwnd, "Chargement effeectue Avec Success", " Ajout", MB_OK|MB_ICONINFORMATION);
            }
        break;
        case 10:
        
            if(enreens==0||enreetu==0||enreliv==0)
                MessageBox(hwnd, "Enregistrez Vos Donnes ", " Warning", MB_OK|MB_ICONINFORMATION);
            else
                exit(EXIT_SUCCESS);      
            break; 
        case 99:
            ShellExecute(NULL, "open", "CV_Kais.JPG", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 199:
            ShellExecute(NULL, "open", "biblio.JPG", NULL, NULL, SW_SHOWNORMAL);
            break;
    }
    case WM_CREATE:
        addmenus(hwnd);

        //CreateBtt(hwnd) ;
        /*****************ajouter fond **********************/

        bitmap = (HBITMAP)LoadImage(NULL,"Background.bmp",IMAGE_BITMAP, 1530, 840,LR_LOADFROMFILE);
        //return 0;

        break;
    

    case WM_PAINT:
        PAINTSTRUCT ps;
        hdc = BeginPaint(hwnd, &ps);
        DrawState(hdc, NULL, NULL,(LPARAM)bitmap, 0, 0, 0, 0, 0, DST_BITMAP);
        
        EndPaint(hwnd, &ps);
        return 0;
    break;


    break;

    case WM_DESTROY:
        PostQuitMessage(0); /* send a WM_QUIT to the message queue */
        break;
    default: /* for messages that we don't deal with */
        return DefWindowProc(hwnd, message, wParam, lParam);
        
    
    }
    return 0;

}      





void addmenus(HWND hwnd)
{
    hmenu = CreateMenu();
    HMENU htp1 = CreateMenu();
    HMENU hex1 = CreateMenu();
    HMENU htp2 = CreateMenu();
    HMENU hex2_1 = CreateMenu();
    HMENU hex2_2 = CreateMenu();
    HMENU hex2_3 = CreateMenu();
    HMENU htp3 = CreateMenu();
    HMENU htp4 = CreateMenu();
    HMENU htp5 = CreateMenu();
    HMENU htp6 = CreateMenu();
    HMENU hex6_1 = CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"cr�ation du repertoire");
    /*******************************************************/
    AppendMenu(hmenu, MF_STRING, 1, " Creation du Bibliotheque ");

    /***************************************************************/

    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)htp2, " Mise a jour de La Bibliotheque ");

    AppendMenu(htp2, MF_POPUP, (UINT_PTR)hex2_1, "Bibliotheque Des Livres");
    AppendMenu(hex2_1, MF_STRING, 211, "Ajout Un Livre"); /*Sous partie de l'ex2*/
    AppendMenu(hex2_1, MF_STRING, 212, "Modifier Le Code D'un Livre");
    AppendMenu(hex2_1, MF_STRING, 213, "Supprimer Un livre");


    AppendMenu(htp2, MF_POPUP, (UINT_PTR)hex2_2, "Bibliotheque Des Etudiants");
    AppendMenu(hex2_2, MF_STRING, 221, "Ajout d'un Etudiant"); /*Sous partie de l'ex2*/
    AppendMenu(hex2_2, MF_STRING, 222, "Recherche D'un Etudiant par Nom");
    AppendMenu(hex2_2, MF_STRING, 223, "Recherche D'un Etudiant par Cin");
    AppendMenu(hex2_2, MF_STRING, 224, "Modifier la CIN dun Etudiant");
    AppendMenu(hex2_2, MF_STRING, 225, "Modifier L'age d'un Etudiant");
    AppendMenu(hex2_2, MF_STRING, 226, "Supprimer un Etudiant");

    AppendMenu(htp2, MF_POPUP, (UINT_PTR)hex2_3, "Bibliotheque Des Enseignants");
     AppendMenu(hex2_3, MF_STRING, 231, "Ajout d'un Enseignant"); /*Sous partie de l'ex2*/
    AppendMenu(hex2_3, MF_STRING, 232, "Recherche D'un Enseignant par Nom");
    AppendMenu(hex2_3, MF_STRING, 233, "Recherche D'un Enseignant par Cin");
    AppendMenu(hex2_3, MF_STRING, 234, "Modifier La CIN dun Enseignant");
    AppendMenu(hex2_3, MF_STRING, 235, "Modifier L'age d'un Enseignant");
    AppendMenu(hex2_3, MF_STRING, 236, "Supprimer un Enseignant");
    /***************************************************************/
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)htp3, " Affichage ");

    AppendMenu(htp3, MF_STRING, 31, "Afficher La Liste Des Livres");
    AppendMenu(htp3, MF_STRING, 32, "Afficher La Liste Des Etudiants");
    AppendMenu(htp3, MF_STRING, 33, "Afficher La Liste Des Enseignants");
    AppendMenu(htp3, MF_STRING, 34, "Afficher La Liste Des Livre Emprunte par un Etudiant");
    AppendMenu(htp3, MF_STRING, 35, "Afficher La Liste Des Livre Emprunte par un Enseignant");
    AppendMenu(htp3, MF_STRING, 36, "Afficher Les Statistiques");


    /***************************************************************/
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)htp4, "Action ");

    AppendMenu(htp4, MF_STRING, 41, "Etudiant Emprunte Un Livre");
    AppendMenu(htp4, MF_STRING, 42, "Enseignant Emprunte Un Livre");

    /***************************************************************/
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)htp5, " Enregistrement Et Chargement ");

    AppendMenu(htp5, MF_STRING, 51, "Chargement Des Livres");
    AppendMenu(htp5, MF_STRING, 52, "Chargement Des Etudiants");
    AppendMenu(htp5, MF_STRING, 53, "Chargement Des Enseignants");
    AppendMenu(htp5, MF_STRING, 54, "Enregistrement Des Livres");
    AppendMenu(htp5, MF_STRING, 55, "Enregistrement Des Etudiants");
    AppendMenu(htp5, MF_STRING, 56, "Enregistrement Des Enseignants");
    AppendMenu(htp5, MF_STRING, 57, "Enregistrer tout les Donnees");
    AppendMenu(htp5, MF_STRING, 58, "Charger tout les Donnees");

    /***************************************************************/

    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)htp6, " Plus ");
    AppendMenu(htp6, MF_STRING, 99, "CV Founder");
    AppendMenu(htp6, MF_STRING, 199, "Image");
    
    /***************************************************************/
    AppendMenu(hmenu, MF_STRING, 10, "Quitter");
    SetMenu(hwnd, hmenu);
}























































































































/* do
    { 
    cout<<"\n********* Gestion De Bibliotheque *********\n\n";

        cout<<"-1- Creation du Bibliotheque.\n";
        cout<<"-2- Ajout d'un Livre.\n";
        cout<<"-3- Ajout d'un Etudiant.\n";
        cout<<"-4- Ajout d'un Enseignant.\n";
        cout<<"-5- Recherche d'Etudiant base sur Nom.\n";
        cout<<"-6- Recherche d'Etudiant base sur Cin.\n";
        cout<<"-7- Recherche d'Enseignant base sur Nom.\n";
        cout<<"-8- Recherche d'Enseignant base sur Cin.\n";
        cout<<"-9- Recherche d'un Livre base sur Nom.\n";
        cout<<"-10- Modifier La Cin d'un Etudiant.\n";
        cout<<"-11- Modifier L'age d'un Etudiant.\n";
        cout<<"-12- Modifier La Cin d'un Enseignant.\n";
        cout<<"-13- Modifier L'age d'un Enseignant.\n";
        cout<<"-14- Modifier Le Code d'un Livre.\n";
        cout<<"-15- Supression d'un Livre.\n";
        cout<<"-16- Supression d'un Etudiant.\n";
        cout<<"-17- Supression d'un Enseignant.\n";
        cout<<"-18- Afficher La liste des Etudiants.\n";
        cout<<"-19- Afficher La liste des Enseignants.\n";
        cout<<"-20- Afficher La liste des Livres.\n";
        cout<<"-21- Etudiant Emprunte un livre.\n";
        cout<<"-22- Enseignant Emprunte un livre.\n";
        cout<<"-23- Afficher les livres emprunte par un etudiant.\n";
        cout<<"-24- Afficher les livres emprunte par un enseignant.\n";
        cout<<"-25- Afficher Les Statistiques de la Bibliotheque.\n";
        cout<<"-26- Enregistrement Des Livre.\n";
        cout<<"-27- Enregistrement Des Etudiants.\n";
        cout<<"-28- Enregistrement Des Enseignant.\n";
        cout<<"-29- Chargement Des Livre.\n";
        cout<<"-30- Chargement Des Etudiants.\n";
        cout<<"-31- Chargement Des Enseignant.\n";
        cout<<"-32- Quitter.\n";
   
        cout<<"Saisit Votre Choix : ";
        scanf("%d",&choix);

        switch (choix)
        {   
            case 1 :
                if(verif!=0)
                cout<<"La Bibliotheque est Deja cree.\n";
            else
                {
                    system("CLS");
                    verif++;
                    cout<<"La Bibliotheque est Creer avec succes !\n";
                }
            break;

            case 2 :
                system("CLS");
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else 
                {
                    FILE *f=fopen("livre.csv","r");
                    fseek(f,0,SEEK_END);  
                    long lfile=ftell(f);   //longueur du fichier  
                    if(lfile!=0&&chargerliv==0)
                        {
                            cout<<"Le Repertoire Des Livres Contient Des Donnes Priere de les Charger !\n";
                        }
                    else{
                    cout<<"\n****** Ajout d'un Livre ******\n";
                    do{
                    cout<<"Saisit Le Titre : ";
                    cin>>tit;
                    cout<<"Saisit L'auteur : ";
                    cin>>aut;
                    cout<<"Saisit Le Code : ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    cout<<"Saisit Le Stock : ";
                    cin>>stock;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
                    b.ajout_liv(tit,aut,code,stock);
                    do{
                    cout<<"Voulez-vous ajouter un autre livre ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y');  
                    }
                    fclose(f);
                }
                break;

            case 3: 
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    FILE *f=fopen("etudiant.csv","r");
                    fseek(f,0,SEEK_END);  
                    long lfile=ftell(f);   //longueur du fichier  
                    if(lfile!=0&&chargeretu==0)
                        {
                            cout<<"Le Repertoire Des Etudiants Contient Des Donnes Priere de les Charger !\n";
                        }
                    else{
                    cout<<"\n****** Ajout d'un Etudiant ******\n";
                    do{
                    cout<<"Saisit Le Nom : ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom : ";
                    cin>>aut;
                    cout<<"Saisit La Cin : ";
                    cin>>stock;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
                    cout<<"Saisit L'Age : ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.ajout_etud(tit,aut,stock,code);
                    do{
                    cout<<"Voulez-vous ajouter un autre Etudiant ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                    }
                    fclose(f);
                }
                break;
            case 4:

                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    FILE *f=fopen("enseignant.csv","r");
                    fseek(f,0,SEEK_END);  
                    long lfile=ftell(f);   //longueur du fichier  
                    if(lfile!=0&&chargerens==0)
                        {
                            cout<<"Le Repertoire Des Enseignants Contient Des Donnes Priere de les Charger !\n";
                        }
                    else{
                    cout<<"\n****** Ajout d'un Enseignant ******\n";
                    do{
                    cout<<"Saisit Le Nom : ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom : ";
                    cin>>aut;
                    cout<<"Saisit La Cin : ";
                    cin>>stock;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> stock;
                        }
                    cout<<"Saisit L'Age : ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.ajout_ens(tit,aut,stock,code);
                    do{
                    cout<<"Voulez-vous ajouter un autre Enseignant ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                    }
                    fclose(f);
                }
                break;

            case 5:
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Recherche Etudiant par Nom ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le prenom: ";
                    cin>>aut;
                    b.rech_etud_nom(tit,aut);
                }
                break;
            case 6:
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Recherche Etudiant par CIN ******\n";
                    cout<<"Saisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.rech_etud_cin(code);
                }
                break;
            case 7:
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Recherche Enseignant par Nom ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le prenom: ";
                    cin>>aut;
                    b.rech_ens_nom(tit,aut);
                }
                break;
            case 8:
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Recherche Enseignant par CIN ******\n";
                    cout<<"Saisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.rech_ens_cin(code);
                }
                break;
            case 9:
                if(verif==0)
                {
                    cout<<"Cree La Bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Recherche Livre par Titre ******\n";
                    cout<<"Saisit Le Titre: ";
                    cin>>tit;
                    cout<<"Saisit L'Auteur: ";
                    cin>>aut;
                    b.rech_livre_nom(tit,aut);
                }
                break;
            case 10:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Modifier CIN d'un Etudiant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit La Nouvelle  Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_etud_cin(tit,aut,code);
                    cout<<"La Cin de "<<tit<<" Est Bien Modifie.\n";
                }
                break;
            case 11:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Modifier AGE d'un Etudiant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit Le Nouveau Age: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_etud_age(tit,aut,code);
                }
                break;
            case 12:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Modifier CIN d'un Enseignant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit La Nouvelle  Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_ens_cin(tit,aut,code);
                }
                break;
            case 13:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Modifier AGE d'un Enseignant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"Saisit Le Prenom: ";
                    cin>>aut;
                    cout<<"Saisit Le Nouveau Age: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_ens_age(tit,aut,code);
                }
                break;
            case 14:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Modifier CODE d'un Livre ******\n";
                    cout<<"Saisit Le Titre: ";
                    cin>>tit;
                    cout<<"Saisit L'Auteur: ";
                    cin>>aut;
                    cout<<"Saisit Le nouveau Code: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    b.modif_livre_code(tit,aut,code);
                }
                break;
            
            case 15:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    if(b.lnow!=0)
                    {cout<<"\n****** Supression d'un Livre ******\n";
                    do{
                    cout<<"Saisit Le Titre: ";
                    cin>>tit;
                    cout<<"Saisit L'Auteur: ";
                    cin>>aut;
                    b.supp_livre(tit,aut);
                    do{
                    cout<<"Voulez-vous Supprimer un autre livre ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); }
                    else
                        cout<<"La bibliotheque des Livre est Vide!\n";
                }
                break;
            case 16:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    if(b.enow!=0)
                   { cout<<"\n****** Supression d'un Etudiant ******\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>aut;
                    b.supp_etudiant(tit,aut);
                    do{
                    cout<<"Voulez-vous Supprimer un autre Etudiant ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y');}
                    else
                        cout<<"La Bibliotheque des Etudiants est Vide.\n";
                }
                break;
            case 17:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    if(b.ensnow!=0)
                    {cout<<"\n****** Supression d'un Enseignant ******\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>tit;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>aut;
                    b.supp_enseignant(tit,aut);
                    do{
                    cout<<"Voulez-vous Supprimer un autre Enseignant ? (Y/N) : \n";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y');}
                    else
                        cout<<"La Bibliotheque des Enseignants est Vide.\n";


                }
                break;
            case 18:
            if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                system("CLS");    
                cout<<"\n****** La Liste Des Etudiants ******\n";
                b.affiche_etu();
                }
                break;
            case 19:
            if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** La Liste Des Enseignants ******\n";
                    b.affiche_ens();
                }
                 break;
            case 20:
            if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** La Liste Des Livres ******\n";
                    b.affiche_liv();
                }
                break;
                
            case 21:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Etudiant Emprunte un Livre ******\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    cout<<"\nSaisit Le Titre: ";
                    cin>>tit;
                    cout<<"\nSaisit L'Auteur: ";
                    cin>>aut;
                    b.print_livre_etud(nom,code,tit,aut);
                    do{
                    cout<<nom<<" Voulez-vous Emprunte un autre livre ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                }
                break;
            case 22:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Enseignant Emprunte un Livre ******\n";
                    do{
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit La Cin: ";
                    cin>>code;
                    while(cin.fail())
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Input Invalide  ! Reessayez Svp : ";
                        cin >> code;
                        }
                    cout<<"\nSaisit Le Titre: ";
                    cin>>tit;
                    cout<<"\nSaisit L'Auteur: ";
                    cin>>aut;
                    b.print_livre_ens(nom,code,tit,aut);
                    do{
                    cout<<nom <<" Voulez-vous Emprunte un autre livre ? (Y/N) : ";
                    cin>>repet;
                    }while(repet!='Y'&&repet!='N');
                    }while(repet=='Y'); 
                }
                break;
            case 23:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Les Livre emprunte par un Etudiant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>tit;

                    b.affiche_printed_livre_etud(nom,tit);
                }
                break;
            case 24:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    cout<<"\n****** Les Livre emprunte par un Enseignant ******\n";
                    cout<<"Saisit Le Nom: ";
                    cin>>nom;
                    cout<<"\nSaisit Le Prenom: ";
                    cin>>tit;

                    b.affiche_printed_livre_ens(nom,tit);
                }
                break;
            case 25:
            if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                system("CLS");
                cout<<"\n****** Les Statistiques De la Bibliotheque ******\n";
                b.statistique();
                }
                break;
            case 26:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.enregistrement_livre();
                    cout<<"\nEnregistrement Des Livres effectue Avec Success.\n";
                }
                break;
            case 27:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.enregistrement_etudiant();
                    cout<<"\nEnregistrement Des Etudiants effectue Avec Success.\n";
                }
                break;
            case 28:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.enregistrement_enseignant();
                    cout<<"\nEnregistrement Des Enseignants effectue Avec Success.\n";
                }
                break;
            case 29:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.Chargement_livre();
                    chargerliv++;
                    cout<<"\nChargement Des Livres effectue Avec Success.\n";
                }
                break;
            case 30:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.Chargement_etudiant();
                    chargeretu++;
                    cout<<"\nChargement Des Etudiants effectue Avec Success.\n";
                }
                break;
            case 31:
                if(verif==0)
                {
                    cout<<"Cree La bibliotheque !\n";
                }
                else
                {
                    system("CLS");
                    b.Chargement_enseignant();
                    chargerens++;
                    cout<<"\nChargement Des Enseignants effectue Avec Success.\n";
                }
                break;
            case 32:
                    system("CLS");
                    cout<<"Au Revoir !\n";
                    exit(0);  
            default:
                cout<<"Verifie Votre Choix SVP!\n";
            break;
        }
    }while(choix!=32);

    */