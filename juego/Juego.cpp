#include "Juego.h"
#include <cmath>

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


//TODO: //AGREGAR PERDIDAS DE ENERGIA

void Juego::atacar(Personaje* personajeAtacante) {
    //Usuario* usuarioAtacante = this->usuario[this->turnoActual];
    // Casillero* casilleroAtacante = this->tablero->getCasilleros()->obtener(posAtacante[0],posAtacante[1]);
    // Personaje* personaje = casilleroAtacante->getPersonaje();
    string elemento = personajeAtacante->obtenerElemento();
    int* posAtacante = personajeAtacante->getPosicion();
    
    int energia = personajeAtacante->obtenerEnergia(); 

    if(elemento == "fuego" && energia >= 5) {
        ataqueFuego(posAtacante);
        personajeAtacante->bajarEnergia(5);
    } else if(elemento == "agua" && energia >= 5) {
        ataqueAgua();
        personajeAtacante->bajarEnergia(5);
    } else if(elemento == "tierra" && energia >= 6) {
        ataqueTierra(posAtacante);
        personajeAtacante->bajarEnergia(6);
    } else if (energia >= 8) {
        ataqueAire();
        personajeAtacante->bajarEnergia(8);
    } else {
        cout << "El personajeAtacante: " << personajeAtacante->obtenerNombre() << " no tiene energia suficiente para atacar." << endl;
    }
}

int Juego::modulo(int* posAtacante, int* posAtacado){
    int posAtacanteX, posAtacanteY, posAtacadoX, posAtacadoY;

    posAtacanteX = posAtacante[0];
    posAtacanteY = posAtacante[1];
    posAtacadoX = posAtacado[0];
    posAtacadoY = posAtacado[1];

    return (int)sqrt(pow(posAtacanteX - posAtacadoX, 2) + pow(posAtacanteY - posAtacadoY, 2));

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

int Juego::estaEnRangoDeTierra(int* posAtacante, int* posAtacado) {
    int estaEnRango = 0;
    int posAtacanteX, posAtacadoX;
    posAtacanteX = posAtacante[0];
    posAtacadoX = posAtacado[0];

    int resultadoModulo = modulo(posAtacante, posAtacado);

    if(resultadoModulo <= 2){
        estaEnRango == 2;
    }else if(2 < resultadoModulo <= 4){
        estaEnRango = 4;
    }else if(4 < resultadoModulo <= 6){
        estaEnRango = 6;
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
        int* posAtacado = personajeAtacado->getPosicion();

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
        int* posAtacado = personajeAtacado->getPosicion();

        int rango = estaEnRangoDeTierra(posAtacante, posAtacado);

        if(rango == 2) {
            personajeAtacado->bajarVida(30);
        }else if(rango == 4) {
            personajeAtacado->bajarVida(20);
        }else {
            personajeAtacado->bajarVida(10);
        }
        
        if(personajeAtacado->obtenerElemento() == "agua") {
            personajeAtacado->bajarVida(20);
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

void Juego::defensa(Personaje* personaje) {
    string elemento = personaje->obtenerElemento();

    int energia = personaje->obtenerEnergia(); 

    if(elemento == "fuego" && energia >= 5) {
        ataqueFuego(posAtacante);
        personaje->bajarEnergia(5);
    } else if(elemento == "agua" && energia >= 5) {
        ataqueAgua();
        personaje->bajarEnergia(5);
    } else if(elemento == "tierra" && energia >= 6) {
        ataqueTierra(posAtacante);
        personaje->bajarEnergia(6);
    } else if (energia >= 8) {
        ataqueAire();
        personaje->bajarEnergia(8);
    } else {
        cout << "El personaje: " << personaje->obtenerNombre() << " no tiene energia suficiente para atacar." << endl;
    }

}

void Juego::defensaFuego(Personaje* Personaje) {}

void Juego::defensaAgua(Personaje* Personajee) {}

void Juego::defensaAire(Personaje* Personaje) {}

void Juego::defensaTierra() {}

Juego::~Juego() {

}