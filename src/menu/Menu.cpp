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
		while(getline(archivoDeOpciones, linea)) {
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
