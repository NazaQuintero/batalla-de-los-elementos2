#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>
#include <iostream>
#include "../validaciones/Validador.h"
#include "../tablero/Tablero.h"
#include "../tda/diccionario/Diccionario.h"
#include "personaje/Personaje.h"
#include "utilitario/Utilitario.h"

using namespace std;

class Usuario {

private:
	// Atributos
    Tablero* tablero;
    Utilitario* utilitario;
    Terminal* terminal;
    Diccionario<string, Personaje*>* personajesElegidos;
    string nombre;
    bool esTurno;

	// Metodos


public:
	// Constructor

    Usuario();

    Usuario(string nombre);

	Usuario(Tablero* tablero, Diccionario<string, Personaje*>* diccionario, string nombre);

	// Metodos

    Diccionario<string, Personaje*>* obtenerPersonajesElegidos();

    void ejecutarAtacar(Personaje* personajeAtacante);

    void ejecutarMover();

    void ejecutarDefender(Personaje* personajeDefender);

    void ejecutarAlimentar(Personaje* personajeAlimentar);

    void finalizarTurno();
    
    void seleccionarPersonaje();
	
	// string toString();

	// Destructor

	~Usuario();

};

#endif /* USUARIO_H_ */