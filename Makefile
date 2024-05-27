MAP = -DMAP
FLAGS = -ansi -pedantic -Wall -std=c++11
OBJ = main.o Attribut.o Capteur.o Fournisseur.o Mesure.o Particulier.o Utilisateur.o Purificateur.o Service.o
TARGET = main

main: $(OBJ)
		g++ -o main $(OBJ) $(FLAGS) $(MAP)

main.o: main.cpp
		g++ -c main.cpp $(FLAGS)

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
		rm -f $(OBJ) $(TARGET)