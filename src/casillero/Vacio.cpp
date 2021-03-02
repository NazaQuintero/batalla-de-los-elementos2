#include "Vacio.h"

Vacio::Vacio(int posX, int posY) : Casillero(posX, posY) {
    
}

string Vacio::getTerreno() {
    return "Vacio";
}

string Vacio::getColorIni() {
    return this->colorIni;
}

string Vacio::getColorFin() {
    return this->colorFin;
}

Vacio::~Vacio() {
    
}