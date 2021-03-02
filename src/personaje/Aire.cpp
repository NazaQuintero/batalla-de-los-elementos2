/*
 * Aire.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#include "Aire.h"

Aire::Aire() {
	this->asignarEnergia();
}

Aire::Aire(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Aire::Aire(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

Aire::Aire(string nombre, int escudo, int vida, int posX, int posY) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
	this->setPosicion(posX,posY);
}

string Aire::obtenerElemento() {
	return "aire";
}

string Aire::alimentar() {
	return "Los Personajes de tipo Aire no necesitan alimentarse.";
}

string Aire::getColorIni(){
	return this->colorIni;
}

string Aire::getColorFin(){
	return this->colorFin;
}

Aire::~Aire() {

}

