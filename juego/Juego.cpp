#include "Juego.h"

Juego::Juego(){
    this->tablero = new Tablero();
    this->personajesDisponibles = new Diccionario<string, Personaje*>();
    this-> personajesElegidos = new Diccionario<string, bool>();
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
    this->menuOpciones[0] = new Menu("opcionesPrincipal.txt");
    this->menuOpciones[1] = new Menu("opcionesSecundario.txt");
    this->turnoMenu[0] = new Menu("opcionesTurno1.txt");
    this->turnoMenu[1] = new Menu("opcionesTurno2.txt");

    string nombreUsuario1 = this->terminal->obtenerDato("Ingrese el nombre del Jugador 1");
    string nombreUsuario2 = this->terminal->obtenerDato("Ingrese el nombre del Jugador 2");

    this->usuario[0] = new Usuario(nombreUsuario1);
    this->usuario[1] = new Usuario(nombreUsuario2);
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

void Juego::atacar(int* posAtacante) {
    Casillero* casilleroAtacante = this->tablero->getCasilleros()->obtener(posAtacante[0],posAtacante[1]);
    string elemento = casilleroAtacante->getPersonaje()->obtenerElemento();

    if(elemento == "fuego") {
        ataqueFuego();
    } else if(elemento == "agua") {
        //ataqueAgua();
    } else if(elemento == "tierra") {
        //ataqueTierra();
    } else {
        //ataqueAire();
    }
}

void Juego::ataqueFuego() {

}

void Juego::ataqueAgua() {
    cout << "Ingrese las coordenadas del casillero al que desea atacar..." << endl;
    int posAtacarX = this->terminal->obtenerDatoEntero("X:","");
    int posAtacarY = this->terminal->obtenerDatoEntero("Y:","");

    Personaje* personajeAtacar = this->tablero->getCasilleros()->obtener(posAtacarX,posAtacarY)->getPersonaje();

    if(!this->personajesElegidos->pertenece(personajeAtacar->obtenerNombre())) {
        if(personajeAtacar->obtenerElemento() == "fuego") {
            personajeAtacar->bajarVida(30);
        } else if(personajeAtacar->obtenerElemento() == "tierra") {
            personajeAtacar->bajarVida(10);
        } else {
            personajeAtacar->bajarVida(20);
        }
    }
}

void Juego::ataqueTierra() {

}

void Juego::ataqueAire() {

}

Juego::~Juego() {

}