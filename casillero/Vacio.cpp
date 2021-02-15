#include "Vacio.h"

Vacio::Vacio(int posX, int posY) : Casillero(posX, posY) {
    this->setTerreno(TERRENO_VACIO);
}

string Vacio::getTerreno() {
    return "Vacio";
}

Vacio::~Vacio() {
    
}