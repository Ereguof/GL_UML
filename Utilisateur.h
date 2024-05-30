/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ----------------
#if ! defined ( Utilisateur_H )
#define Utilisateur_H
#include <list>
#include "main.h"
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------



class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const string & getUtilisateurID() const;
//------------------------------------------------- Surcharge d'opérateurs
    // Utilisateur & operator = ( const Utilisateur & unUtilisateur );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    // Utilisateur ( const Utilisateur & unUtilisateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Utilisateur (string utilisateurID);


    virtual ~Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  string utilisateurID;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Utilisateur>

#endif // Utilisateur_H
