/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( Mesure_H )
#define Mesure_H


//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string.h>
#include "main.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste des paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //
        string const & getCapteurID() const;
        string const & getAttributID() const;
        double getValeur() const;
        Date const & getDate() const;

    //-------------------------------------------- Constructeurs - destructeur

        Mesure ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        Mesure(Date date_, string capteurID_, string attributID_, double valeur_);
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Mesure ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Mesures protégés
    Date date;
    string capteurID;
    string attributID;
    double valeur;
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif // Mesure_H

