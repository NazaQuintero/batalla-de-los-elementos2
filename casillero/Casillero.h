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
	string color;
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
	
	void setColor(string color);

	//Recibe una lista de coordenadas vacia que se cargara
	//con las coordenadas de los casilleros adyacentes
	void buscarAdyacentes(Lista<Coordenada>* listaCoordenadas);
	 
	// Devuelve la lista de coordenadas de los casilleros adyacentes
	Lista<Coordenada>* getAdyacentes();
    
	// Devuelve el personaje
	Personaje* getPersonaje();


	// Inserta al personaje en el casillero
    void setPersonaje(Personaje* personaje);

	// Devuelve la posicion del casillero
    int* getPos();

    void setPos(int posX, int posY);

    string getPosString();

	// Inserta tipo de terreno pasado por parametro al casillero
	void setTerreno(Terreno terreno);

	// Devuleve el tipo de terreno del casillero
	// Terreno getTerreno();


	// Destructor
	virtual ~Casillero();

};

#endif /* CASILLERO_CASILLERO_H_ */
