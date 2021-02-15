#ifndef CASILLERO_FABRICADECASILLERO_H_
#define CASILLERO_FABRICADECASILLERO_H_

#include "Casillero.h"
#include "Camino.h"
#include "Lago.h"
#include "Montana.h"
#include "Precipicio.h"
#include "Vacio.h"
#include "Volcan.h"

#include <iostream>

using namespace std;

class FabricaDeCasillero {
public:

	// Constructor

	FabricaDeCasillero();

	// Destructor

	virtual ~FabricaDeCasillero();

	//Metodos

	/**
	 * PRE: El terreno es un terreno valido.
	 * POS: Devuelve un puntero que apuntara a una instancia de la clase correspondiente al terreno.
	 */
	Casillero* obtenerCasillero(Terreno terreno, int posX, int posY);
};

#endif /* CASILLERO_FABRICADECASILLERO_H_ */