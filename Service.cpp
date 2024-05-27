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


int Service::qualiteAirZoneCirculaireMoment(double latitude, double longitude, Date jour){

  cout << "Il faut encore implémenter cette fonction(zone moment)" << endl;
  return 0;
}


int Service::constulterNombrePoints(string Id){
    cout << "La fonction constulterNombrePoints n'a pas été implémentéé, elle retourne juste l'id en entrée(nbpoint)" << endl;
    return 0;
}

int Service::qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon){
    cout << "Il faut encore implémenter cette fonction(qualiteair)"<< endl;

    return 0;
}//------------------------------------------------- Surcharge d'opérateurs

int Service::observerImpactPurificateur(string PurificateurId){
  cout << "Il faut encore implémenter cette fonction (observerimpact)"<< endl;

  return 0;

}

int getSubIndex(int value, const std::vector<int>& thresholds) {
    for (int i = 0; i < thresholds.size(); ++i) {
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

int calculeIndiceAtmo(Mesure mesureO2, Mesure mesureSO2, Mesure mesureNO2, Mesure mesurePM10){
      int valeur1 = mesureO2.getValeur();
      int valeur2 = mesureSO2.getValeur();
      int valeur3 = mesureNO2.getValeur();
      int valeur4 = mesurePM10.getValeur();


      vector<int> O3Thresholds = {29, 54, 79, 104, 129, 149, 179, 209, 239};
      vector<int> SO2Thresholds = {39, 79, 119, 159, 199, 249, 299, 399, 499};
      vector<int> NO2Thresholds = {29, 54, 84, 109, 134, 164, 199, 274, 399};
      vector<int> PM10Thresholds = {6, 13, 20, 27, 34, 41, 49, 64, 79};


      int O3Index = getSubIndex(valeur1, O3Thresholds);
      int SO2Index = getSubIndex(valeur2, SO2Thresholds);
      int NO2Index = getSubIndex(valeur3, NO2Thresholds);
      int PM10Index = getSubIndex(valeur4, PM10Thresholds);



      return calculeMax4(O3Index, SO2Index, NO2Index, PM10Index);




}


int Service:: moyenneIndiceAtmo(string CapteurId, Date debut, Date fin){
    int longueur = 0;
    int somme = 0;
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


std::pair<std::vector<int>::iterator, int> insertSorted(std::vector<int>& vec, int value, int length) {
    // Find the insertion point using lower_bound
    auto it = std::lower_bound(vec.begin(), vec.end(), value);

    // Calculate the index of the insertion point
    int index = std::distance(vec.begin(), it);
    cout << "size" <<vec.size();
    if (index > length){
      index = length;
    }
    cout << "value" << value << endl;
    // Insert the value at the correct position
    vec.insert(it, value);

    // Return the iterator to the insertion point and the index
    return {it, index};
}

vector<string> Service :: identifierZoneQualiteSimilaire(string CapteurId, Date debut, Date fin){


    vector<int> listSimilarity;
    vector<string> listRanking;
    int indiceAtmoCapteur = moyenneIndiceAtmo(CapteurId, debut, fin);
    int moyenneCapteurCourant ;
    int length = 0;
    for (vector<Capteur>::iterator it = listeCapteur.begin(); it != listeCapteur.end(); ++it){

        Capteur capteurCourant= *it;

        string capteurCourantId = capteurCourant.getCapteurID();

        if (capteurCourantId != CapteurId){
          int moyenneIndiceAtmoCourant = moyenneIndiceAtmo(capteurCourantId, debut, fin);
          int similarity = abs(moyenneIndiceAtmoCourant - moyenneCapteurCourant);
          listSimilarity.push_back(similarity);
          auto result = insertSorted(listSimilarity, similarity, length);

          listRanking.insert(listRanking.begin() + result.second, capteurCourantId);

          length++;

        }
    }



    return listRanking;
}

int Service::analyserQualiteDonnees(string CapteurId){
    cout << "Il faut encore implémenter cette fonction(qualite donnees)" << endl;
    return 0;
}

int Service::lireDataSet(string nomDossier){

  cout << "Il faut encore implémenter cette fonction(recupererdonnees)"<<endl;


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
  return 0;
}
//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


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
