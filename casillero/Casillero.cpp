#include "Casillero.h"

Casillero::Casillero(int posX, int posY) {
    this->pos [0] = posX;
    this->pos [1] = posY;
    this->personaje = 0;
}

Personaje* Casillero::getPersonaje() {
    return this->personaje;
}

Personaje* Casillero::getPersonajePasajero() {
    return this->personajePasajero;
}

void Casillero::setPersonaje(Personaje* personaje) {
    this->personaje = personaje;
}

void Casillero::setPersonajePasajero(Personaje* personajePasajero) {
    this->personajePasajero = personajePasajero;
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
    if(this->personajePasajero) {
        return this->getPersonajePasajero()->getColorIni() + "X" + this->getPersonajePasajero()->getColorFin();
    }

    if(this->getPersonaje()){
        return this->getPersonaje()->getColorIni() + "X" + this->getPersonaje()->getColorFin();
    }
    
    return " ";
}

// string Casillero::toString() {
//     return getColorIni() + "---------\n|       |\n|" + getColorFin() + imprimirPersonajeColor() + getColorIni() + "|\n|       |\n---------" + getColorFin();
// }

string Casillero::toString() {
    return getColorIni() + "[ " + getColorFin() + imprimirPersonajeColor() + getColorIni() + " ]" + getColorFin();
}

Casillero::~Casillero() {

}
