#include "Coordenada.h"

Coordenada::Coordenada() {
	this->posX = 0;
	this->posY = 0;
}

Coordenada::Coordenada(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}


int Coordenada:: getPosX(){
    return this->posX;
}

int Coordenada:: getPosY(){
    return this->posY;
}
    
Coordenada::~Coordenada() {
    
}
