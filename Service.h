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
#include <fstream>
#include <iostream>
#include "Utilisateur.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Mesure.h"
#include "Purificateur.h"
#include "Fournisseur.h"
#include <cmath>
#include <algorithm>
#include <map>
#include <iterator>
#include <numeric>
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

    int constulterNombrePoints (string Id);

    int qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon);

    vector<Capteur> identifierZoneQualiteSimilaire(string CapteurId, Date debut, Date fin);

    int qualiteAirZoneCirculaireMoment(double latitude, double longitude, Date jour, int rayon);

    int observerImpactPurificateur(string PurificateurId);

    int analyserQualiteDonnees(string CapteurId);

    int lireDataSet(string nomDossier);

    double moyenneIndiceAtmo(string CapteurId, Date debut, Date fin);

    vector<Particulier> getListeParticulier();
    vector<Capteur> getListeCapteur();
    vector<Attribut> getListeAttribut();
    vector<Mesure> getListeMesure();
    vector<Purificateur> getListePurificateur();
    vector<Fournisseur> getListeFournisseur();

    void setListeParticulier(vector<Particulier> listeParticulier);
    void setListeCapteur(vector<Capteur> listeCapteur);
    void setListeAttribut(vector<Attribut> listeAttribut);
    void setListeMesure(vector<Mesure> listeMesure);
    void setListePurificateur(vector<Purificateur> listePurificateur);
    void setListeFournisseur(vector<Fournisseur> listeFournisseur);

//-------------------------------------------- Constructeurs - destructeur

    Service ( );

    virtual ~Service ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
  vector<Particulier> listeParticulier;
  vector<Capteur> listeCapteur;
  vector<Attribut> listeAttribut;
  vector<Mesure> listeMesure;
  vector<Purificateur> listePurificateur;
  vector<Fournisseur> listeFournisseur;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // Service_H
