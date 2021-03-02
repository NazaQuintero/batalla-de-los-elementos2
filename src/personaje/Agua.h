/*
 * Agua.h
 *
 *  Created on: Nov 15, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_AGUA_H_
#define PERSONAJE_AGUA_H_

#include "Personaje.h"

const int CANT_MAX_ALIMENTADO = 3;
const int RECUPERO_DE_ENERGIA_AGUA = 10;

class Agua: public Personaje {
private:

	int vecesAlimentado = 0;
	string colorIni = "\x1B[1;36m";
	string colorFin = "\033[0m";

public:

	// Constructores
	Agua();

	Agua(string nombre);

	Agua(string nombre, int escudo, int vida);

	Agua(string nombre, int escudo, int vida, int posX, int posY);

	// Destructor

	virtual ~Agua();

	// Metodos

	string obtenerElemento();

	string alimentar();

	string getColorIni();
	string getColorFin();

	/*void defender();

	void atacar(int posX, int posY);

	void mover();*/
	
};

#endif /* PERSONAJE_AGUA_H_ */
