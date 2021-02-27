#include "Camino.h"

Camino::Camino(int posX, int posY) : Casillero(posX,posY) {
    
}

string Camino::getTerreno() {
    return "Camino";
}

string Camino::getColorIni() {
	return this->colorIni;
}

string Camino::getColorFin() {
	return this->colorFin;
}

Camino::~Camino() {
    
}
