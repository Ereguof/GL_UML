// Projet UML

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Mesure.h"
#include "Fournisseur.h"
#include "Utilisateur.h"
#include "Capteur.h"
#include "Attribut.h"


typedef struct
{
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;

} Date;

list < Attribut > listeAttributs;

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
        getline(rFluxAttribut, ligne);
        if (rFluxAttribut)
        {
            int start;
            int end;
            
            end = ligne.find(';');
            string attributID = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(';', start);
            string unit = ligne.substr(start, end-start);

            start = end+1;
            end = ligne.find(';', start);
            string description = ligne.substr(start, end-start);

            // cout << "AttributID: " << attributID << " Unit: " << unit << " Description: " << description << endl;
            Attribut attribut(attributID, unit, description);
            listeAttributs.push_back(attribut);
            //cout << "AttributID: " << listeAttributs.front().attributID << " Unit: " << listeAttributs.front().unit << " Description: " << listeAttributs.front().description << endl;
        }
    }
    return 0;
}


int main()
{
    lireDataset("dataset");

    return 0;
}