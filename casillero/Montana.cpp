#include "Montana.h"

Montana::Montana(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_MONTANA);
}

string Montana::getTerreno() {
    return "Montana";
}

Montana::~Montana() {
    
}