// Projet UML

using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include <Mesure.h>
#include <Fournisseur.h>
#include <Utilisateur.h>
#include <Capteur.h>
#include <Attribut.h>


typedef struct
{
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;

} Date;


int lireDataset(string nomDossier)
{
    string file;
    ifstream rFlux(nomDossier);
    rFlux.open(nomDossier);
    if ((rFlux.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier ne peut être ouvert, vérifiez sa validité" << endl;
    }
}


int main()
{
    Date date;
    date.annee = 2020;
    date.mois = 12;
    date.jour = 31;
    date.heure = 23;
    date.minute = 59;
    date.seconde = 59;

    cout << "Date: " << date.annee << "/" << date.mois << "/" << date.jour << " " << date.heure << ":" << date.minute << ":" << date.seconde << endl;

    return 0;
}