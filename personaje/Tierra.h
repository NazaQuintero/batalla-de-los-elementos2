/*
 * Tierra.h
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_TIERRA_H_
#define PERSONAJE_TIERRA_H_

#include "Personaje.h"

const int RECUPERO_DE_ENERGIA_TIERRA = 8;

class Tierra: public Personaje {
	private:
		string colorIni = "\x1B[2;49;31m";
		string colorFin = "\033[0m";
public:

	// Constructores

	Tierra();

	Tierra(string nombre);

	Tierra(string nombre, int escudo, int vida);

	Tierra(string nombre, int escudo, int vida, int posX, int posY);

	string getColorIni();
	string getColorFin();

	// Destructor

	virtual ~Tierra();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_TIERRA_H_ */
