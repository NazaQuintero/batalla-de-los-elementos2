#include "Lago.h"

Lago::Lago(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_LAGO);
}

Lago::~Lago() {

}