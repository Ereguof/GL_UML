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

list<string> Service :: identifierZoneQualiteSimilaire(string CapteurId){
    cout << "Il faut encore implémenter cette fonction(zone qualite)" << endl;
    std::list <string> stringlist = {"Hello"};

    return stringlist;
}

int Service::analyserQualiteDonnees(string CapteurId){
    cout << "Il faut encore implémenter cette fonction(qualite donnees)" << endl;
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
