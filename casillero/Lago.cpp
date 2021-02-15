#include "Lago.h"

Lago::Lago(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_LAGO);
    this->setColor(COLOR_LAGO);
}

string Lago::getTerreno() {
    return "Lago";
}

Lago::~Lago() {

}