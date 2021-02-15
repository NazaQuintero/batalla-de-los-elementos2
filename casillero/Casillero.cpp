#include "Casillero.h"

Casillero::Casillero(int posX, int posY) {
    this->pos [0] = posX;
    this->pos [1] = posY;
}

Personaje* Casillero::getPersonaje() {
    return this->personaje;
}

void Casillero::setPersonaje(Personaje* personaje) {
    this->personaje = personaje;
}

int* Casillero::getPos() {
    return this->pos;
}

void Casillero::setTerreno(Terreno terreno) {
    this->terreno = terreno;
}

Terreno Casillero::getTerreno() {
    return this->terreno;
}

Casillero::~Casillero() {

}