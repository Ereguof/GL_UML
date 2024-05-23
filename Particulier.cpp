/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Particulier.h"
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Particulier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Particulier & Particulier::operator = ( const Particulier & unParticulier )
// Algorithme :
//
{
  return *this;

} //----- Fin de operator =

string const & Particulier::getCapteurID() const
{
    return capteurID;
}

int Particulier::getNbPoints() const
{
    return nbPoints;
}

int Particulier::getFiabilite() const
{
    return fiabilite;
}

void Particulier::setCapteurID(const string& newCapteurID){
  capteurID = newCapteurID;
}
//-------------------------------------------- Constructeurs - destructeur
Particulier::Particulier ( const Particulier & unParticulier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Particulier>" << endl;
#endif
} //----- Fin de Particulier (constructeur de copie)


Particulier::Particulier ( string userID_ , string capteurID_): Utilisateur(userID_)
// Algorithme :
//
{
  capteurID = capteurID_;
#ifdef MAP
    cout << "Appel au constructeur de <Particulier>" << endl;
#endif
} //----- Fin de Particulier


Particulier::~Particulier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier>" << endl;
#endif
} //----- Fin de ~Particulier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
