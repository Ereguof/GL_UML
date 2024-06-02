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

    const string & getUtilisateurID() const;

//-------------------------------------------- Constructeurs - destructeur

    Utilisateur ( );

    Utilisateur (string utilisateurID);


    virtual ~Utilisateur ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  string utilisateurID;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Utilisateur>

#endif // Utilisateur_H
