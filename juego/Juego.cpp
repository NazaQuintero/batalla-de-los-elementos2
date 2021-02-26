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
    Usuario* usuarioAtacante = this->usuario[this->turnoActual];
    Casillero* casilleroAtacante = this->tablero->getCasilleros()->obtener(posAtacante[0],posAtacante[1]);
    string elemento = casilleroAtacante->getPersonaje()->obtenerElemento();

    if(elemento == "fuego") {
        ataqueFuego(posAtacante);
    } else if(elemento == "agua") {
        ataqueAgua();
    } else if(elemento == "tierra") {
        ataqueTierra(posAtacante);
    } else {
        ataqueAire();
    }
}

bool Juego::estaEnRangoDeFuego(int* posAtacante, int* posAtacado) {
    bool estaEnRango = false;
    int posAtacanteX, posAtacadoX;
    posAtacanteX = posAtacante[0];
    posAtacadoX = posAtacado[0];

    if(posAtacadoX - 1 == posAtacanteX || posAtacadoX == posAtacanteX || posAtacadoX + 1 == posAtacadoX) {
        estaEnRango = true;
    }
    return estaEnRango;
}

bool Juego::estaEnRangoDeTierra1(int* posAtacante, int* posAtacado) {
    bool estaEnRango = false;
    int posAtacanteX, posAtacadoX;
    posAtacanteX = posAtacante[0];
    posAtacadoX = posAtacado[0];

    if() {
        estaEnRango = true;
    }
    return estaEnRango;
}

bool Juego::estaEnRangoDeTierra2(int* posAtacante, int* posAtacado) {
    bool estaEnRango = false;
    int posAtacanteX, posAtacadoX;
    posAtacanteX = posAtacante[0];
    posAtacadoX = posAtacado[0];

    if() {
        estaEnRango = true;
    }
    return estaEnRango;
}

void Juego::ataqueFuego(int* posAtacante) {

    int posAtacanteX, posAtacanteY;

    posAtacanteX = posAtacante[0];
    posAtacanteY = posAtacante[1];

    Diccionario<string, Personaje*>* personajesOponente = this->usuario[!this->turnoActual]->obtenerPersonajesElegidos();

    Lista<string>* claves = personajesOponente->obtenerClaves();
	claves->reiniciar();

    while(claves->haySiguiente()) {
		Personaje* personajeAtacado = personajesOponente->obtenerDato(claves->siguiente());
        int* posAtacado = personajeAtacado->obtenerPosicion();

        if(estaEnRangoDeFuego(posAtacante, posAtacado)) {
            if(personajeAtacado->obtenerElemento() == "aire") {
		        personajeAtacado->bajarVida(30);
            } else if(personajeAtacado->obtenerElemento() == "agua") {
                personajeAtacado->bajarVida(10);
            } else {
                personajeAtacado->bajarVida(20);
            }
        }
    }
}

void Juego::ataqueAgua() {
    cout << "Ingrese las coordenadas del casillero al que desea atacar..." << endl;
    int posAtacarX = this->terminal->obtenerDatoEntero("X:","El valor ingresado debe ser un numero");
    int posAtacarY = this->terminal->obtenerDatoEntero("Y:","El valor ingresado debe ser un numero");

    Personaje* personajeAtacado = this->tablero->getCasilleros()->obtener(posAtacarX,posAtacarY)->getPersonaje();
    Diccionario<string, Personaje*>* personajesOponente = this->usuario[!this->turnoActual]->obtenerPersonajesElegidos();

    if(personajesOponente->pertenece(personajeAtacado->obtenerNombre())) {
        if(personajeAtacado->obtenerElemento() == "fuego") {
            personajeAtacado->bajarVida(30);
        } else if(personajeAtacado->obtenerElemento() == "tierra") {
            personajeAtacado->bajarVida(10);
        } else {
            personajeAtacado->bajarVida(20);
        }
    }
}

void Juego::ataqueTierra(int *posAtacante) {

    Diccionario<string, Personaje*>* personajesOponente = this->usuario[!this->turnoActual]->obtenerPersonajesElegidos();

    Lista<string>* claves = personajesOponente->obtenerClaves();
	claves->reiniciar();

    while(claves->haySiguiente()) {
		Personaje* personajeAtacado = personajesOponente->obtenerDato(claves->siguiente());
        int* posAtacado = personajeAtacado->obtenerPosicion();

        if(estaEnRangoDeTierra1(posAtacante, posAtacado)) {
            if(personajeAtacado->obtenerElemento() == "agua")
                personajeAtacado->bajarVida(50);
            else
                personajeAtacado->bajarVida(30);
        }else if(estaEnRangoDeTierra2(posAtacante, posAtacado)) {
            if(personajeAtacado->obtenerElemento() == "agua")
                personajeAtacado->bajarVida(40);
            else
                personajeAtacado->bajarVida(20);
        }else{ //rangoTierra3
            if(personajeAtacado->obtenerElemento() == "agua")
                personajeAtacado->bajarVida(30);
            else
                personajeAtacado->bajarVida(10);
        }
    }
}

void Juego::ataqueAire() {
    Diccionario<string, Personaje*>* personajesOponente = this->usuario[!this->turnoActual]->obtenerPersonajesElegidos();

    Lista<string>* claves = personajesOponente->obtenerClaves();
	claves->reiniciar();

	while(claves->haySiguiente()) {
		Personaje* personajeAtacado = personajesOponente->obtenerDato(claves->siguiente());
        if(personajeAtacado->obtenerElemento() == "tierra") {
		    personajeAtacado->bajarVida(20);
        } else if (personajeAtacado->obtenerElemento() == "fuego") {
		    personajeAtacado->bajarVida(10);
        } else {
		    personajeAtacado->bajarVida(15);
        }
	}


}

Juego::~Juego() {

}