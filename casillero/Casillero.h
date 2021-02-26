#ifndef CASILLERO_CASILLERO_H_
#define CASILLERO_CASILLERO_H_

#include <string>
#include <iostream>
#include "../personaje/Personaje.h"
#include "../tda/lista/lista.h"
#include "../coordenadas/Coordenada.h"

using namespace std;

enum Terreno { LAGO, VOLCAN, PRECIPICIO, MONTANA, CAMINO, VACIO };

class Casillero {

private:
	// Atributos
	int pos [2];
	Personaje* personaje;
	Personaje* personajePasajero;
	Terreno terreno;

public:
	// Constructor
	Casillero(int posX, int posY);

	Casillero();

	// Metodos

	/**
	 * TO DO:
	 * Definir color, setColor()
	*/ 

	virtual string getTerreno() = 0;

	virtual string getColorIni() = 0;

    virtual string getColorFin() = 0;
    
	// Devuelve el personaje pasajero
	Personaje* getPersonajePasajero();

	// Devuelve el personaje
	Personaje* getPersonaje();

	// Inserta al personaje en el casillero
    void setPersonaje(Personaje* personaje);

	// Inserta al personaje pasajero en el casillero
	void setPersonajePasajero(Personaje* personajePasajero);

	// Devuelve la posicion del casillero
    int* getPos();

    void setPos(int posX, int posY);

    string getPosString();

	string imprimirPersonajeColor();

	string toString();

	// Destructor
	virtual ~Casillero();

};

#endif /* CASILLERO_CASILLERO_H_ */
