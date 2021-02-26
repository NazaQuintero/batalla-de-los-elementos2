/*
 * Fuego.h
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_FUEGO_H_
#define PERSONAJE_FUEGO_H_

#include "Personaje.h"

const int RECUPERO_DE_VIDA_FUEGO = 5;
const int RECUPERO_DE_ENERGIA_FUEGO = 10;

class Fuego: public Personaje {
	private:
		string colorIni = "\x1B[1;31m";
		string colorFin = "\033[0m\t\t";

	public:

	// Constructores

	Fuego();

	Fuego(string nombre);

	Fuego(string nombre, int escudo, int vida);

	string getColorIni();
	string getColorFin();

	// Destructor

	virtual ~Fuego();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_FUEGO_H_ */
