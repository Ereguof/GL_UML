/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string const & Capteur::getCapteurID() const
{
    return CapteurID;
}

double Capteur::getLatitude() const
{
    return latitude;
}

double Capteur::getLongitude() const
{
    return longitude;
}
//-------------------------------------------- Constructeurs - destructeur

Capteur::Capteur ( string monCapteurID, double maLatitude, double maLongitude)
// Algorithme :
//
{
  CapteurID = monCapteurID;
  latitude = maLatitude;
  longitude = maLongitude;
#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif
} //----- Fin de Capteur


Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
