/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Purificateur> (fichier Purificateur.h) ----------------
#if ! defined ( Purificateur_H )
#define Purificateur_H
#include <string.h>
#include "main.h"
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Purificateur>
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
    double getLatitude() const;
    const Date & getDebut() const;
    const Date & getFin() const;
//------------------------------------------------- Surcharge d'opérateurs
    // Purificateur & operator = ( const Purificateur & unPurificateur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    // Purificateur ( const Purificateur & unPurificateur );
    // // Mode d'emploi (constructeur de copie) :
    // //
    // // Contrat :
    // //

    // Purificateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Purificateur(string purificateurId_,  double longitude_, double latitude_, Date debut_, Date fin_);
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
  double latitude;
  Date debut;
  Date fin;


//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Purificateur>

#endif // Purificateur_H

