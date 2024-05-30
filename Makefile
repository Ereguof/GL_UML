MAP = -DMAP
FLAGS = -ansi -pedantic -Wall -std=c++11
OBJ_MAIN = main.o Attribut.o Capteur.o Fournisseur.o Mesure.o Particulier.o Utilisateur.o Purificateur.o Service.o
OBJ_TESTS = mainTestsUnitaires.o Attribut.o Capteur.o Fournisseur.o Mesure.o Particulier.o Utilisateur.o Purificateur.o Service.o
TARGET = main mainTestsUnitaires

all: $(TARGET)

main: $(OBJ_MAIN)
		g++ -o main $(OBJ_MAIN) $(FLAGS) $(MAP)

mainTestsUnitaires: $(OBJ_TESTS)
		g++ -o mainTestsUnitaires $(OBJ_TESTS) $(FLAGS) $(MAP)

main.o: main.cpp
		g++ -c main.cpp $(FLAGS)

mainTestsUnitaires.o: mainTestsUnitaires.cpp
		g++ -c mainTestsUnitaires.cpp $(FLAGS)

Attribut.o: Attribut.cpp
		g++ -c Attribut.cpp $(FLAGS)

Capteur.o: Capteur.cpp
		g++ -c Capteur.cpp $(FLAGS)

Fournisseur.o: Fournisseur.cpp
		g++ -c Fournisseur.cpp $(FLAGS)

Mesure.o: Mesure.cpp
		g++ -c Mesure.cpp $(FLAGS)

Particulier.o: Particulier.cpp
		g++ -c Particulier.cpp $(FLAGS)

Utilisateur.o: Utilisateur.cpp
		g++ -c Utilisateur.cpp $(FLAGS)

Purificateur.o: Purificateur.cpp	
		g++ -c Purificateur.cpp $(FLAGS)

Service.o: Service.cpp	
		g++ -c Service.cpp $(FLAGS)

clean:
		rm -f $(OBJ_TESTS) $(OBJ_MAIN) $(TARGET)