#ifndef JUEGO_H_
#define JUEGO_H_

#include <string>
#include <iostream>
#include "../tablero/Tablero.h"
#include "../tda/diccionario/Diccionario.h"
#include "../tda/grafo/Grafo.h"
#include "../usuario/Usuario.h"
#include "../menu/Menu.h"
#include "math.h"

using namespace std;

const string COSTOS_AGUA = "costosAgua.csv";
const string COSTOS_TIERRA = "costosTierra.csv";
const string COSTOS_FUEGO = "costosFuego.csv";
const string COSTOS_AIRE = "costosAire.csv";

class Juego {

private:
	// Atributos
    Tablero* tablero;
    Diccionario<string, Personaje*>* personajesDisponibles;
    Diccionario<string, bool>* personajesElegidos;
    Utilitario* utilitario;
    Menu* turnoMenu[];
    Menu* menuOpciones[];
    Usuario* usuario[];
    Terminal* terminal;
    Grafo<Casillero*, int>* grafoAgua;
    Grafo<Casillero*, int>* grafoTierra;
    Grafo<Casillero*, int>* grafoFuego;
    Grafo<Casillero*, int>* grafoAire;
    int turnoActual;
    int contadorDeTurnos;

	// Metodos
    int modulo(int* posAtacante, int* posAtacado);

    bool estaEnRangoDeFuego(int* posAtacante, int* posAtacado);

    int estaEnRangoDeTierra(int* posAtacante, int* posAtacado);

    Matriz<Vertice<Casillero*, int>*>* obtenerMatrizDeRecorrido(Personaje* personaje);

    Matriz<Arista<int>*>* obtenerMatrizDeAdyacencia(Personaje* personaje);

public:
	// Constructor

	Juego();

	// Metodos

    bool guardarJuego(); //bool?

    void cargarJuego();

    void cambiarTurno();

    void mostrarMenuPrincipal();
    
    void mostrarMenuSecundario();

    bool validarTurnos(); //bool?

    void atacar(Personaje* personajeAtacante);

    void ataqueFuego(int* posAtacante);

    void ataqueAgua();

    void ataqueTierra(int* posAtacante);

    void ataqueAire();


    void defensa(Personaje* personaje);

    void defensaFuego(Personaje* personaje);

    void defensaAgua(Personaje* personaje);

    void defensaTierra(Personaje* personaje);

    void defensaAire(Personaje* personaje);

    void mover(Personaje* personaje);

    int transcribirPosicion(int* posicion);

    void obtenerCamino(Personaje* personaje, Lista<Casillero*>* pilaCamino, int* posFinal, int &costoEnergia);

	// Destructor

	~Juego();

};

#endif /* JUEGO_H_ */