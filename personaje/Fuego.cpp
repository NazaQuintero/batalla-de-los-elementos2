/*
 * Fuego.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#include "Fuego.h"

Fuego::Fuego() {
	this->asignarEnergia();
}

Fuego::Fuego(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Fuego::Fuego(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

string Fuego::obtenerElemento() {
	return "fuego";
}

string Fuego::getColorIni(){
	return this->colorIni;
}

string Fuego::getColorFin(){
	return this->colorFin;
}

string Fuego::alimentar() {

	int vidaRecuperada;

	int energiaRecuperada;

	if(this->obtenerVida() <= MAXIMO_VALOR_VIDA - RECUPERO_DE_VIDA_FUEGO) {

		vidaRecuperada = RECUPERO_DE_VIDA_FUEGO;

		this->incrementarVida(RECUPERO_DE_VIDA_FUEGO);

	} else {

		vidaRecuperada = MAXIMO_VALOR_VIDA - this->obtenerVida();

		this->asignarVida(MAXIMO_VALOR_VIDA);

	}

	if (this->obtenerEnergia() <= MAXIMO_VALOR_ENERGIA - RECUPERO_DE_ENERGIA_FUEGO){

		energiaRecuperada = RECUPERO_DE_ENERGIA_FUEGO;

		this->incrementarEnergia(RECUPERO_DE_ENERGIA_FUEGO);

	} else {

		energiaRecuperada = MAXIMO_VALOR_ENERGIA - this->obtenerEnergia();

		this->asignarEnergia(MAXIMO_VALOR_ENERGIA);
	
	}

	
	return "El personaje: " + this->obtenerNombre() + " fue alimentado con madera, ha recuperado: " + to_string(vidaRecuperada) + " puntos de vida y " + to_string(energiaRecuperada) + " puntos de energia." ;

}

Fuego::~Fuego() {

}

