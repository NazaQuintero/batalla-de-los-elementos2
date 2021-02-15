#ifndef CASILLERO_CASILLERO_H_
#define CASILLERO_CASILLERO_H_

#include <string>
#include <iostream>
#include "../personaje/Personaje.h"

using namespace std;

enum Terreno { LAGO, VOLCAN, PRECIPICIO, MONTANA, CAMINO, VACIO };

class Casillero {

private:
	// Atributos
	int pos [2];
	Personaje* personaje;
	string color;
	Terreno terreno;

public:
	// Constructor

	Casillero(int posX, int posY);

	// Metodos

	/**
	 * TO DO:
	 * Definir color, setColor()
	 * getAdyacentes() */

    Personaje* getPersonaje();

    void setPersonaje(Personaje* personaje);

    int* getPos();

	void setTerreno(Terreno terreno);

	Terreno getTerreno();

	// Destructor

	virtual ~Casillero();

};

#endif /* CASILLERO_CASILLERO_H_ */