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
	this->listaDeOpciones = new Lista<string>();
	cargarOpciones(NOMBRE_ARCHIVO_OPCIONES);
}

Menu::Menu(string nombreDeArchivo) {
	this->terminal = Terminal::obtenerInstancia();
	this->utilitario = Utilitario::obtenerInstancia();
	this->listaDeOpciones = new Lista<string>();
	cargarOpciones(nombreDeArchivo);
}

Menu::~Menu() {
}

void Menu::cargarOpciones(string nombreDeArchivo) {
	fstream archivoDeOpciones(nombreDeArchivo, ios::in);

	if(!archivoDeOpciones.is_open()) {

		cout << "No se encontro un archivo con el nombre \"" << nombreDeArchivo << "\" ." << endl;

	} else {

		string linea;

		/*int largo = this->listaDeOpciones->obtenerCantidad();*/
		/*cout << "El largo es: " << largo << endl << endl<< endl;*/
		while(getline(archivoDeOpciones, linea)) {
			/*largo = this->listaDeOpciones->obtenerCantidad();*/
			/*cout << "El largo es: " << largo << endl;
			cout << linea << endl;*/
			this->listaDeOpciones->alta(linea, 1);
		}

	}
	archivoDeOpciones.close();
}

void Menu::mostrarOpciones() {

	int largo = this->listaDeOpciones->obtenerCantidad();

	for(int i = largo; i > 0; i--) {
		cout << this->listaDeOpciones->consulta(i) << endl;
	}

}

int Menu::obtenerOpcion(string texto) {
	return this->terminal->leerNumero(texto, PRIMER_OPCION, ULTIMA_OPCION);
}

/*int Menu::validarOpcion(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes, string textoSolicitud) {
	int systemResult = 0;
	while(opcion != ULTIMA_OPCION) {

		systemResult = ejecutarOpcion(opcion, diccionarioDePersonajes);

		mostrarOpciones();

		opcion = obtenerOpcion(textoSolicitud);
	}
	return systemResult;
}*/

/*int Menu::ejecutarOpcion(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes) {
	int systemResult = 0;
	switch (opcion) {
		case 1:
			systemResult = this->utilitario->limpiarPantalla();
			utilitario->agregarNuevoPersonaje(diccionarioDePersonajes);
			break;
		case 2:
			utilitario->eliminarPersonaje(diccionarioDePersonajes);
			break;
		case 3:
			systemResult = this->utilitario->limpiarPantalla();
			utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
			break;
		case 4:
			utilitario->buscarPersonajePorNombre(diccionarioDePersonajes);
			break;
		case 5:
			utilitario->alimentarPersonaje(diccionarioDePersonajes);
			break;
		default:
			systemResult = this->utilitario->limpiarPantalla();
			cout << "La opcion ingresada no es correcta." << endl << endl;
			break;
	}
	return systemResult;
}*/

