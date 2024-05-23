#include <iostream>
#include <string.h>
#include "Utilisateur.h"
#include "main.h"
#include "Service.h"

using namespace std;

int main(){

	string attributId = "5";

	string unite = "100";

	string  description = "fjmdsljf";

  Date date;
  date.annee = 2020;
  date.mois = 18;
  date.jour = 5;
  date.heure =6;
  date.minute =12;
  date.seconde =12;


  Utilisateur Utilisateur1 = Utilisateur(attributId);

  Service service = Service();


  service.constulterNombrePoints(5);
  service.qualiteAirZoneCirculairePeriode(50.0, 50.0, date, date, 5);
  service.identifierZoneQualiteSimilaire(unite);
  service.qualiteAirZoneCirculaireMoment(10.0, 10.0, date);
  service.observerImpactPurificateur("50");
  service.analyserQualiteDonnees("50");
  service.lireDataSet();


}
