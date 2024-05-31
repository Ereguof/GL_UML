// Projet UML - main des tests unitaires 

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>
#include <functional>
#include "Mesure.h"
#include "Fournisseur.h"
#include "Utilisateur.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Purificateur.h"
#include "Particulier.h"
#include "Service.h"

int testIdentifierZoneQualiteSimilaire(){

    Date dateDebut;
    dateDebut.annee = 2019;
    dateDebut.mois = 1;
    dateDebut.jour = 1;
    dateDebut.heure = 12;
    dateDebut.minute = 0;
    dateDebut.seconde = 0;

    Date dateFin;
    dateFin.annee = 2019;
    dateFin.mois = 1;
    dateFin.jour = 2;
    dateFin.heure = 12;
    dateFin.minute = 0;
    dateFin.seconde = 0;

    Service * service = new Service( ); 

    vector <Mesure> listeMesures;
    vector <Capteur> listeCapteurs;

    Mesure mes010(dateDebut, "Sensor0", "O3", 80);
    Mesure mes011(dateDebut, "Sensor0", "NO2", 120);
    Mesure mes012(dateDebut, "Sensor0", "S02", 85);
    Mesure mes013(dateDebut, "Sensor0", "PM10", 25);
    listeMesures.push_back(mes010);
    listeMesures.push_back(mes011);
    listeMesures.push_back(mes012);
    listeMesures.push_back(mes013);
    Mesure mes020(dateFin, "Sensor0", "O3", 30);
    Mesure mes021(dateFin, "Sensor0", "NO2", 40);
    Mesure mes022(dateFin, "Sensor0", "S02", 30);
    Mesure mes023(dateFin, "Sensor0", "PM10", 10);
    listeMesures.push_back(mes020);
    listeMesures.push_back(mes021);
    listeMesures.push_back(mes022);
    listeMesures.push_back(mes023);

    Mesure mes110(dateDebut, "Sensor1", "O3", 180);
    Mesure mes111(dateDebut, "Sensor1", "NO2", 300);
    Mesure mes112(dateDebut, "Sensor1", "S02", 200);
    Mesure mes113(dateDebut, "Sensor1", "PM10", 60);
    listeMesures.push_back(mes110);
    listeMesures.push_back(mes111);
    listeMesures.push_back(mes112);
    listeMesures.push_back(mes113);
    Mesure mes120(dateFin, "Sensor1", "O3", 150);
    Mesure mes121(dateFin, "Sensor1", "NO2", 250);
    Mesure mes122(dateFin, "Sensor1", "S02", 165);
    Mesure mes123(dateFin, "Sensor1", "PM10", 45);
    listeMesures.push_back(mes120);
    listeMesures.push_back(mes121);
    listeMesures.push_back(mes122);
    listeMesures.push_back(mes123);

    Mesure mes210(dateDebut, "Sensor2", "O3", 80);
    Mesure mes211(dateDebut, "Sensor2", "NO2", 120);
    Mesure mes212(dateDebut, "Sensor2", "S02", 85);
    Mesure mes213(dateDebut, "Sensor2", "PM10", 25);
    listeMesures.push_back(mes210);
    listeMesures.push_back(mes211);
    listeMesures.push_back(mes212);
    listeMesures.push_back(mes213);
    Mesure mes220(dateFin, "Sensor2", "O3", 1);
    Mesure mes221(dateFin, "Sensor2", "NO2", 1);
    Mesure mes222(dateFin, "Sensor2", "S02", 1);
    Mesure mes223(dateFin, "Sensor2", "PM10", 1);
    listeMesures.push_back(mes220);
    listeMesures.push_back(mes221);
    listeMesures.push_back(mes222);
    listeMesures.push_back(mes223);

    Mesure mes310(dateDebut, "Sensor3", "O3", 105);
    Mesure mes311(dateDebut, "Sensor3", "NO2", 160);
    Mesure mes312(dateDebut, "Sensor3", "S02", 110);
    Mesure mes313(dateDebut, "Sensor3", "PM10", 30);
    listeMesures.push_back(mes310);
    listeMesures.push_back(mes311);
    listeMesures.push_back(mes312);
    listeMesures.push_back(mes313);
    Mesure mes320(dateFin, "Sensor3", "O3", 130);
    Mesure mes321(dateFin, "Sensor3", "NO2", 200);
    Mesure mes322(dateFin, "Sensor3", "S02", 135);
    Mesure mes323(dateFin, "Sensor3", "PM10", 36);
    listeMesures.push_back(mes320);
    listeMesures.push_back(mes321);
    listeMesures.push_back(mes322);
    listeMesures.push_back(mes323);

    service->setListeMesure(listeMesures);

    Capteur cap0("Sensor0", 1.0, 1.0);
    Capteur cap1("Sensor1", 1.0, 1.0);
    Capteur cap2("Sensor2", 1.0, 1.0);
    Capteur cap3("Sensor3", 1.0, 1.0);
    listeCapteurs.push_back(cap0);
    listeCapteurs.push_back(cap1);
    listeCapteurs.push_back(cap2);
    listeCapteurs.push_back(cap3);

    service->setListeCapteur(listeCapteurs);

    vector<Capteur> listeResultat = service->identifierZoneQualiteSimilaire("Sensor0", dateDebut, dateFin);

    cout << "Test identifierZoneQualiteSimilaire" << endl;
    cout << "Ordre des capteurs voulus : Sensor2 -> Sensor3 -> Sensor1" << endl;
    cout << "Ordre des capteurs obtenus : " << endl;
    for (vector<Capteur>::iterator it = listeResultat.begin(); it != listeResultat.end(); ++it){
        Capteur capteurCourant = *it;
        cout << capteurCourant.getCapteurID() << "  Latitude :" << capteurCourant.getLatitude() << "  Longitude :" << capteurCourant.getLongitude() << endl;
    }
    return 0;
}

int testQualiteAirZoneCirculaireMoment(){

    Date dateDebut;
    dateDebut.annee = 2019;
    dateDebut.mois = 1;
    dateDebut.jour = 1;
    dateDebut.heure = 12;
    dateDebut.minute = 0;
    dateDebut.seconde = 0;

    Date dateFin;
    dateFin.annee = 2019;
    dateFin.mois = 1;
    dateFin.jour = 2;
    dateFin.heure = 12;
    dateFin.minute = 0;
    dateFin.seconde = 0;

    Service * service = new Service( ); 

    vector <Mesure> listeMesures;
    vector <Capteur> listeCapteurs;

    Mesure mes010(dateDebut, "Sensor0", "O3", 50.25);
    Mesure mes011(dateDebut, "Sensor0", "NO2", 74.5);
    Mesure mes012(dateDebut, "Sensor0", "S02", 41.5);
    Mesure mes013(dateDebut, "Sensor0", "PM10", 44.75);
    listeMesures.push_back(mes010);
    listeMesures.push_back(mes011);
    listeMesures.push_back(mes012);
    listeMesures.push_back(mes013);
    Mesure mes020(dateFin, "Sensor0", "O3", 50.5);
    Mesure mes021(dateFin, "Sensor0", "NO2", 72);
    Mesure mes022(dateFin, "Sensor0", "S02", 39.25);
    Mesure mes023(dateFin, "Sensor0", "PM10", 50.5);
    listeMesures.push_back(mes020);
    listeMesures.push_back(mes021);
    listeMesures.push_back(mes022);
    listeMesures.push_back(mes023);

    Mesure mes110(dateDebut, "Sensor1", "O3", 63.04);
    Mesure mes111(dateDebut, "Sensor1", "NO2", 61.92);
    Mesure mes112(dateDebut, "Sensor1", "S02", 34.42);
    Mesure mes113(dateDebut, "Sensor1", "PM10", 51.12);
    listeMesures.push_back(mes110);
    listeMesures.push_back(mes111);
    listeMesures.push_back(mes112);
    listeMesures.push_back(mes113);
    Mesure mes120(dateFin, "Sensor1", "O3", 65.08);
    Mesure mes121(dateFin, "Sensor1", "NO2", 60.33);
    Mesure mes122(dateFin, "Sensor1", "S02", 32.88);
    Mesure mes123(dateFin, "Sensor1", "PM10", 54.58);
    listeMesures.push_back(mes120);
    listeMesures.push_back(mes121);
    listeMesures.push_back(mes122);
    listeMesures.push_back(mes123);

    service->setListeMesure(listeMesures);

    Capteur cap0("Sensor0", 44.0, -1.0);
    Capteur cap1("Sensor1", 44.0, -0.3);
    listeCapteurs.push_back(cap0);
    listeCapteurs.push_back(cap1);

    service->setListeCapteur(listeCapteurs);

    int indiceAtmoFinale = service->qualiteAirZoneCirculaireMoment(44.0, -0.5, dateDebut, 150);

    cout << "Test qualiteAirZoneCirculaireMoment" << endl;
    cout << "Indice atmo voulu : 7" << endl;
    cout << "Indice atmo obtenu : " << indiceAtmoFinale << endl;
 
    return 0;
}

template <typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now(); 
    func();
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> duration = end - start; 
    return duration.count();
}

int main()
{
    cout << endl << "Test des deux fonctions majeures implémentées : identifierZoneQualiteSimilaire et qualiteAirZoneCirculaireMoment" << endl << endl;

    double timeTaken = measureTime(testIdentifierZoneQualiteSimilaire);
    cout << "Temps d'éxécution de identifierZoneQualiteSimilaire: " << timeTaken << " secondes" << endl << endl;

    double timeTaken2 = measureTime(testQualiteAirZoneCirculaireMoment);
    cout << "Temps d'éxécution de testQualiteAirZoneCirculaireMoment: " << timeTaken2 << " secondes" << endl << endl;

    return 0;
}
