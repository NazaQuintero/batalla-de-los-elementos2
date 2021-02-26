/*
 * Utilitario.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nazaquintero
 */

#ifndef UTILITARIO_UTILITARIO_H_
#define UTILITARIO_UTILITARIO_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//#include "../tda/lista/lista.h"
#include "../tda/diccionario/Diccionario.h"
#include "../personaje/FabricaDePersonaje.h"
#include "../terminal/Terminal.h"


const string NOMBRE_ARCHIVO_PERSONAJES = "personajes.csv";
const string NOMBRE_ARCHIVO_JUEGO = "mapa.csv";
const int CANTIDAD_DE_DATOS = 4;

const string TEXTO_SOLICITUD_ELEMENTO = "Por favor, ingrese el elemento del Personaje que desea generar (tierra / fuego / agua / aire):";
const string TEXTO_SOLICITUD_NOMBRE = "Ingrese el nombre del Personaje:";
const string TEXTO_SOLICITUD_ESCUDO = "Ingrese el valor del escudo del Personaje (Entero entre " + to_string(MINIMO_VALOR_ESCUDO) + " y " + to_string(MAXIMO_VALOR_ESCUDO) + " inclusive):";
const string FORMATO_DE_ESCUDO = "Por favor, ingrese el valor del escudo (Entero entre " + to_string(MINIMO_VALOR_ESCUDO) + " y " + to_string(MAXIMO_VALOR_ESCUDO) + " inclusive):";
const string TEXTO_SOLICITUD_VIDA = "Ingrese el valor de la vida del Personaje (Entero entre " + to_string(MINIMO_VALOR_VIDA) + " y " + to_string(MAXIMO_VALOR_VIDA) + " inclusive):";
const string FORMATO_DE_VIDA = "Por favor, ingrese el valor de la vida (Entero entre " + to_string(MINIMO_VALOR_VIDA) + " y " + to_string(MAXIMO_VALOR_VIDA) + " inclusive):";

class Utilitario {
private:
	// Atributo privado
	Terminal* terminal;

	// Constructor
	Utilitario();

public:
	// Atributo
	static Utilitario* utilitario;

	// Metodos

	/**
	 * PRE:
	 * POS: Devuelve unica instancia de Utilitario.
	 */
	static Utilitario* obtenerInstancia();

	void split(string cadena, char separador, vector<string> &resultado);

	int limpiarPantalla();

	/**
	 * PRE:
	 * POS: Carga en 'diccionarioDePersonajes' la instancia del personajes correspondiente leido de 'personajes.csv'.
	 */
	void cargarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	void cargarJuego(Diccionario<string, Personaje*>* diccionarioDePersonajesElegidos);

	/**
	 * PRE: personaje != null
	 * POS: Muestra por pantalla los datos del personaje recibido por parametro.
	 */
	void mostrarPersonaje(Personaje* personaje);

	/**
	 * PRE: diccionarioDePersonajes != null
	 * POS: Muestra por pantalla el nombre de cada personaje de 'diccionarioDePersonajes'.
	 */
	void mostrarNombresDePersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE: diccionarioDePersonajes != null
	 * POS: Muestra por pantalla los datos del personaje en caso que se encuentre en 'diccionarioDePersonajes'.
	 * Muestra por pantalla un mensaje de error caso contrario.
	 */
	void buscarPersonajePorNombre(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE: diccionarioDePersonajes != null
	 * POS: Devuelve el Personaje ingresado por consola por el usuario en caso de que exista, 0 caso contrario.
	 */
	Personaje* obtenerPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE:
	 * POS: Agrega en 'diccionarioDePersonajes' el personaje que se creara con los datos ingresados por consola por el usuario.
	 */
	void agregarNuevoPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE: diccionarioDePersonajes != null
	 * POS: Se dara de baja de la 'diccionarioDePersonajes' el personaje correspondiente al nombre ingresado por consola
	 * por el usuario.
	 */
	void eliminarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE: diccionarioDePersonajes != null
	 * POS: Se alimentara al personaje correspondiente al nombre ingresado por consola por el usuario.
	 * Muestra un mensaje de error en caso de que el personaje no se encuentre en la lista.
	 */
	void alimentarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	/**
	 * PRE:
	 * POS: Escribe en 'personajes.csv' los personajes contenidos en 'diccionarioDePersonajes'.
	 */
	void guardarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes);

	void guardarJuego(Diccionario<string, Personaje*>* diccionarioDePersonajes, int turno);

	void imprimirPersonaje(Personaje* personaje);

	// Destructor
	virtual ~Utilitario();

};

#endif /* UTILITARIO_UTILITARIO_H_ */
