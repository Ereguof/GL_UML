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
#include "Particulier.h"
#include "Service.h"


vector < Attribut > listeAttribut;
vector < Capteur > listeCapteur;
vector < Mesure > listeMesure;
vector < Fournisseur > listeFournisseur;
vector < Particulier > listeParticulier;
vector < Purificateur > listePurificateur;


int lireDataset(string nomDossier)
{
    string fileAttribut = nomDossier + "/attributes.csv";
    string fileCapteur = nomDossier + "/sensors.csv";
    string fileMesure = nomDossier + "/measurements.csv";
    string fileFournisseur = nomDossier + "/providers.csv";
    string filePurificateur = nomDossier + "/cleaners.csv";
    string fileParticulier = nomDossier + "/users.csv";
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
            listeCapteur.push_back(cap);
        }
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
    }

    ifstream rfFluxFournisseur;
    rfFluxFournisseur.open(fileFournisseur);
    if ((rfFluxFournisseur.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier providers.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        while (getline(rfFluxFournisseur, ligne))
        {
            int start;
            int end;
            
            end = ligne.find(';');
            string fournisseurID = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(';', start);
            string purificateurID = ligne.substr(start, end-start);

            Fournisseur four(fournisseurID, purificateurID);
            listeFournisseur.push_back(four);
        }
    }

    ifstream rfFluxPurificateur;
    rfFluxPurificateur.open(filePurificateur);
    if ((rfFluxPurificateur.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier cleaners.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        while (getline(rfFluxPurificateur, ligne))
        {
            int start;
            int end;
            
            end = ligne.find(';');
            string purificateurID = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(';', start);
            double latitude = stod(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            double longitude = stod(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find('-',start);
            int anneeStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find('-', start);
            int moisStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(' ', start);
            int jourStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int heureStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int minuteStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            int secondeStart = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find('-',start);
            int anneeStop = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find('-', start);
            int moisStop = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(' ', start);
            int jourStop = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int heureStop = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(':', start);
            int minuteStop = stoi(ligne.substr(start, end-start));

            start = end+1;
            end = ligne.find(';', start);
            int secondeStop = stoi(ligne.substr(start, end-start));

            Date dateStart;
            dateStart.annee = anneeStart;
            dateStart.mois = moisStart;
            dateStart.jour = jourStart;
            dateStart.heure = heureStart;
            dateStart.minute = minuteStart;
            dateStart.seconde = secondeStart;

            Date dateStop;
            dateStop.annee = anneeStop;
            dateStop.mois = moisStop;
            dateStop.jour = jourStop;
            dateStop.heure = heureStop;
            dateStop.minute = minuteStop;
            dateStop.seconde = secondeStop;

            Purificateur pur(purificateurID, latitude, longitude, dateStart, dateStop);
            listePurificateur.push_back(pur);
        }
    }

    ifstream rfFluxParticuliers;
    rfFluxParticuliers.open(fileParticulier);
    if ((rfFluxParticuliers.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur : le fichier users.csv ne peut être ouvert, vérifiez sa validité" << endl;
    } else
    {
        string ligne;
        while (getline(rfFluxParticuliers, ligne))
        {
            int start;
            int end;
            
            end = ligne.find(';');
            string utilisateurID = ligne.substr(0, end);

            start = end+1;
            end = ligne.find(';', start);
            string capteurID = ligne.substr(start, end-start);

            bool fiabilite = true;
            ifstream rfFluxBannis;
            rfFluxBannis.open(fileBannis);
            if ((rfFluxBannis.rdstate() & ifstream::failbit) != 0)
            {
                cerr << "Erreur : le fichier bannis.csv ne peut être ouvert, vérifiez sa validité" << endl;
            } else
            {
                string ligneBannis;
                while (getline(rfFluxBannis, ligneBannis))
                {
                    int end = ligne.find(';');
                    string testUtilisateurID = ligne.substr(0, end);
                    if (testUtilisateurID == utilisateurID)
                    {
                        fiabilite = false;
                    }
                }
            }

            Particulier part(utilisateurID, capteurID, fiabilite);
            listeParticulier.push_back(part);
        }
    }

    return 0;
}


int main()
{
    vector < Attribut > listeAttribut;
    vector < Capteur > listeCapteur;
    vector < Mesure > listeMesure;
    vector < Fournisseur > listeFournisseur;
    vector < Particulier > listeParticulier;
    vector < Purificateur > listePurificateur;

    Service * service = new Service();  
    string nomDossier = "dataset";
    lireDataset(nomDossier);

    bool en_fonctionnement = 1; 
    bool modePrivilegie = 0;
    while (en_fonctionnement)
    {
        char reponse;
        cout << endl << "Liste des commandes" << endl;
        cout << "1 : Consulter le nombre de points d'un utilisateur" << endl;
        cout << "2 : Identifier zones avec qualité de l'air similaire au capteur donné" << endl;
        cout << "3 : Afficher qualité de l'air dans une zone circulaire dans une certaine période" << endl;
        cout << "4 : Afficher qualité de l'air dans une zone circulaire à un moment donné" << endl;
        cout << "5 : Observer l'impact des air cleaners" << endl;
        cout << "6 : Changer de mode (gouvernement/utilisateur classique)" << endl;
        cout << "7 : Analyser la qualité des données d'un capteur (mode gouvernement seulement) " << endl;
        cout << "8 : Quitter l'application " << endl;
        cin >> reponse;
        switch (reponse)
        {
        case '1':{
            string utilisateurID; 
            cout << endl << "Donnez l'ID de l'utilisateur à consulter : " << endl;
            cin >> utilisateurID;
            int nbPoints = 2;//service->constulterNombrePoints(utilisateurID);
            cout << "L'utilisateur " << utilisateurID << " a " << nbPoints << " points" << endl;
            break;
            }
        
        case '2':{
            string capteurID; 
            cout << endl << "Donnez l'ID du capteur considéré : " << endl;
            cin >> capteurID;
            Date debut;
            cout << "Donnez l'année de début : " << endl;
            cin >> debut.annee;
            cout << "Donnez le mois de début : " << endl;
            cin >> debut.mois;
            cout << "Donnez le jour de début : " << endl;
            cin >> debut.jour;
            cout << "Donnez l'heure de début : " << endl;
            cin >> debut.heure;
            cout << "Donnez les minutes de début : " << endl;
            cin >> debut.minute;
            cout << "Donnez les secondes de début : " << endl;
            cin >> debut.seconde;
            Date fin;
            cout << "Donnez l'année de fin : " << endl;
            cin >> fin.annee;
            cout << "Donnez le mois de fin : " << endl;
            cin >> fin.mois;
            cout << "Donnez le jour de fin : " << endl;
            cin >> fin.jour;
            cout << "Donnez l'heure de fin : " << endl;
            cin >> fin.heure;
            cout << "Donnez les minutes de fin : " << endl;
            cin >> fin.minute;
            cout << "Donnez les secondes de fin : " << endl;
            cin >> fin.seconde;
            service->identifierZoneQualiteSimilaire(capteurID,debut,fin);
            break;
            }

        case '3':{
            double latitude; 
            cout << endl << "Donnez une latitude : " << endl;
            cin >> latitude;
            double longitude;
            cout << "Donnez une longitude : " << endl;
            cin >> longitude;
            Date debut;
            cout << "Donnez l'année de début : " << endl;
            cin >> debut.annee;
            cout << "Donnez le mois de début : " << endl;
            cin >> debut.mois;
            cout << "Donnez le jour de début : " << endl;
            cin >> debut.jour;
            cout << "Donnez l'heure de début : " << endl;
            cin >> debut.heure;
            cout << "Donnez les minutes de début : " << endl;
            cin >> debut.minute;
            cout << "Donnez les secondes de début : " << endl;
            cin >> debut.seconde;
            Date fin;
            cout << "Donnez l'année de fin : " << endl;
            cin >> fin.annee;
            cout << "Donnez le mois de fin : " << endl;
            cin >> fin.mois;
            cout << "Donnez le jour de fin : " << endl;
            cin >> fin.jour;
            cout << "Donnez l'heure de fin : " << endl;
            cin >> fin.heure;
            cout << "Donnez les minutes de fin : " << endl;
            cin >> fin.minute;
            cout << "Donnez les secondes de fin : " << endl;
            cin >> fin.seconde;
            int rayon;
            cout << "Donnez le rayon de la zone circulaire : " << endl;
            cin >> rayon;
            service->qualiteAirZoneCirculairePeriode(latitude, longitude, debut, fin, rayon);
            break;
            }

        case '4':{
            double latitude; 
            cout << endl << "Donnez une latitude : " << endl;
            cin >> latitude;
            double longitude;
            cout << "Donnez une longitude : " << endl;
            cin >> longitude;
            Date moment;
            cout << "Donnez l'année du moment : " << endl;
            cin >> moment.annee;
            cout << "Donnez le mois du moment : " << endl;
            cin >> moment.mois;
            cout << "Donnez le jour du moment : " << endl;
            cin >> moment.jour;
            cout << "Donnez l'heure du moment : " << endl;
            cin >> moment.heure;
            cout << "Donnez les minutes du moment : " << endl;
            cin >> moment.minute;
            cout << "Donnez les secondes du moment : " << endl;
            cin >> moment.seconde;
            service->qualiteAirZoneCirculaireMoment(latitude, longitude, moment);
            break; 
            }

        case '5':{
            string purificateurID; 
            cout << endl << "Donnez l'ID du purificateur considéré : " << endl;
            cin >> purificateurID;
            service->observerImpactPurificateur(purificateurID);
            break;
            }

        case '6':{
            if (modePrivilegie == 1)
            {
                modePrivilegie = 0;
                cout << endl << "Mode utilisateur classique activé" << endl;
            } else
            {
                string mdp; 
                cout << endl << "Donnez le mot de passe : " << endl;
                cin >> mdp;
                if (mdp == "mdp")
                {
                    modePrivilegie = 1;
                    cout << endl << "Mode gouvernement activé" << endl;
                } else
                {
                    cout << endl << "Mot de passe incorrect" << endl;
                }
            }
            break;
            }

        case '7':{
            if (modePrivilegie == 0)
            {
                cout << endl << "Vous n'avez pas les droits pour accéder à cette fonctionnalité" << endl; 
            }else{
                string capteurID; 
                cout << endl << "Donnez l'ID du capteur considéré : " << endl;
                cin >> capteurID;
                service->analyserQualiteDonnees(capteurID);
            }
            break;
            }

        case '8':{
            en_fonctionnement = 0;
            break;
            }
        
        default:{
            cout << endl << "Veuillez choisir une option valide." << endl;
            break;
            }
        }
    }
    return 0;
}
