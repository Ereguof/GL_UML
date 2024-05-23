/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( Attribut_H )
#define Attribut_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur
    Attribut ( const Attribut & unAttribut );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attribut ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Attribut(int attributId_,  int unite_, string description_);
    virtual ~Attribut ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int attributId;
int unite;
string description;

	


};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // Attribut_H

