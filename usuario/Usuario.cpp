#include "Usuario.h"

Usuario::Usuario(){
    this->tablero = &Tablero();
    this->personajesElegidos = &Diccionario<string, Personaje*>();
    this->nombre = nombre;
    this->esTurno = true;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
}

Usuario::Usuario(string nombre){
    this->nombre = nombre;
}

Usuario::Usuario(Tablero* tablero, Diccionario<string, Personaje*>* diccionario, string nombre) {
    this->tablero = tablero;
    this->personajesElegidos = diccionario;
    this->nombre = nombre;
    this->esTurno = true;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
}

Diccionario<string, Personaje*>* Usuario::obtenerPersonajesElegidos() {
    return this->personajesElegidos;
}

void Usuario::ejecutarAlimentar(Personaje* personajeAlimentar) {
    personajeAlimentar->alimentar();
    
}

void Usuario::finalizarTurno() {
    this->esTurno = false;diccionario
}

Usuario::~Usuario() {

}