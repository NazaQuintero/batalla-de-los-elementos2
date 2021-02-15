#include "Volcan.h"

Volcan::Volcan(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_VOLCAN);
}

string Volcan::getTerreno() {
    return "Volcan";
}

Volcan::~Volcan() {
    
}