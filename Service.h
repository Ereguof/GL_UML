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
#include <vector>
#include "Utilisateur.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Mesure.h"
#include <iterator>

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

    vector<string> identifierZoneQualiteSimilaire(string CapteurId, Date debut, Date fin);

    int qualiteAirZoneCirculaireMoment(double latitude, double longitude, Date jour);

    int observerImpactPurificateur(string PurificateurId);

    int analyserQualiteDonnees(string CapteurId);

    int lireDataSet();

    int moyenneIndiceAtmo(string CapteurId, Date debut, Date fin);
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
  std::vector<Utilisateur> listeUtilisateur;
  std::vector<Particulier> listeParticulier;
  std::vector<Capteur> listeCapteur;
  std::vector<Attribut> listeAttribut;
  std::vector<Mesure> listeMesure;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // Service_H
