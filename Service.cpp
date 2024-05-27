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


int Service::constulterNombrePoints(int Id){
    cout << "La fonction constulterNombrePoints n'a pas été implémentéé, elle retourne juste l'id en entrée(nbpoint)" << endl;
    return Id;
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
    for (vector<Mesure>::iterator it = listeMesure.begin(); it != listeMesure.end(); ++it) {

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

    if (longueur != 0)
        return somme/longueur;
    return -1;

}

vector<string> Service :: identifierZoneQualiteSimilaire(string CapteurId, Date debut, Date fin){
    cout << "Il faut encore implémenter cette fonction(zone qualite)" << endl;

    vector<int> listSimilarity;
    vector<string> listeRanking;
    int moyenne_capteur_courant;

    std::vector <string> stringlist = {"Hello"};

    return stringlist;
}

int Service::analyserQualiteDonnees(string CapteurId){
    cout << "Il faut encore implémenter cette fonction(qualite donnees)" << endl;
    return 0;
}

int Service::lireDataSet(){

  cout << "Il faut encore implémenter cette fonction(recupererdonnees)"<<endl;
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
