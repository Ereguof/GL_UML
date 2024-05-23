// Projet UML

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
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
    string fileAttribut = nomDossier + "/attributes.csv";
    string fileCapteur = nomDossier + "/sensors.csv";
    string fileMesure = nomDossier + "/measures.csv";
    string fileFournisseur = nomDossier + "/providers.csv";
    string filePurificateur = nomDossier + "/cleaners.csv";
    string fileParticuliers = nomDossier + "/users.csv";
    string fileBannis = nomDossier + "/bannis.csv";

    ifstream rFluxAttribut;
    rFluxAttribut.open(fileAttribut);
    if ((rFluxAttribut.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier attributes.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        getline(rFluxAttribut, ligne);
        if (rFluxAttribut)
        {
            int start;
            int end;
            
            end = ligne.find(' ');
            data.ip = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(' ', start);
            data.userNameLog = ligne.substr(start, end-start);

            start = end+1;
            end = ligne.find(' ', start);
            data.nameUser = ligne.substr(start, end-start);

            start = end+2;
            end = start+11;
            data.date = ligne.substr(start, end-start);
        }
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