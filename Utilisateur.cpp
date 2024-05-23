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


int Utilisateur::constulterNombrePoints(int Id){
    cout << "La fonction constulterNombrePoints n'a pas été implémentéé, elle retourne juste l'id en entrée" << endl;
    return Id;
}

int Utilisateur::qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon){
    cout << "Il faut encore implémenter cette fonction" << endl;
    return 0;
}

list<string> Utilisateur :: identifierZoneQualiteSimilaire(string CapteurId){
    cout << "Il faut encore implémenter cette fonction" << endl;
    std::list <string> stringlist = {"Hello"};

    return stringlist;
}

const string & Utilisateur::getUtilisateurId() const
{
    return UtilisateurId;
}

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (constructeur de copie)


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

Utilisateur::Utilisateur (string id)
// Algorithme :
//
{

UtilisateurId = id;
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
