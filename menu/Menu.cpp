/*
 * Menu.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#include "Menu.h"

Menu::Menu() {
	this->terminal = Terminal::obtenerInstancia();
	this->utilitario = Utilitario::obtenerInstancia();
	cargarOpciones(NOMBRE_ARCHIVO_OPCIONES);
}

Menu::Menu(string nombreDeArchivo) {
	this->terminal = Terminal::obtenerInstancia();
	this->utilitario = Utilitario::obtenerInstancia();
	cargarOpciones(nombreDeArchivo);
}

Menu::~Menu() {
}

int clearScreen() {
	int result;
	#ifdef __linux__
		result = system("clear");
	#else
		// Assume WINDOWS
		result = system("cls");
	#endif
	return result;
}

void Menu::cargarOpciones(string nombreDeArchivo) {
	fstream archivoDeOpciones(nombreDeArchivo, ios::in);

	if(!archivoDeOpciones.is_open()) {

		cout << "No se encontro un archivo con el nombre \"" << nombreDeArchivo << "\" ." << endl;

	} else {

		string linea;

		int largo = this->listaDeOpciones->obtenerCantidad();
		while(getline(archivoDeOpciones, linea)) {
			this->listaDeOpciones->alta(linea, largo+1);
		}

	}
	archivoDeOpciones.close();
}

void Menu::mostrarOpciones() {

	// for (int i = 0; i < CANTIDAD_DE_LINEAS; ++i) {
	// 	if(i == 0 || i == CANTIDAD_DE_LINEAS - 1) {
	// 		cout << opciones[i] << endl << endl;
	// 	} else {
	// 		cout << opciones[i] << endl;
	// 	}
	// }
	this->listaDeOpciones->reiniciar();
	while(this->listaDeOpciones->haySiguiente()) {
		cout << this->listaDeOpciones->siguiente() << endl;
	}

}

int Menu::obtenerOpcion(string texto) {
	return this->terminal->leerNumero(texto, PRIMER_OPCION, ULTIMA_OPCION);
}

int Menu::validarOpcion(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes, string textoSolicitud) {
	int systemResult = 0;
	while(opcion != ULTIMA_OPCION) {

		systemResult = ejecutarOpcion(opcion, diccionarioDePersonajes);

		mostrarOpciones();

		opcion = obtenerOpcion(textoSolicitud);
	}
	return systemResult;
}

int Menu::ejecutarOpcion(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes) {
	int systemResult = 0;
	switch (opcion) {
		case 1:
			systemResult = clearScreen();
			utilitario->agregarNuevoPersonaje(diccionarioDePersonajes);
			break;
		case 2:
			utilitario->eliminarPersonaje(diccionarioDePersonajes);
			break;
		case 3:
			systemResult = clearScreen();
			utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
			break;
		case 4:
			utilitario->buscarPersonajePorNombre(diccionarioDePersonajes);
			break;
		case 5:
			utilitario->alimentarPersonaje(diccionarioDePersonajes);
			break;
		default:
			systemResult = clearScreen();
			cout << "La opcion ingresada no es correcta." << endl << endl;
			break;
	}
	return systemResult;
}

