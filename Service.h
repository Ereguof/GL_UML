/*************************************************************************
                           Service  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Service> (fichier Service.h) ----------------
#if ! defined ( Service_H )
#define Service_H
using namespace std;
#include <list>
#include "Utilisateur.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Mesure.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class Service
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int constulterNombrePoints (int Id);


    int qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon);

    std::list<string> identifierZoneQualiteSimilaire(string CapteurId);

    int qualiteAirZoneCirculaireMoment(double latitude, double longitude, Date jour);

    int observerImpactPurificateur(string PurificateurId);

    int analyserQualiteDonnees(string CapteurId);


//------------------------------------------------- Surcharge d'opérateurs
    Service & operator = ( const Service & unService );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Service ( const Service & unService );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
  std::list<Utilisateur> listeUtilisateur;
  std::list<Particulier> listeParticulier;
  std::list<Capteur> listeCapteur;
  std::list<Attribut> listeAttribut;
  std::list<Mesure> listeMesure;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // Service_H
