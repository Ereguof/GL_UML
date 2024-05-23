/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined ( Capteur_H )
#define Capteur_H
#include <string>
//--------------------------------------------------- Interfaces utilisées
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    string getCapteurID() const;
    double getLatitude() const;
    double getLongitude() const;

//------------------------------------------------- Surcharge d'opérateurs
    Capteur & operator = ( const Capteur & unCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Capteur ( const Capteur & unCapteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Capteur (string monCapteurID, double maLatitude, double maLongitude );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string CapteurID;
double latitude;
double longitude;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // Capteur_H
