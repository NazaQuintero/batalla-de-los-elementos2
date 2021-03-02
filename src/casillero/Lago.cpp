#include "Lago.h"

Lago::Lago(int posX, int posY) : Casillero(posX, posY) {
    
}

string Lago::getTerreno() {
    return "Lago";
}

string Lago::getColorIni() {
    return this->colorIni;
}

string Lago::getColorFin() {
    return this->colorFin;
}

Lago::~Lago() {

}