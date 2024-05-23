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



//-------------------------------------------- Constructeurs - destructeur


Attribut::Attribut (int attributId_, int unite_, string description_){
	unite = unite_;
	attributId = attributId_;
	description = description_;

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
