// Projet UML

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include "Mesure.h"
#include "Fournisseur.h"
#include "Utilisateur.h"
#include "Capteur.h"
#include "Attribut.h"


list < Attribut > listeAttribut;

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

            //cout << "AttributID: " << attributID << " Unit: " << unit << " Description: " << description << endl;
            Attribut att(attributID, unit, description);
            listeAttribut.push_back(att);
            
            for (list<Attribut>::iterator it = listeAttribut.begin(); it != listeAttribut.end(); ++it) {
                cout << "AttributID:" << it->getAttributId() << " Unit:" << it->getUnite() << " Description:" << it->getDescription() << endl;
            }
        }
    }
    return 0;
}


int main()
{
    string nomDossier = "dataset";
    lireDataset(nomDossier);

    return 0;
}