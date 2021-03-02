#include "Usuario.h"

Usuario::Usuario(){
    this->nombre = nombre;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
    this->personajesElegidos = new Diccionario<string, Personaje*>();
}

Usuario::Usuario(string nombre){
    this->nombre = nombre;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
    this->personajesElegidos = new Diccionario<string, Personaje*>();
}

Usuario::Usuario(Tablero* tablero, Diccionario<string, Personaje*>* diccionario, string nombre) {
    this->tablero = tablero;
    this->personajesElegidos = diccionario;
    this->nombre = nombre;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
    this->personajesElegidos = new Diccionario<string, Personaje*>();
}

Diccionario<string, Personaje*>* Usuario::obtenerPersonajesElegidos() {
    return this->personajesElegidos;
}

void Usuario::ejecutarAlimentar(Personaje* personajeAlimentar) {
    personajeAlimentar->alimentar();
    
}

string Usuario::getNombre() {
	return this->nombre;
}

void Usuario::finalizarTurno() {
}

Usuario::~Usuario() {

}
