#ifndef JUEGO_H_
#define JUEGO_H_

#include <string>
#include <iostream>
#include "../tablero/Tablero.h"
#include "../tda/diccionario/Diccionario.h"
#include "../usuario/Usuario.h"
#include "../menu/Menu.h"
#include "math.h"

using namespace std;

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
    int turnoActual;
    int contadorDeTurnos;

	// Metodos
    int modulo(int* posAtacante, int* posAtacado);

    bool estaEnRangoDeFuego(int* posAtacante, int* posAtacado);

    int estaEnRangoDeTierra(int* posAtacante, int* posAtacado);

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


    void defensa(Personaje* Personaje);

    void defensaFuego(Personaje* Personaje);

    void defensaAgua(Personaje* Personaje);

    void defensaTierra();

    void defensaAire(Personaje* Personaje);

	// Destructor

	~Juego();

};

#endif /* JUEGO_H_ */