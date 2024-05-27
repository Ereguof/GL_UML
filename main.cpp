// Projet UML

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Mesure.h"
#include "Fournisseur.h"
#include "Utilisateur.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Purificateur.h"


vector < Attribut > listeAttribut;
vector < Capteur > listeCapteur;
vector < Mesure > listeMesure;
vector < Fournisseur > listeFournisseur;
vector < Utilisateur > listeUtilisateur;
vector < Purificateur > listePurificateur;

int lireDataset(string nomDossier)
{
    string fileAttribut = nomDossier + "/attributes.csv";
    string fileCapteur = nomDossier + "/sensors.csv";
    string fileMesure = nomDossier + "/measurements.csv";
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
        // for (vector<Attribut>::iterator it = listeAttribut.begin(); it != listeAttribut.end(); ++it) {
        //     cout << "AttributID:" << it->getAttributId() << " Unit:" << it->getUnite() << " Description:" << it->getDescription() << endl;
        // }
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

        // for (vector<Capteur>::iterator it = listeCapteur.begin(); it != listeCapteur.end(); ++it) {
        //     cout << "CapteurID:" << it->getCapteurID() << " Latitude:" << it->getLatitude() << " Longitude:" << it->getLongitude() << endl;
        // }
    }

    ifstream rfFluxMesure;
    rfFluxMesure.open(fileMesure);
    if ((rfFluxMesure.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier measurements.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        while (getline(rfFluxMesure, ligne))
        {
            int start;
            int end;
            
            end = ligne.find('-');
            int annee = stoi(ligne.substr(0, end));

            start = end+1;
            end = ligne.find('-', start);
            int mois = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(' ', start);
            int jour = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int heure = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int minute = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            int seconde = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            string capteurID = ligne.substr(start, end-start);

            start = end+1;
            end = ligne.find(';', start);
            string attributID = ligne.substr(start, end-start);

            start = end+1;
            end = ligne.find(';', start);
            double valeur = stod(ligne.substr(start, end-start));
            
            Date date;
            date.annee = annee;
            date.mois = mois;
            date.jour = jour;
            date.heure = heure;
            date.minute = minute;
            date.seconde = seconde;

            Mesure mes(date, capteurID, attributID, valeur);
            listeMesure.push_back(mes);
        }
        for (vector<Mesure>::iterator it = listeMesure.begin(); it != listeMesure.end(); ++it) {
            cout << "date:" << it->getDate().jour << " CapteurID:" << it->getCapteurID() << " AttributID:" << it->getAttributID() << " Valeur:" << it->getValeur() << endl;
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