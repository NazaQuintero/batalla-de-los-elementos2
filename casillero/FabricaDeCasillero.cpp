#include "FabricaDeCasillero.h"


FabricaDeCasillero::~FabricaDeCasillero() {

}

FabricaDeCasillero::FabricaDeCasillero() {

}

Casillero* FabricaDeCasillero::obtenerCasillero(string terreno, int posX, int posY) {

	Casillero* casillero;

	if (terreno == "Camino") {

		casillero = new Camino (posX, posY);

	} else if (terreno == "Lago") {

		casillero = new Lago (posX, posY);

	} else if (terreno == "Montana") {

		casillero = new Montana (posX, posY);

	} else if (terreno == "Precipicio") {

		casillero = new Precipicio (posX, posY);

	} else if (terreno == "Vacio") {

		casillero = new Vacio( posX, posY);

	} else if (terreno == "Volcan") {

		casillero = new Volcan(posX, posY);

	}

	return casillero;
}