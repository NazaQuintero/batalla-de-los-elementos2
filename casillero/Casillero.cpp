#include "Casillero.h"

Casillero::Casillero(int posX, int posY) {
    this->pos [0] = posX;
    this->pos [1] = posY;
    this->personaje = 0;
    this->terreno = LAGO;
}

void Casillero::setColor(string color) {
    this->color = color;
}

Personaje* Casillero::getPersonaje() {
    return this->personaje;
}

void Casillero::buscarAdyacentes(Lista<Coordenada>* listaCoordenadas){
    int X = this->pos[0];
    int Y = this->pos[1];

    if(X - 1 >= 0){
        Coordenada* coord = new Coordenada(X-1,Y);
        listaCoordenadas->alta(*coord,1);
    }

    if(X + 1 < 8){
        Coordenada* coord = new Coordenada(X+1,Y);
        listaCoordenadas->alta(*coord,1);
    }

    if(Y - 1 >=0){
        Coordenada* coord = new Coordenada(X,Y-1);
        listaCoordenadas->alta(*coord,1);
    }
    
    if(Y + 1 < 8){
        Coordenada* coord = new Coordenada(X,Y + 1);
        listaCoordenadas->alta(*coord,1);
    }
}

Lista<Coordenada>* Casillero::getAdyacentes(){

    Lista<Coordenada>* listaCoordenadas = new Lista<Coordenada>();

    buscarAdyacentes(listaCoordenadas);

    return listaCoordenadas;
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

void Casillero::setTerreno(Terreno terreno) {
    this->terreno = terreno;
}

// Terreno Casillero::getTerreno() {
//     return this->terreno;
// }

string Casillero::toString() {
    
}

void bajarVida(int cantidadVida, string elemento) {
    // ...
}

Casillero::~Casillero() {

}
