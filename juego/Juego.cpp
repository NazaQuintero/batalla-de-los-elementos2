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

    if(elemento == "fuego" && energia >= 10) {
        defensaFuego(personaje);
    } else if(elemento == "agua" && energia >= 12) {
        defensaAgua(personaje);
    } else if(elemento == "tierra" && energia >= 5) {
        defensaTierra(personaje);
    } else if (energia >= 15) {
        defensaAire(personaje);
    } else {
        cout << "El personaje: " << personaje->obtenerNombre() << " no tiene energia suficiente para defenderse." << endl;
    }

}

void Juego::defensaFuego(Personaje* personaje) {
    personaje->incrementarVida(10);
    personaje->bajarEnergia(10);
}

void Juego::defensaAgua(Personaje* personaje) {
    personaje->incrementarVida(50);

    Diccionario<string, Personaje*>* personajesAliados = this->usuario[this->turnoActual]->obtenerPersonajesElegidos();

    Lista<string>* claves = personajesAliados->obtenerClaves();
	claves->reiniciar();

	while(claves->haySiguiente()) {
		Personaje* personajeAliado = personajesAliados->obtenerDato(claves->siguiente());
        if(personajeAliado != personaje && personajeAliado->obtenerVida() > 0) {
		    personajeAliado->incrementarVida(10);
        }
    }

    personaje->bajarEnergia(12);
}

void Juego::defensaAire(Personaje* personaje) {
    cout << "Ingrese las coordenadas del casillero al que desea mover al personaje..." << endl;
    int posX = this->terminal->obtenerDatoEntero("X:","El valor ingresado debe ser un numero");
    int posY = this->terminal->obtenerDatoEntero("Y:","El valor ingresado debe ser un numero");
    
    int* posVieja = personaje->getPosicion();
    
    Matriz<Casillero*>* casilleros = this->tablero->getCasilleros();
    
    Casillero* casilleroViejo = casilleros->obtener(posVieja[0], posVieja[1]);

    Casillero* casilleroNuevo = casilleros->obtener(posX, posY);

    if (!casilleroNuevo->getPersonaje()) {
        personaje->setPosicion(posX, posY);
        casilleroNuevo->setPersonaje(personaje);
        casilleroViejo->setPersonaje(nullptr);
    }
    
    personaje->bajarEnergia(15);
}

// TODO: defensa tierra
void Juego::defensaTierra(Personaje* personaje) {
    personaje->bajarEnergia(5);
}

int Juego::transcribirPosicion(int* posicion){
    int casilleroTranscripto = posicion[0]*8 + posicion[1];
    return casilleroTranscripto;
}

void Juego::mover(Personaje* personaje){
    Lista<Casillero*>* pilaCamino = new Lista<Casillero*>(); 
    cout << "Ingrese las coordenadas del casillero al que desea mover al personaje..." << endl;
    int posX = this->terminal->obtenerDatoEntero("X:","El valor ingresado debe ser un numero");
    int posY = this->terminal->obtenerDatoEntero("Y:","El valor ingresado debe ser un numero");

    int* posFinal[2];
    *posFinal[0] = posX;
    *posFinal[1] = posY;
    
    int* posInicial = personaje->getPosicion();
    int costoEnergia;
    Matriz<Casillero*>* casilleros = this->tablero->getCasilleros();
    Casillero* casilleroViejo = casilleros->obtener(posInicial[0], posInicial[1]);
    Casillero* casilleroNuevo = casilleros->obtener(posX, posY);
    
    if(!casilleroNuevo->getPersonaje()){
        casilleroViejo->setPersonaje(nullptr);
        obtenerCamino(personaje, pilaCamino, *posFinal, costoEnergia);
        while (!pilaCamino->vacia() && personaje->obtenerEnergia() >= costoEnergia){
            Casillero* casillero = pilaCamino->consulta(1); // Desapila un elemento
            pilaCamino->baja(1);
            //casillero->pintar();
        }
        personaje->setPosicion(posX, posY);
        casilleroNuevo->setPersonaje(personaje);
    }
}

Matriz<Vertice<Casillero*, int>>* Juego::obtenerMatrizDeRecorrido(Personaje* personaje) {
    string elemento = personaje->obtenerElemento();
    if(elemento == "agua") {
        return this->grafoAgua->getMatrizDeRecorridos();
    } else if () {
        return this->grafoAire->getMatrizDeRecorridos();
    }

    grafoAgua
grafoTierra
grafoFuego
grafoAire
    
}

void Juego::obtenerCamino(Personaje* personaje, Lista<Casillero*>* pilaCamino, int* posFinal, int &costoEnergia) {
    int* posInicial = personaje->getPosicion();

    if(posInicial == posFinal){
        return;
    }

    Casillero* casillero = tablero->getCasilleros()->obtener(posFinal[0], posFinal[1]);
    pilaCamino->alta(casillero, 1);
    Matriz<Casillero>* matrizDeRecorrido = 
    


}


Juego::~Juego() {

}