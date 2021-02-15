#include "Volcan.h"

Volcan::Volcan(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_VOLCAN);
}

Volcan::~Volcan() {
    
}