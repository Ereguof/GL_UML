#ifndef MAIN_H
#define MAIN_H

#include <string>

struct Date {
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
};

int lireDataset(const std::string& nomDossier);

#endif // MAIN_H