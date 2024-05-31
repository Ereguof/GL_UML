/*************************************************************************
                           Service  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Service.h"
using namespace std;
#include "main.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Service::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


double distanceLatLong (double lat1, double long1, double lat2, double long2){
    double R = 6371; 
    double dLat = (lat2-lat1) * M_PI / 180;
    double dLon = (long2-long1) * M_PI / 180;
    double a = sin(dLat/2) * sin(dLat/2) +
            cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) *
            sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    return d;
}

int Service::constulterNombrePoints(string Id){
    int res = 0;
    for (vector<Particulier>::iterator it = listeParticulier.begin(); it != listeParticulier.end(); ++it) {
        Particulier particulierCourant = *it;
        if (particulierCourant.getUtilisateurID() == Id) {
            res = particulierCourant.getNbPoints();
        }
    }
    return res;
}

int Service::qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon){
    cout << "Cette fonctionnalité n'est pas implémentée"<< endl;

    return 0;
}

int Service::observerImpactPurificateur(string PurificateurId){
  cout << "Cette fonctionnalité n'est pas implémentée"<< endl;

  return 0;

}

int getSubIndex(int value, const std::vector<double>& thresholds) {
    for (long unsigned int i = 0; i < thresholds.size(); ++i) {
        if (value <= thresholds[i]) {
            return i + 1;
        }
    }
    return thresholds.size() + 1;
}

int calculeMax4(int a, int b, int c, int d){
  int maxVal = a; // Assume the first value is the largest initially

  if (b > maxVal) {
      maxVal = b;
  }
  if (c > maxVal) {
      maxVal = c;
  }
  if (d > maxVal) {
      maxVal = d;
  }

  return maxVal;

}

int calculeIndiceAtmoValeur(double valeurO3, double valeurNO2, double valeurSO2, double valeurPM10){

    vector<double> O3Thresholds = {29, 54, 79, 104, 129, 149, 179, 209, 239};
    vector<double> SO2Thresholds = {39, 79, 119, 159, 199, 249, 299, 399, 499};
    vector<double> NO2Thresholds = {29, 54, 84, 109, 134, 164, 199, 274, 399};
    vector<double> PM10Thresholds = {6, 13, 20, 27, 34, 41, 49, 64, 79};

    int O3Index = getSubIndex(valeurO3, O3Thresholds);
    int NO2Index = getSubIndex(valeurNO2, NO2Thresholds);
    int SO2Index = getSubIndex(valeurSO2, SO2Thresholds);
    int PM10Index = getSubIndex(valeurPM10, PM10Thresholds);

    return calculeMax4(O3Index, SO2Index, NO2Index, PM10Index);
}

int calculeIndiceAtmo(Mesure mesureO2, Mesure mesureNO2, Mesure mesureSO2, Mesure mesurePM10){
      double valeur1 = mesureO2.getValeur();
      double valeur2 = mesureNO2.getValeur();
      double valeur3 = mesureSO2.getValeur();
      double valeur4 = mesurePM10.getValeur();


      vector<double> O3Thresholds = {29, 54, 79, 104, 129, 149, 179, 209, 239};
      vector<double> SO2Thresholds = {39, 79, 119, 159, 199, 249, 299, 399, 499};
      vector<double> NO2Thresholds = {29, 54, 84, 109, 134, 164, 199, 274, 399};
      vector<double> PM10Thresholds = {6, 13, 20, 27, 34, 41, 49, 64, 79};

      int O3Index = getSubIndex(valeur1, O3Thresholds);
      int NO2Index = getSubIndex(valeur2, NO2Thresholds);
      int SO2Index = getSubIndex(valeur3, SO2Thresholds);
      int PM10Index = getSubIndex(valeur4, PM10Thresholds);

      return calculeMax4(O3Index, SO2Index, NO2Index, PM10Index);
}


double Service:: moyenneIndiceAtmo(string CapteurId, Date debut, Date fin){
    double longueur = 0;
    double somme = 0;
    for (vector<Mesure>::iterator it = listeMesure.begin(); it != listeMesure.end(); it += 4) {
      
      Mesure mesureEnCours = *it;
      // une fois qu'on a la mesure, on regarde si c'est le bon capteur et une date valide
      if (mesureEnCours.getCapteurID() == CapteurId){
          //on doit faire les verifs pour les dates
          Date DateEnCours = mesureEnCours.getDate();
          if (debut.annee <= DateEnCours.annee && debut.mois <= DateEnCours.mois && debut.jour <= DateEnCours.jour
          && debut.heure <= DateEnCours.heure && debut.minute <= DateEnCours.minute && debut.seconde <= DateEnCours.seconde){

                if (fin.annee >= DateEnCours.annee && fin.mois >= DateEnCours.mois && fin.jour >= DateEnCours.jour
                && fin.heure >= DateEnCours.heure && fin.minute >= DateEnCours.minute && fin.seconde >= DateEnCours.seconde){

                        auto it2 = it + 1;
                        auto it3 = it2 + 1;
                        auto it4 = it3 + 1;

                        if (it4 < listeMesure.end()) {
                            Mesure mesure2 = *it2;
                            Mesure mesure3 = *it3;
                            Mesure mesure4 = *it4;

                            int indiceAtmo = calculeIndiceAtmo(mesureEnCours, mesure2, mesure3, mesure4);
                            somme += indiceAtmo;
                            longueur++;

                        }

               }
          }
     }
   }
    //cout << "service moyenne" << endl;
    if (longueur != 0)
        return somme/longueur;
    
    return -1;

}


int Service::qualiteAirZoneCirculaireMoment(double latitude, double longitude, Date moment, int rayon){

    double somme_O3 = 0;
    double somme_SO2 = 0;
    double somme_NO2 = 0;
    double somme_PM10 = 0;
    double somme_mesure = 0;

    for (vector<Mesure>::iterator it = listeMesure.begin(); it != listeMesure.end(); it += 4) {
        Mesure mesureEnCours = *it;
        Date dateEnCours = mesureEnCours.getDate();
        string nomCapteurEnCours = mesureEnCours.getCapteurID();
        double latitudeCapteurEnCours = 0;
        double longitudeCapteurEnCours = 0;
        for (vector<Capteur>::iterator it = listeCapteur.begin(); it != listeCapteur.end(); it++) {
            if (it->getCapteurID() == nomCapteurEnCours) {
                latitudeCapteurEnCours = it->getLatitude();
                longitudeCapteurEnCours = it->getLongitude();
            }
        }
        double distance_capteur = distanceLatLong(latitude, longitude, latitudeCapteurEnCours, longitudeCapteurEnCours);

        if (moment.annee == dateEnCours.annee && moment.mois == dateEnCours.mois && moment.jour == dateEnCours.jour && distance_capteur <= rayon) {

            auto it2 = it + 1;
            auto it3 = it2 + 1;
            auto it4 = it3 + 1;

            if (it4 < listeMesure.end()) {
                Mesure mesure2 = *it2;
                Mesure mesure3 = *it3;
                Mesure mesure4 = *it4;

                somme_mesure++;
                somme_O3 += mesureEnCours.getValeur();
                somme_NO2 += mesure2.getValeur();
                somme_SO2 += mesure3.getValeur();
                somme_PM10 += mesure4.getValeur();
            }
        }
    }
    somme_O3 = somme_O3/somme_mesure;
    somme_NO2 = somme_NO2/somme_mesure;
    somme_SO2 = somme_SO2/somme_mesure;
    somme_PM10 = somme_PM10/somme_mesure;

    int indiceAtmo = calculeIndiceAtmoValeur(somme_O3, somme_NO2, somme_SO2, somme_PM10);

    return indiceAtmo;
}

std::pair<std::vector<double>::iterator, int> insertSorted(std::vector<double>& vec, double value, int length) {
    // Find the insertion point using lower_bound
    auto it = std::lower_bound(vec.begin(), vec.end(), value);

    // Calculate the index of the insertion point
    int index = std::distance(vec.begin(), it);
    //cout << "size" <<vec.size();
    if (index > length){
      index = length;
    }
    //cout << "value" << value << endl;
    // Insert the value at the correct position
    vec.insert(it, value);

    // Return the iterator to the insertion point and the index
    return {it, index};
}

vector<Capteur> Service :: identifierZoneQualiteSimilaire(string CapteurId, Date debut, Date fin){


    vector<double> listSimilarity;
    vector<Capteur> listRanking;
    //int indiceAtmoCapteur = moyenneIndiceAtmo(CapteurId, debut, fin);
    double moyenneCapteurCourant = moyenneIndiceAtmo(CapteurId, debut, fin);
    int length = 0;
    for (vector<Capteur>::iterator it = listeCapteur.begin(); it != listeCapteur.end(); ++it){

        Capteur capteurCourant= *it;

        string capteurCourantId = capteurCourant.getCapteurID();

        if (capteurCourantId != CapteurId){
          double moyenneIndiceAtmoCourant = moyenneIndiceAtmo(capteurCourantId, debut, fin);
          double similarity = abs(moyenneIndiceAtmoCourant - moyenneCapteurCourant);
          auto result = insertSorted(listSimilarity, similarity, length);

          listRanking.insert(listRanking.begin() + result.second, capteurCourant);

          length++;

        }
    }

    
    return listRanking;
}

int Service::analyserQualiteDonnees(string CapteurId){
    cout << "Cette fonctionnalité n'est pas implémentée" << endl;
    return 0;
}

int Service::lireDataSet(string nomDossier){

  string fileAttribut = nomDossier + "/attributes.csv";
  string fileCapteur = nomDossier + "/sensors.csv";
  string fileMesure = nomDossier + "/measurements.csv";
  string fileFournisseur = nomDossier + "/providers.csv";
  string filePurificateur = nomDossier + "/cleaners.csv";
  string fileParticulier = nomDossier + "/users.csv";
  string fileBannis = nomDossier + "/bannis.csv";
  string filePoints = nomDossier + "/users_points.csv";

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
                  int endBannis = ligneBannis.find(';');
                  string testUtilisateurID = ligneBannis.substr(0, endBannis);
                  if (testUtilisateurID == utilisateurID)
                  {
                      fiabilite = false;
                  }
              }
          }

        int nbPoints = 0;
        ifstream rfFluxPoints;
        rfFluxPoints.open(filePoints);
        if ((rfFluxPoints.rdstate() & ifstream::failbit) != 0)
        {
            cerr << "Erreur : le fichier users_points.csv ne peut être ouvert, vérifiez sa validité" << endl;
        } else
        {
            string lignePoints;
            while (getline(rfFluxPoints, lignePoints))
            {
                int endPoints = ligne.find(';');
                string testUtilisateurID = lignePoints.substr(0, endPoints);
                if (testUtilisateurID == utilisateurID)
                {
                    int startPoints = endPoints+1;
                    endPoints = lignePoints.find(';', startPoints);
                    nbPoints = stoi(lignePoints.substr(startPoints, endPoints-startPoints));
                }
            }
        }

        Particulier part(utilisateurID, capteurID, fiabilite, nbPoints);
        listeParticulier.push_back(part);
      }
  }

  return 0;
}

vector<Particulier> Service::getListeParticulier(){
    return listeParticulier;
}

vector<Capteur> Service::getListeCapteur(){
    return listeCapteur;
}

vector<Attribut> Service::getListeAttribut(){
    return listeAttribut;
}

vector<Mesure> Service::getListeMesure(){
    return listeMesure;
}

vector<Purificateur> Service::getListePurificateur(){
    return listePurificateur;
}

vector<Fournisseur> Service::getListeFournisseur(){
    return listeFournisseur;
}

void Service::setListeParticulier(vector<Particulier> listeParticulier){
    this->listeParticulier = listeParticulier;
}

void Service::setListeCapteur(vector<Capteur> listeCapteur){
    this->listeCapteur = listeCapteur;
}

void Service::setListeAttribut(vector<Attribut> listeAttribut){
    this->listeAttribut = listeAttribut;
}

void Service::setListeMesure(vector<Mesure> listeMesure){
    this->listeMesure = listeMesure;
}

void Service::setListePurificateur(vector<Purificateur> listePurificateur){
    this->listePurificateur = listePurificateur;
}

void Service::setListeFournisseur(vector<Fournisseur> listeFournisseur){
    this->listeFournisseur = listeFournisseur;
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
// Service::Service ( const Service & unService )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Service>" << endl;
// #endif
// } //----- Fin de Service (constructeur de copie)


Service::Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
