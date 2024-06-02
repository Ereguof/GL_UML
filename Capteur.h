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

    string const & getCapteurID() const;
    double getLatitude() const;
    double getLongitude() const;

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    Capteur (string monCapteurID, double maLatitude, double maLongitude );

    virtual ~Capteur ( );

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
