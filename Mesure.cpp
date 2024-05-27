/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Mesure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
    string const & Mesure::getCapteurID() const
    {
        return capteurID;
    }

    string const & Mesure::getAttributID() const
    {
        return attributID;
    }

    double Mesure::getValeur() const
    {
        return valeur;
    }

    Date const & Mesure::getDate() const
    {
        return date;
    }

//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure (Date date_, string capteurID_, string attributID_, double valeur_)
{
    this->date = date_;
    this->capteurID = capteurID_;
    this->attributID = attributID_;
    this->valeur = valeur_;
}


Mesure::Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure


Mesure::~Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

