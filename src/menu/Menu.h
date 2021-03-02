#ifndef MENU_MENU_H_
#define MENU_MENU_H_

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../terminal/Terminal.h"
#include "../utilitario/Utilitario.h"
#include "../tda/lista/lista.h"

using namespace std;

const string NOMBRE_ARCHIVO_OPCIONES = "../opcionesPrincipal.txt";

const int CANTIDAD_DE_LINEAS = 8;
const int PRIMER_OPCION = 1;
const int ULTIMA_OPCION = 6;

class Menu {
private:
	//Atributos privados

	Terminal* terminal;
	Utilitario* utilitario;
	string opciones[CANTIDAD_DE_LINEAS];
	Lista<string>* listaDeOpciones;
	

	//Metodos privados
	void cargarOpciones(string nombreDeArchivo);


public:
	//Atributos

	//Constructor vacio
	Menu();

	Menu(string nombreDeArchivo);

	//Metodos

	virtual ~Menu();

	/**
	 * PRE: Las opciones fueron cargadas desde el archivo 'opciones.txt'.
	 * POS: Muestra por pantalla las opciones al usuario.
	 */
	void mostrarOpciones();

	/**
	 * PRE:
	 * POS: Muestra por pantalla el mensaje recibido en 'texto'. Retorna el numero ingresado por el usuario.
	 */
	int obtenerOpcion(string texto);

	/**
	 * PRE: listaDePersonajes != null, 1 <= opcion <= 6.
	 * POS: Ejecuta la opcion y solicita el ingreso de otra opcion mientras opcion != 6.
	 */
	int validarOpcion(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes, string textoSolicitud);

};

#endif /* MENU_MENU_H_ */
