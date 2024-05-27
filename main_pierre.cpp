
#include "main.h"
#include "Service.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Mesure.h"
#include "Fournisseur.h"
#include "Utilisateur.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Purificateur.h"
#include "Particulier.h"


using namespace std;

int main(){



	string capteurId = "Sensor0";

  Date date;
  date.annee = 2019;
  date.mois = 1;
  date.jour = 1;
  date.heure = 11;
  date.minute = 0;
  date.seconde = 0;

	Date date2;
	date2.annee = 2019;
	date2.mois = 3;
	date2.jour = 27;
	date2.heure =12;
	date2.minute =0;
	date2.seconde =0;



  Service service = Service();

	service.lireDataSet("dataset");
  service.identifierZoneQualiteSimilaire(capteurId, date, date2);


}
