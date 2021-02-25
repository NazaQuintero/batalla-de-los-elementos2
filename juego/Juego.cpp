#include "Juego.h"

Juego::Juego(){
    this->tablero = new Tablero();
    this->personajesDisponibles = new Diccionario<string, Personaje*>();
    this-> personajesElegidos = new Diccionario<string, bool>();
    this->utilitario = Utilitario::obtenerInstancia();
    this->menuOpciones[0] = new Menu("opcionesPrincipal.txt");
    this->menuOpciones[1] = new Menu("opcionesSecundario.txt");
    this->turnoMenu[0] = new Menu("opcionesTurno1.txt");
    this->turnoMenu[1] = new Menu("opcionesTurno2.txt");
    this-> usuario[0] = new Usuario(nombreUsuario1);
    this-> usuario[1] = new Usuario(nombreUsuario2);
}

bool Juego::guardarJuego(){
    
}

void Juego::cargarJuego(){

};

void Juego::cambiarTurno(){

};

void Juego::mostrarMenuSecundario(){

};
    
void Juego::mostrarMenuSecundario(){

};

bool Juego::validarTurnos(){

};