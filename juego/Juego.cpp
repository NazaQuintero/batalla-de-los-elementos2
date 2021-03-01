#include "Juego.h"
#include <cmath>


Juego::Juego(){
    this->tablero = new Tablero();
    this->personajesDisponibles = new Diccionario<string, Personaje*>();
    this->personajesElegidos = new Diccionario<string, Personaje*>();
    this->utilitario = Utilitario::obtenerInstancia();
    this->terminal = Terminal::obtenerInstancia();
    this->menuOpciones[0] = new Menu("opcionesPrincipal.txt");
    this->menuOpciones[1] = new Menu("opcionesSecundario.txt");
    this->turnoMenu[0] = new Menu("opcionesTurno1.txt");
    this->turnoMenu[1] = new Menu("opcionesTurno2.txt");

    this->utilitario->cargarPersonajes(personajesDisponibles);

    string nombreUsuario1 = this->terminal->obtenerDato("Ingrese el nombre del Jugador 1");
    string nombreUsuario2 = this->terminal->obtenerDato("Ingrese el nombre del Jugador 2");

    this->usuario[0] = new Usuario(tablero, personajesDisponibles, nombreUsuario1);
    this->usuario[1] = new Usuario(tablero, personajesDisponibles, nombreUsuario2);

    cout << "User1: " + this->usuario[0]->getNombre() << endl;
    cout << "User2: " + this->usuario[1]->getNombre() << endl;

    this->turnoActual = 0; // TODO: Hacer que sea random
    this->contadorDeTurnos = 0;

    this->grafoAgua = new Grafo<Casillero*, int>(COSTOS_AGUA);
    this->grafoTierra = new Grafo<Casillero*, int>(COSTOS_TIERRA);
    this->grafoFuego = new Grafo<Casillero*, int>(COSTOS_FUEGO);
    this->grafoAire = new Grafo<Casillero*, int>(COSTOS_AIRE);

    inicializarGrafos(tablero, grafoAgua, grafoTierra, grafoAire, grafoFuego);

}

int Juego::jugar(Usuario** usuarios, int turnoActual) {
	Menu* menuTurno1 = this->getMenuTurno1();
	Menu* menuTurno2 = this->getMenuTurno2();

	int systemResult;

	int opcion1;
	int opcion2;



	for(int i = 0; i < 3; i++){

		this->utilitario->limpiarPantalla();

		Usuario* usuario = usuarios[turnoActual];
		cout << "Es el turno de: " << usuario->getNombre() << endl << endl;
		utilitario->mostrarNombresDePersonajes(usuarios[turnoActual]->obtenerPersonajesElegidos());
		Personaje* personaje = this->utilitario->obtenerPersonaje(usuarios[turnoActual]->obtenerPersonajesElegidos());

		utilitario->mostrarPersonaje(personaje);

		menuTurno1->mostrarOpciones();

		string textoSolicitud = "Por favor " + usuarios[turnoActual]->getNombre() + ", elija una opcion:";

		opcion1 = menuTurno1->obtenerOpcion(textoSolicitud);

		switch(opcion1) {
			case 1:
				systemResult = this->utilitario->limpiarPantalla();
				utilitario->alimentarPersonaje(personaje);
				sleep(3);
				break;
			case 2:
				systemResult = this->utilitario->limpiarPantalla();
				this->tablero->mostrarTablero();
				this->mover(personaje);
				break;
			default:
				systemResult = this->utilitario->limpiarPantalla();
				cout << "Usted ha saltado estas opciones ..." << endl << endl;
				sleep(3);
				break;
		}
		this->utilitario->limpiarPantalla();
		utilitario->mostrarNombresDePersonajes(usuarios[turnoActual]->obtenerPersonajesElegidos());
		utilitario->mostrarPersonaje(personaje);
		menuTurno2->mostrarOpciones();
		opcion2 = menuTurno2->obtenerOpcion(textoSolicitud);
		switch(opcion2) {
			case 1:
				systemResult = this->utilitario->limpiarPantalla();
				defensa(personaje);
				sleep(2);
				break;
			case 2:
				systemResult = this->utilitario->limpiarPantalla();
				cout << "Usted esta a punto de atacar" << endl;
				atacar(personaje);
				sleep (3);
				break;
			default:
				systemResult = this->utilitario->limpiarPantalla();
				cout << "Han finalizado sus turnos por este personaje" << endl << endl;
				sleep(3);
				break;
		}


	}
	return systemResult;
}

void Juego::guardarJuego() {
    this->utilitario->guardarJuego(this->personajesElegidos, this->turnoActual);
}

/**
 * TERMINAR
 * */
void Juego::cargarJuego(){
    
};

void Juego::cambiarTurno(){
    this->turnoActual = !this->turnoActual;
};

Menu* Juego::getMenuPrincipal() {
	return this->menuOpciones[0];
}

Menu* Juego::getMenuSecundario() {
	return this->menuOpciones[1];
}

Menu* Juego::getMenuTurno1() {
	return this->turnoMenu[0];
}

Menu* Juego::getMenuTurno2() {
	return this->turnoMenu[1];
}

Diccionario<string, Personaje*>* Juego::getPersonajesDisponibles() {
	return this->personajesDisponibles;
}

void Juego::iniciarJuego() {
	Menu* menuSecundario = this->getMenuSecundario();
	menuSecundario->mostrarOpciones();
	int opcion = menuSecundario->obtenerOpcion("Elija una opcion:");
	validarOpcionSecundario(opcion, this->personajesDisponibles, "Por favor, ingrese una opcion para continuar:", this->menuOpciones[1]);
	ejecutarOpcionSecundario(opcion, personajesDisponibles);
}

int Juego::ejecutarOpcionPrincipal(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes) {
	int systemResult = 0;
	switch (opcion) {
		case 1:
			systemResult = this->utilitario->limpiarPantalla();
			utilitario->agregarNuevoPersonaje(diccionarioDePersonajes);
			break;
		case 2:
			utilitario->eliminarPersonaje(diccionarioDePersonajes);
			break;
		case 3:
			systemResult = this->utilitario->limpiarPantalla();
			utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
			break;
		case 4:
			utilitario->buscarPersonajePorNombre(diccionarioDePersonajes);
			break;
		case 5:
			iniciarJuego();
			break;
		default:
			systemResult = this->utilitario->limpiarPantalla();
			cout << "La opcion ingresada no es correcta." << endl << endl;
			break;
	}
	return systemResult;
}

int Juego::validarOpcionPrincipal(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes, string textoSolicitud, Menu* menu) {
	int systemResult = 0;
	while(opcion != ULTIMA_OPCION) {

		systemResult = ejecutarOpcionPrincipal(opcion, diccionarioDePersonajes);

		menu->mostrarOpciones();

		opcion = menu->obtenerOpcion(textoSolicitud);
	}
	return systemResult;
}

int Juego::ejecutarOpcionSecundario(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes) {
	int systemResult = 0;
		switch (opcion) {
			case 1:
				systemResult = this->utilitario->limpiarPantalla();
				utilitario->buscarPersonajePorNombre(diccionarioDePersonajes);
				break;
			case 2:
				utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
				break;
			case 3:
				systemResult = this->utilitario->limpiarPantalla();
				for (int i = 0; i < 3; i++) {
					seleccionarPersonaje(diccionarioDePersonajes, this->usuario, turnoActual);
					seleccionarPersonaje(diccionarioDePersonajes, this->usuario, !turnoActual);
				}
				for (int i = 0; i < 3; i++) {
					posicionarPersonaje(this->usuario, turnoActual);
					/*this->tablero->mostrarTablero();*/
					posicionarPersonaje(this->usuario, !turnoActual);
					/*this->tablero->mostrarTablero();*/
				}
				this->tablero->mostrarTablero();
				sleep(4);
				jugar(this->usuario, turnoActual);
				jugar(this->usuario, !turnoActual);
				return systemResult;
			default:
				systemResult = this->utilitario->limpiarPantalla();
				cout << "La opcion ingresada no es correcta." << endl << endl;
				break;
		}
		return systemResult;
}

void Juego::posicionarPersonaje(Usuario** usuarios, int turnoActual) {
	this->utilitario->limpiarPantalla();
	this->tablero->mostrarTablero();
	cout << "###############################################################" << endl;
	cout << "Es el turno de: " + this->usuario[turnoActual]->getNombre() << endl << endl;

	utilitario->mostrarNombresDePersonajes(usuarios[turnoActual]->obtenerPersonajesElegidos());
	Personaje* personajeElegido = this->utilitario->obtenerPersonaje(usuarios[turnoActual]->obtenerPersonajesElegidos());

	cout << "Ingrese las coordenadas del casillero en que desea posicionar su personaje:" << endl;
	int posX = this->terminal->obtenerDatoEntero("X:","El valor ingresado debe ser un numero");
	int posY = this->terminal->obtenerDatoEntero("Y:","El valor ingresado debe ser un numero");

	bool corte = false;
	while (!corte) {

		if(!this->tablero->getCasilleros()->obtener(posX, posY)->getPersonaje()) {
			personajeElegido->setPosicion(posX, posY);
			this->tablero->posicionarPersonaje(posX, posY, personajeElegido);
			corte = true;
		} else {
			cout << "Ya existe un personaje en esa posicion..." << endl;
			cout << "Ingrese otras coordenadas del casillero para posicionar a: " << personajeElegido->obtenerNombre() << endl;
			posX = this->terminal->obtenerDatoEntero("X:","El valor ingresado debe ser un numero");
			posY = this->terminal->obtenerDatoEntero("Y:","El valor ingresado debe ser un numero");
		}

	}

}


int Juego::validarOpcionSecundario(int opcion, Diccionario<string, Personaje*> *diccionarioDePersonajes, string textoSolicitud, Menu* menu) {
	int systemResult = 0;
		while(opcion != 4 && systemResult != 666) {

			systemResult = ejecutarOpcionSecundario(opcion, diccionarioDePersonajes);

			menu->mostrarOpciones();

			opcion = menu->obtenerOpcion(textoSolicitud);
		}
	return systemResult;
}

void Juego::mostrarMenuPrincipal(){
    this->menuOpciones[0]->mostrarOpciones();
};
    
void Juego::mostrarMenuSecundario(){
    this->menuOpciones[1]->mostrarOpciones();
};

void Juego::mostrarMenuTurno1() {
	this->turnoMenu[0]->mostrarOpciones();
}

void Juego::mostrarMenuTurno2() {
	this->turnoMenu[1]->mostrarOpciones();
}

void Juego::mostrarTablero() {
	this->tablero->mostrarTablero();
}

void Juego::mostrarNombrePersonajes() {
	this->utilitario->mostrarNombresDePersonajes(personajesDisponibles);
}

void Juego::insertarVerticesGrafo(Tablero* tablero, Grafo<Casillero*, int>* grafo) {

	Matriz<Casillero*>* casilleros = tablero->getCasilleros();

	Diccionario<string, int>* costosAgua = grafo->obtenerCostos();

	for(int i = 0; i < tablero->getCantidadDeCasillerosPorFila(); i++) {
		for(int j = 0; j < tablero->getCantidadDeCasillerosPorFila(); j++) {
			string terreno = casilleros->obtener(i, j)->getTerreno();
			int peso = costosAgua->obtenerDato(terreno);
			grafo->insertarVertice(casilleros->obtener(i, j), peso);
		}
	}
}

void Juego::inicializarGrafos(Tablero* tablero, Grafo<Casillero*, int>* grafoAgua, Grafo<Casillero*, int>* grafoTierra , Grafo<Casillero*, int>* grafoAire, Grafo<Casillero*, int>* grafoFuego) {
	insertarVerticesGrafo(this->tablero, this->grafoAgua);
	insertarVerticesGrafo(this->tablero, this->grafoTierra);
	insertarVerticesGrafo(this->tablero, this->grafoFuego);
	insertarVerticesGrafo(this->tablero, this->grafoAire);

	this->grafoAgua->generarMatrizDeAdyacencia();
	this->grafoAgua->inicializarMatrizDeRecorrido();

	this->grafoTierra->generarMatrizDeAdyacencia();
	this->grafoTierra->inicializarMatrizDeRecorrido();

	this->grafoFuego->generarMatrizDeAdyacencia();
	this->grafoFuego->inicializarMatrizDeRecorrido();

	this->grafoAire->generarMatrizDeAdyacencia();
	this->grafoAire->inicializarMatrizDeRecorrido();


	this->grafoAgua->floydWarshall();
	this->grafoTierra->floydWarshall();
	this->grafoFuego->floydWarshall();
	this->grafoAire->floydWarshall();
}

void Juego::seleccionarPersonaje(Diccionario<string, Personaje*> *diccionarioDePersonajes, Usuario** usuarios, int turnoActual) {
	this->utilitario->limpiarPantalla();
	Usuario* usuario = usuarios[turnoActual];
	cout << "Es el turno de: " << usuario->getNombre() << endl << endl;
	this->utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
	Personaje* personajeElegido = this->utilitario->obtenerPersonaje(diccionarioDePersonajes);
	string nombre = personajeElegido->obtenerNombre();


	bool corte = false;
	while (!corte) {
		bool lePerteneceAlContrincante = usuarios[!turnoActual]->obtenerPersonajesElegidos()->pertenece(nombre);
		bool mePertenece = usuarios[turnoActual]->obtenerPersonajesElegidos()->pertenece(nombre);
		if(!mePertenece && !lePerteneceAlContrincante) {
			usuario->obtenerPersonajesElegidos()->guardar(nombre, personajeElegido);
			this->personajesElegidos->guardar(nombre, personajeElegido);
			corte = true;
		} else {
			cout << "El personaje " << nombre << " ya fue seleccionado" << endl;
			cout << "Por favor " << usuario->getNombre() << " seleccione otro personaje:" << endl;
			this->utilitario->mostrarNombresDePersonajes(diccionarioDePersonajes);
			personajeElegido = this->utilitario->obtenerPersonaje(diccionarioDePersonajes);
			nombre = personajeElegido->obtenerNombre();
		}
	}


}

void Juego::atacar(Personaje* personajeAtacante) {
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

    int resultadoModulo = modulo(posAtacante, posAtacado);

    if(resultadoModulo <= 2){
        estaEnRango = 2;
    }else if(2 < resultadoModulo && resultadoModulo <= 4){
        estaEnRango = 4;
    }else if(4 < resultadoModulo && resultadoModulo <= 6){
        estaEnRango = 6;
    }

    return estaEnRango;
}

void Juego::ataqueFuego(int* posAtacante) {

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
    cout << "Me estoy defendindo por lo tanto recupero 10 de vida" << endl;
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
    cout << "Me defendi :( " << endl;
    
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

    int posFinal[2];
    posFinal[0] = posX;
    posFinal[1] = posY;
    
    int* posInicial = personaje->getPosicion();
    int costoEnergia;
    Matriz<Casillero*>* casilleros = this->tablero->getCasilleros();
    Casillero* casilleroViejo = casilleros->obtener(posInicial[0], posInicial[1]);
    Casillero* casilleroNuevo = casilleros->obtener(posX, posY);
    
    if(!casilleroNuevo->getPersonaje()){
        obtenerCamino(personaje, pilaCamino, posFinal, costoEnergia);
        if(personaje->obtenerEnergia() >= costoEnergia){
            casilleroViejo->setPersonaje(nullptr);
            while (!pilaCamino->vacia()){
                Casillero* casillero = pilaCamino->consulta(1); // Desapila un elemento
                pilaCamino->baja(1);
                casillero->setPersonajePasajero(personaje);
                sleep(1);
                this->utilitario->limpiarPantalla();
                this->tablero->mostrarTablero();
                casillero->setPersonajePasajero(nullptr);
            }
            personaje->setPosicion(posX, posY);
            casilleroNuevo->setPersonaje(personaje);
        }
    }
}

Matriz<Vertice<Casillero*, int>*>* Juego::obtenerMatrizDeRecorrido(Personaje* personaje) {
    string elemento = personaje->obtenerElemento();
    if(elemento == "agua") {
        return this->grafoAgua->getMatrizDeRecorridos();
    } else if (elemento == "aire") {
        return this->grafoAire->getMatrizDeRecorridos();
    } else if (elemento == "tierra") {
        return this->grafoTierra->getMatrizDeRecorridos();
    } else {
        return this->grafoFuego->getMatrizDeRecorridos();
    }
}

Matriz<Arista<int>*>* Juego::obtenerMatrizDeAdyacencia(Personaje* personaje) {
    string elemento = personaje->obtenerElemento();
    if(elemento == "agua") {
        return this->grafoAgua->getMatrizDeAdyacencia();
    } else if (elemento == "aire") {
        return this->grafoAire->getMatrizDeAdyacencia();
    } else if (elemento == "tierra") {
        return this->grafoTierra->getMatrizDeAdyacencia();
    } else {
        return this->grafoFuego->getMatrizDeAdyacencia();
    }
}

void Juego::obtenerCamino(Personaje* personaje, Lista<Casillero*>* pilaCamino, int* posFinal, int &costoEnergia) {
    int* posInicial = personaje->getPosicion();

    if(posInicial == posFinal){
        return;
    }

    cout << "NO PROBLEM" << endl;

    Casillero* casillero = tablero->getCasilleros()->obtener(posFinal[0], posFinal[1]);
    pilaCamino->alta(casillero, 1);
    Matriz<Vertice<Casillero*, int>*>* matrizDeRecorrido = obtenerMatrizDeRecorrido(personaje);
    Matriz<Arista<int>*>* matrizDeAdyacencia = obtenerMatrizDeAdyacencia(personaje);
    
    int posicionTranscriptaInicial = transcribirPosicion(posInicial);
    int posicionTranscriptaFinal = transcribirPosicion(posFinal);
    casillero = matrizDeRecorrido->obtener(posicionTranscriptaInicial, posicionTranscriptaFinal)->getData();
    int peso = matrizDeAdyacencia->obtener(posicionTranscriptaInicial, posicionTranscriptaFinal)->getPeso();
    costoEnergia += peso;
    return obtenerCamino(personaje, pilaCamino, casillero->getPos(), costoEnergia);
}


Juego::~Juego() {

}
