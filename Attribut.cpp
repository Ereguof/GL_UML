/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribut::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

const string & Attribut::getAttributId() const
{
    return attributId;
}

const string & Attribut::getUnite() const
{
    return unite;
}

const string & Attribut::getDescription() const
{
    return description;
}

//-------------------------------------------- Constructeurs - destructeur


Attribut::Attribut (string attributId_, string unite_, string description_){
	unite = unite_;
	attributId = attributId_;
	description = description_;

  #ifdef MAP
      cout << "Appel au constructeur de <Attribut>" << endl;
  #endif

}


Attribut::Attribut ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
