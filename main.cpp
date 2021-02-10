//============================================================================
// Name        : Batalla de los elementos
// Author      : Quintero Nazareno 105296
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Batalla de los elementos C++, Ansi-style
//============================================================================

#include "menu/Menu.h"
#include "terminal/Terminal.h"
#include "validaciones/Validador.h"
#include "utilitario/Utilitario.h"

Menu* Menu::menu = 0;
Terminal* Terminal::terminal = 0;
Validador* Validador::validador = 0;
Utilitario* Utilitario::utilitario = 0;

const string TEXTO_SOLICITUD_OPCION = "Por favor, ingrese una opcion para continuar:";

int main() {

	srand(time(0));

	Diccionario<string, Personaje*> *diccionarioDePersonajes = new Diccionario<string, Personaje*>();

	Utilitario* utilitario = Utilitario::obtenerInstancia();

	utilitario->cargarPersonajes(diccionarioDePersonajes);

	Menu* menu = Menu::obtenerInstancia();

	menu->mostrarOpciones();

	int opcion = menu->obtenerOpcion(TEXTO_SOLICITUD_OPCION);

	int systemResult = menu->validarOpcion(opcion, diccionarioDePersonajes, TEXTO_SOLICITUD_OPCION);

	cout << "El sistema ha finalizado con codigo de error: " << systemResult << "." << endl;

	utilitario->guardarPersonajes(diccionarioDePersonajes);

	delete diccionarioDePersonajes;
	delete menu;
	delete utilitario;

	return 0;
}
