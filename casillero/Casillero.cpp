#include "Casillero.h"

Casillero::Casillero(int posX, int posY) {
    this->pos [0] = posX;
    this->pos [1] = posY;
    this->personaje = 0;
    this->terreno = LAGO;
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

void Casillero::setPos(int posX, int posY) {
	this->pos[0] = posX;
	this->pos[1] = posY;
}

string Casillero::getPosString() {
	return "(" + to_string(this->pos[0]) + "," + to_string(this->pos[1]) + ")";
}

string Casillero::imprimirPersonajeColor() {
    if(!this->getPersonaje()){
        return "       ";
    } else {
        return this->getPersonaje()->getColorIni() + "   X   " + this->getPersonaje()->getColorFin();
    }
}

string Casillero::toString() {
    return getColorIni() + "---------\n|       |\n|" + getColorFin() + imprimirPersonajeColor() + getColorIni() + "|\n|       |\n---------" + getColorFin();
}

void bajarVida(int cantidadVida, string elemento) {
    // ...
}

Casillero::~Casillero() {

}
