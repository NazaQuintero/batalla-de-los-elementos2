
#include "Personaje.h"

Personaje::Personaje() {
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Personaje::~Personaje() {

}

int Personaje::obtenerNroRandom(int min, int max) {
	return (rand() % max) + (min);
}

void Personaje::asignarNombre(string nombre) {
	this->nombre = nombre;
}

string Personaje::obtenerNombre() {
	return this->nombre;
}

void Personaje::asignarEscudo() {
	this->escudo = obtenerNroRandom(MINIMO_VALOR_ESCUDO, MAXIMO_VALOR_ESCUDO);
}

void Personaje::asignarEscudo(int escudo) {
	this->escudo = escudo;
}

int Personaje::obtenerEscudo() {
	return this->escudo;
}

void Personaje::asignarVida() {
	this->vida = obtenerNroRandom(MINIMO_VALOR_VIDA, MAXIMO_VALOR_VIDA);
}

void Personaje::asignarVida(int vida) {
	this->vida = vida;
}

void Personaje::incrementarVida(int incremento) {
	this->vida += incremento;
}

int Personaje::obtenerVida() {
	return this->vida;
}

void Personaje::bajarVida(int cantidad) {
	if (this->escudo == 0){
		this->vida -= cantidad;
	}else if (this->escudo == 1){
		cantidad = cantidad - (10*cantidad)/100;
		this->vida -= cantidad;
	}else if (this->escudo == 2){
		cantidad = cantidad - (20*cantidad)/100;
		this->vida -= cantidad;
	}else{
		cantidad = cantidad - (80*cantidad)/100;
		this->vida -= cantidad;
	}
}

void Personaje::asignarEnergia() {
	this->energia = obtenerNroRandom(MINIMO_VALOR_ENERGIA, MAXIMO_VALOR_ENERGIA);
}

void Personaje::asignarEnergia(int energia) {
	this->energia = energia;
}

void Personaje::bajarEnergia(int cantidad) {
	this->energia -= cantidad;
}

void Personaje::incrementarEnergia(int incremento) {
	this->energia += incremento;
}

int Personaje::obtenerEnergia() {
	return this->energia;
}

void Personaje::setPosicion(int x, int y) {
	this->pos[0] = x;
	this->pos[1] = y;
}

int* Personaje::getPosicion() {
	return this->pos;
}

string Personaje::toString() {
	return this->obtenerElemento() + "," + this->obtenerNombre() + "," + to_string(this->obtenerEscudo()) + "," + to_string(this->obtenerVida()) + "," + to_string(this->obtenerEnergia()) + "," + to_string(this->getPosicion()[0]) + "," + to_string(this->getPosicion()[1]);
}

    
