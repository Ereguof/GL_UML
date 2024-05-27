/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if ! defined ( Fournisseur_H )
#define Fournisseur_H


//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string.h>
#include "Utilisateur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//
//
//------------------------------------------------------------------------

class Fournisseur : public Utilisateur
{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        bool passerEnModePrivilegie (string motDePasse) const;
        // Mode d'emploi :

        string const & getFournisseurID() const;

        string const & getPurificateurID() const;

    //-------------------------------------------- Constructeurs - destructeur
        // Fournisseur ( const Fournisseur & unFournisseur );
        // // Mode d'emploi (constructeur de copie) :
        // //
        // // Contrat :
        // //

        Fournisseur ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        Fournisseur(string fournisseurID_, string purificateurID_);
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Fournisseur ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Fournisseurs protégés
    string fournisseurID;
    string purificateurID;
};

//-------------------------------- Autres définitions dépendantes de <Fournisseur>

#endif // Fournisseur_H

