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


int main()
{
    Service * service = new Service( );  
    string nomDossier = "dataset";
    service->lireDataSet(nomDossier);

    bool en_fonctionnement = 1; 
    bool modePrivilegie = 0;
    while (en_fonctionnement)
    {
        char reponse;
        cout << endl << "Liste des commandes" << endl;
        cout << "1 : Consulter le nombre de points d'un utilisateur" << endl;
        cout << "2 : Identifier zones avec qualité de l'air similaire au capteur donné" << endl;
        cout << "3 : Afficher qualité de l'air dans une zone circulaire dans une certaine période (non-implémentée)" << endl;
        cout << "4 : Afficher qualité de l'air dans une zone circulaire à un moment donné" << endl;
        cout << "5 : Observer l'impact des air cleaners (non-implémentée)" << endl;
        cout << "6 : Changer de mode (gouvernement/utilisateur classique)" << endl;
        cout << "7 : Analyser la qualité des données d'un capteur (mode gouvernement seulement) (non-implémentée)" << endl;
        cout << "8 : Quitter l'application " << endl;
        cin >> reponse;
        switch (reponse)
        {
        case '1':{
            string utilisateurID; 
            cout << endl << "Donnez l'ID de l'utilisateur à consulter : " << endl;
            cin >> utilisateurID;
            int nbPoints = service->constulterNombrePoints(utilisateurID);
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

            vector<Capteur> listeResultat = service->identifierZoneQualiteSimilaire(capteurID,debut,fin);
            cout << "Ordre des capteurs obtenus dans l'ordre croissant de similarité : " << endl;
            for (vector<Capteur>::iterator it = listeResultat.begin(); it != listeResultat.end(); ++it){
                    Capteur capteurCourant = *it;
                    cout << capteurCourant.getCapteurID() << "  Latitude :" << capteurCourant.getLatitude() << "  Longitude :" << capteurCourant.getLongitude() << endl;
            }
            cout << endl;
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
            int rayon;
            cout << "Donnez le rayon de la zone circulaire : " << endl << endl;
            cin >> rayon;
            cout << "Indice ATMO sur la zone considérée : " << service->qualiteAirZoneCirculaireMoment(latitude, longitude, moment, rayon) << endl;
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
