#include "Montana.h"

Montana::Montana(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_MONTANA);
}

Montana::~Montana() {
    
}