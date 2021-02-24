#include "usuario.h"

Usuario::Usuario(Tablero* tablero, Diccionario<string, Personaje*>* diccionario, string nombre) {
    this->tablero = tablero;
    this->personajesElegidos = diccionario;
    this->nombre = nombre;
    this->esTurno = true;
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
}

void Usuario::ejecutarAlimentar(Personaje* personajeAlimentar) {
    personajeAlimentar->alimentar();
    
}

void Usuario::ejecutarDefender(Personaje* personajeDefender) {
    //personajeDefender->defender();
}

void Usuario::ejecutarAtacar(Personaje* personajeAtacante) {
    //personajeAtacante.atacar();
}

void Usuario::finalizarTurno() {
    this->esTurno = false;
}

Usuario::~Usuario() {

}