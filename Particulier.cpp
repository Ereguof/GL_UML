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


string const & Particulier::getCapteurID() const
{
    return capteurID;
}

int Particulier::getNbPoints() const
{
    return nbPoints;
}

int Particulier::setNbPoints(int nbPoints_)
{
    this->nbPoints = nbPoints_;
    return nbPoints;
}

bool Particulier::getFiabilite() const
{
    return fiabilite;
}

void Particulier::setCapteurID(const string& newCapteurID){
  capteurID = newCapteurID;
}
//-------------------------------------------- Constructeurs - destructeur


Particulier::Particulier ( string userID_ , string capteurID_, bool fiabilite_, int nbPoints_): Utilisateur(userID_)
// Algorithme :
//
{
    this->capteurID = capteurID_;
    this->fiabilite = fiabilite_;
    this->nbPoints = nbPoints_;
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
