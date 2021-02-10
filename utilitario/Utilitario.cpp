/*
 * Utilitario.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nazaquintero
 */

#include "Utilitario.h"

Utilitario::Utilitario() {
	this->terminal = Terminal::obtenerInstancia();
}

Utilitario::~Utilitario() {
	delete this->terminal;
}

Utilitario* Utilitario::obtenerInstancia() {

	if(!utilitario)
		utilitario = new Utilitario();

	return utilitario;

}

void Utilitario::split(string str, char sep, vector<string> &resultado) {

	istringstream f(str);
	string s;

	while(getline(f, s, sep)) {
		resultado.push_back(s);
	}

}

void Utilitario::cargarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	fstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ios::in);

	if(!archivo_personajes.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_PERSONAJES << "\", se va a crear el archivo" << endl;
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::out);
		archivo_personajes.close();
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::in);
	}

	string linea;
	string elemento, nombre, escudoStr, vidaStr;
	int escudo, vida;

	vector<string> datos;

	while(archivo_personajes >> linea) {

		split(linea, ',', datos);

		elemento = datos[0];
		nombre = datos[1];
		escudoStr = datos[2];
		vidaStr = datos[3];

		escudo = stol(escudoStr);
		vida = stol(vidaStr);

		FabricaDePersonaje fabricaDePersonaje;

		Personaje* personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre, escudo, vida);

		datos.clear();

		//diccionarioDePersonajes->alta(personaje, 1);
		if(!diccionarioDePersonajes->pertenece(nombre)) {
			diccionarioDePersonajes->guardar(nombre, personaje);
		} else {
			cout << "El personaje: " << nombre << " ya fue creado anteriormente." << endl;
		}


	}

	archivo_personajes.close();

}

void Utilitario::mostrarPersonaje(Personaje* personaje) {
	cout << "~~~~ Personaje ~~~~" << endl;
	cout << "Elemento: " << personaje->obtenerElemento() << "\nNombre: " << personaje->obtenerNombre() << "\nEscudo: " << personaje->obtenerEscudo() << "\nVida: " << personaje->obtenerVida() << "\nEnergia: " << personaje->obtenerEnergia() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~\n" << endl;
}

void Utilitario::mostrarNombresDePersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	Lista<string>* claves = diccionarioDePersonajes->obtenerClaves();
	claves->reiniciar();

	cout << "~~~~~~~~~~~~ Personajes ~~~~~~~~~~~~" << endl;
	while(claves->haySiguiente()) {
		Personaje* personaje = diccionarioDePersonajes->obtenerDato(claves->siguiente());
		cout << personaje->obtenerNombre() << endl << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

Personaje* Utilitario::obtenerPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	string nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	return diccionarioDePersonajes->obtenerDato(nombre);

}

void Utilitario::buscarPersonajePorNombre(Diccionario<string, Personaje*>* diccionarioDePersonajes) {


	Personaje* personaje = obtenerPersonaje(diccionarioDePersonajes);

	if (!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		mostrarPersonaje(personaje);
	}

}



void Utilitario::agregarNuevoPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {
	string elemento, nombre;

	FabricaDePersonaje fabricaDePersonaje;

	elemento = this->terminal->obtenerDato(TEXTO_SOLICITUD_ELEMENTO);

	this->terminal->validarElemento(elemento, TEXTO_SOLICITUD_ELEMENTO);

	nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	Personaje* personaje;
	if(!diccionarioDePersonajes->pertenece(nombre)) {
		personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre);
		diccionarioDePersonajes->guardar(nombre, personaje);
	} else {
		cout << "El Personaje: " << nombre << ", ya existe." << endl << endl;
	}

}

void Utilitario::eliminarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	string nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	Personaje* personaje = diccionarioDePersonajes->borrar(nombre);

	if(!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		cout << "Se ha eliminado al personaje: " << personaje->obtenerNombre() << endl << endl;
	}

}

void Utilitario::alimentarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	Personaje* personaje = obtenerPersonaje(diccionarioDePersonajes);

	if(!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		cout << personaje->alimentar() << endl << endl;
	}
}

void Utilitario::guardarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {
	ofstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ofstream::trunc);

	Lista<string>* claves = diccionarioDePersonajes->obtenerClaves();
	claves->reiniciar();

	Personaje* personaje;

	while(claves->haySiguiente()) {
		personaje = diccionarioDePersonajes->obtenerDato(claves->siguiente());
		archivo_personajes << personaje->toString() << endl;
	}

	archivo_personajes.close();
}
