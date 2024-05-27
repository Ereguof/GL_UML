/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
#include <list>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

 using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Utilisateur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


const string & Utilisateur::getUtilisateurID() const
{
    return utilisateurID;
}

const string & Utilisateur::getCapteurID() const
{
    return capteurID;
}

//-------------------------------------------- Constructeurs - destructeur
// Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
// #endif
// } //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur

Utilisateur::Utilisateur (string utilisateurID_, string capteurID_)
// Algorithme :
//
{
    this->utilisateurID = utilisateurID_;
    this->capteurID = capteurID_;
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
