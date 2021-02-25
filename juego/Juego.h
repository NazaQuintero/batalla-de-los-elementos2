#ifndef JUEGO_H_
#define JUEGO_H_

#include <string>
#include <iostream>
#include "../tablero/Tablero.h"
#include "../tda/diccionario/Diccionario.h"
#include "../usuario/Usuario.h"
#include "../menu/Menu.h"

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
    bool turnoActual;

	// Metodos

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

    void atacar(int* posAtacante);

    void ataqueFuego();

    void ataqueAgua();

    void ataqueTierra();

    void ataqueAire();

	// Destructor

	~Juego();

};

#endif /* JUEGO_H_ */