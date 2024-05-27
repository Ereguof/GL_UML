/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "Fournisseur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Fournisseur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Fournisseur::passerEnModePrivilegie (string motDePasse) const
{
    return true;
}

string const & Fournisseur::getFournisseurID() const
{
    return fournisseurID;
}

string const & Fournisseur::getPurificateurID() const
{
    return purificateurID;
}
//-------------------------------------------- Constructeurs - destructeur
// Fournisseur::Fournisseur ( const Fournisseur & unFournisseur )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Fournisseur>" << endl;
// #endif
// } //----- Fin de Fournisseur (constructeur de copie)

Fournisseur::Fournisseur (string fournisseurID_, string purificateurID_)
{
    this->fournisseurID = fournisseurID_;
    this->purificateurID = purificateurID_;
}


Fournisseur::Fournisseur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur>" << endl;
#endif
} //----- Fin de Fournisseur


Fournisseur::~Fournisseur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fournisseur>" << endl;
#endif
} //----- Fin de ~Fournisseur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

