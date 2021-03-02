#include "Precipicio.h"

Precipicio::Precipicio(int posX, int posY) : Casillero(posX, posY) {
    
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