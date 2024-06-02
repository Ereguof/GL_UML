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
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   const string & getAttributId() const;
   const string & getUnite() const;
   const string & getDescription() const;

//-------------------------------------------- Constructeurs - destructeur

    Attribut ( );

    Attribut(string attributId_,  string unite_, string description_);
    virtual ~Attribut ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string attributId;
  string unite;
  string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // Attribut_H
