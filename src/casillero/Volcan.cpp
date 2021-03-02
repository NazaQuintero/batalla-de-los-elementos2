#include "Volcan.h"

Volcan::Volcan(int posX, int posY) : Casillero(posX, posY) {
    
}

string Volcan::getTerreno() {
    return "Volcan";
}

string Volcan::getColorIni() {
    return this->colorIni;
}

string Volcan::getColorFin() {
    return this->colorFin;
}

Volcan::~Volcan() {
    
}