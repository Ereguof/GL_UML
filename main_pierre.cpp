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
  date.mois = 10;
  date.jour = 5;
  date.heure =6;
  date.minute =12;
  date.seconde =12;

	Date date2;
	date2.annee = 2020;
	date2.mois = 11;
	date2.jour = 5;
	date2.heure =6;
	date2.minute =12;
	date2.seconde =12;


  Utilisateur Utilisateur1 = Utilisateur(attributId);

  Service service = Service();


  service.constulterNombrePoints(5);
  service.qualiteAirZoneCirculairePeriode(50.0, 50.0, date, date, 5);
  service.identifierZoneQualiteSimilaire(unite, date, date2);
  service.qualiteAirZoneCirculaireMoment(10.0, 10.0, date);
  service.observerImpactPurificateur("50");
  service.analyserQualiteDonnees("50");
  service.lireDataSet();


}
