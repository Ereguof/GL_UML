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
#include "Purificateur.h"


list < Attribut > listeAttribut;
list < Capteur > listeCapteur;
list < Mesure > listeMesure;
list < Fournisseur > listeFournisseur;
list < Utilisateur > listeUtilisateur;
list < Purificateur > listePurificateur;

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
        while (getline(rFluxAttribut, ligne))
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

            Attribut att(attributID, unit, description);
            listeAttribut.push_back(att);
        }
        for (list<Attribut>::iterator it = listeAttribut.begin(); it != listeAttribut.end(); ++it) {
            cout << "AttributID:" << it->getAttributId() << " Unit:" << it->getUnite() << " Description:" << it->getDescription() << endl;
        }
    }

    ifstream rfFluxCapteur;
    rfFluxCapteur.open(fileCapteur);
    if ((rfFluxCapteur.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier sensors.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        while (getline(rfFluxCapteur, ligne))
        {
            int start;
            int end;
            
            end = ligne.find(';');
            string capteurID = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(';', start);
            double latitude = stod(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            double longitude = stod(ligne.substr(start, end-start));

            Capteur cap(capteurID, latitude, longitude);
            cout << "CapteurID:" << cap.getCapteurID() << " Latitude:" << cap.getLatitude() << " Longitude:" << cap.getLongitude() << endl;
            listeCapteur.push_back(cap);

            // Capteur premierElement = listeCapteur.front();
            // cout << "CapteurID:" << premierElement.getCapteurID() << " Latitude:" << premierElement.getLatitude() << " Longitude:" << premierElement.getLongitude() << endl;
        }

        for (list<Capteur>::iterator it = listeCapteur.begin(); it != listeCapteur.end(); ++it) {
            cout << "CapteurID:" << it->getCapteurID() << " Latitude:" << it->getLatitude() << " Longitude:" << it->getLongitude() << endl;
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