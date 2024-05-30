/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if ! defined ( Particulier_H )
#define Particulier_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Utilisateur.h"
//------------------------------------------------------------- Constantes
using namespace std;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Particulier>
//
//
//------------------------------------------------------------------------

class Particulier : public Utilisateur
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
    int getNbPoints() const;
    int setNbPoints(int nbPoints_) ;
    bool getFiabilite() const;
    void setCapteurID(const string& newCapteurID);


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    // Particulier ( const Particulier & unParticulier );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Particulier ( string userID_, string capteurID_, bool fiabilite_, int nbPoints_ );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Particulier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string capteurID;
int nbPoints;
bool fiabilite;
};

//-------------------------------- Autres définitions dépendantes de <Particulier>

#endif // Particulier_H
