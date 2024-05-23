/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( Purificateur_H )
#define Purificateur_H
#include <string.h>
#include "main.h"
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Purificateur 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   string getPurificateurId() const;
   double getLongitude() const;
   double getLattitude() const;
   const string & getDescription() const;

//------------------------------------------------- Surcharge d'opérateurs
    Purificateur & operator = ( const Purificateur & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Purificateur ( const Purificateur & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Purificateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Purificateur(string purificateurId_,  double longitude_, double lattitude_, Date debut_, Date fin_);
    virtual ~Purificateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string purificateurId;
  double longitude;
  double lattitude;
  Date debut;
  Date fin;


//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

