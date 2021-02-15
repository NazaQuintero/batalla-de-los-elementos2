#include "Camino.h"

Camino::Camino(int posX, int posY) : Casillero(posX,posY) {
    this->setTerreno(TERRENO_CAMINO);
}

string Camino::getTerreno() {
    return "Camino";
}

Camino::~Camino() {
    
}