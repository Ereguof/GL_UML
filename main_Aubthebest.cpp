#include "Capteur.h"
#include <iostream>
using namespace std;
#include <string>
//------------------------------------------------------ Include personnel



int main(){
  string mot = "12";
  Capteur monCapteur(mot,-45.1,98.2);
  cout<<monCapteur.getLatitude()<<endl;
}
