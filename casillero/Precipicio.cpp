#include "Precipicio.h"

Precipicio::Precipicio(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_PRECIPICIO);
}

string Precipicio::getTerreno() {
    return "Precipicio";
}

string Precipicio::getColorIni() {
    return this->colorIni;
}

string Precipicio::getColorFin() {
    return this->colorFin;
}

Precipicio::~Precipicio() {
    
}