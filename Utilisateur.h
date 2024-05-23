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
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------

typedef struct
{
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;

} Date;


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
    int constulterNombrePoints (int Id);



    const string & getUtilisateurId() const;

    int qualiteAirZoneCirculairePeriode(double latitude, double longitude, Date debut, Date fin, int rayon);

    std::list<string> identifierZoneQualiteSimilaire(string CapteurId);


//------------------------------------------------- Surcharge d'opérateurs
    Utilisateur & operator = ( const Utilisateur & unUtilisateur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Utilisateur ( const Utilisateur & unUtilisateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Utilisateur (string Id);


    virtual ~Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  string UtilisateurId;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Utilisateur>

#endif // Utilisateur_H
