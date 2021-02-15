#include "Precipicio.h"

Precipicio::Precipicio(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_PRECIPICIO);
}

Precipicio::~Precipicio() {
    
}