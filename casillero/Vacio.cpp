#include "Vacio.h"

Vacio::Vacio(int posX, int posY) : Casillero(posX, posY) {
    
}

string Vacio::getTerreno() {
    return "Vacio";
}

Vacio::~Vacio() {
    
}