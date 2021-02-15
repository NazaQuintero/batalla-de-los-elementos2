#include "FabricaDeCasillero.h"


FabricaDeCasillero::~FabricaDeCasillero() {

}

FabricaDeCasillero::FabricaDeCasillero() {

}

Casillero* FabricaDeCasillero::obtenerCasillero(Terreno terreno, int posX, int posY) {

	Casillero* casillero;

	if (terreno == CAMINO) {

		casillero = new Camino (posX, posY);

	} else if (terreno == LAGO) {

		casillero = new Lago (posX, posY);

	} else if (terreno == MONTANA) {

		casillero = new Montana (posX, posY);

	} else if (terreno == PRECIPICIO) {

		casillero = new Precipicio (posX, posY);

	} else if (terreno == VACIO) {

		casillero = new Vacio( posX, posY);

	} else if (terreno == VOLCAN) {

		casillero = new Volcan(posX, posY);

	}

	return casillero;
}