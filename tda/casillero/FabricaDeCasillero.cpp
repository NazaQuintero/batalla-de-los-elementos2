#include "FabricaDeCasillero.h"


FabricaDeCasillero::~FabricaDeCasillero() {

}

FabricaDeCasillero::FabricaDeCasillero() {

}

Casillero* FabricaDeCasillero::obtenerCasillero(Terreno terreno, int posX, int posY) {

	Casillero* casillero;

	if (terreno == camino) {

		casillero = new Camino (posX, posY);

	} else if (terreno == lago) {

		casillero = new Lago (posX, posY);

	} else if (terreno == montana) {

		casillero = new Montana (posX, posY);

	} else if (terreno == precipicio) {

		casillero = new Precipicio (posX, posY);

	} else if (terreno == vacio) {

		casillero = new Vacio( posX, posY);

	} else if (terreno == volcan) {

		casillero = new Volcan(posX, posY);

	}

	return casillero;
}