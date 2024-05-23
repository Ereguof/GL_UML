/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Purificateur.h"
#include "main.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
string Purificateur::getPurificateurId() const
{
    return purificateurId;
}

double Purificateur::getLattitude() const
{
    return lattitude;
}

double Purificateur::getLongitude() const
{
    return longitude;
}

Date Purificateur::getDebut() const
{
    return debut;
}

Date Purificateur::getFin() const
{
    return fin;
}

//-------------------------------------------- Constructeurs - destructeur
Purificateur::Purificateur (string purificateurId_,  double longitude_, double lattitude_, Date debut_, Date fin_){
	purificateurId = purificateurId_;
	longitude = longitude_;
	lattitude = lattitude_;
    debut = debut_;
    fin = fin_;

  #ifdef MAP
      cout << "Appel au constructeur de <Purificateur>" << endl;
  #endif

}


Purificateur::Purificateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur>" << endl;
#endif
} //----- Fin de Purificateur


Purificateur::~Purificateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Purificateur>" << endl;
#endif
} //----- Fin de ~Purificateur

// Xxx::Xxx ( const Xxx & unXxx )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Xxx>" << endl;
// #endif
// } //----- Fin de Xxx (constructeur de copie)





//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

