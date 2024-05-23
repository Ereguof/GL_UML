#include "Capteur.h"
#include "Particulier.h"
#include <iostream>
using namespace std;
#include <string>
//------------------------------------------------------ Include personnel



int main(){
  string mot = "12";
  Capteur monCapteur(mot,-45.1,98.2);
  cout<<monCapteur.getLatitude()<<endl;
  cout<<monCapteur.getLongitude()<<endl;
  cout<<monCapteur.getCapteurID()<<endl;
  string userID = "1";
  Particulier James(userID);
  cout<<James.getUtilisateurId()<<endl;

  cout<<James.getNbPoints()<<endl;
  cout<<James.getFiabilite()<<endl;
  string newCapteurID = "14";
  James.setCapteurID(newCapteurID);
  cout<<James.getCapteurID()<<endl;
}
