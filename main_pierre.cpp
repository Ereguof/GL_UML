#include <iostream>
#include <string.h>
#include "Utilisateur.h"


using namespace std;

int main(){

	string attributId = "5";

	string unite = "100";

	string  description = "fjmdsljf";


  Utilisateur Utilisateur1 = Utilisateur(attributId);

  Utilisateur1.constulterNombrePoints(5);

  Utilisateur1.identifierZoneQualiteSimilaire(unite);


}
