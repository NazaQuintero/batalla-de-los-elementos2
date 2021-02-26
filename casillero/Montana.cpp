#include "Montana.h"

Montana::Montana(int posX, int posY) : Casillero(posX, posY) {
    
}

string Montana::getTerreno() {
    return "Montana";
}

string Montana::getColorIni() {
    return this->colorIni;
}

string Montana::getColorFin() {
    return this->colorFin;
}

Montana::~Montana() {
    
}