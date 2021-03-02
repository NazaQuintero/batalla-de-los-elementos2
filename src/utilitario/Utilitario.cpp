#include "Utilitario.h"

Utilitario::Utilitario() {
	this->terminal = Terminal::obtenerInstancia();
}

Utilitario::~Utilitario() {
	delete this->terminal;
}

Utilitario* Utilitario::obtenerInstancia() {

	if(!utilitario)
		utilitario = new Utilitario();

	return utilitario;

}

void Utilitario::split(string str, char sep, vector<string> &resultado) {

	istringstream f(str);
	string s;

	while(getline(f, s, sep)) {
		resultado.push_back(s);
	}

}

int Utilitario::limpiarPantalla() {
	int result;
	#ifdef __linux__
		result = system("clear");
	#else
		// Assume WINDOWS
		result = system("cls");
	#endif
	return result;
}

void Utilitario::cargarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	fstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ios::in);

	if(!archivo_personajes.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_PERSONAJES << "\", se va a crear el archivo" << endl;
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::out);
		archivo_personajes.close();
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::in);
	}

	string linea;
	string elemento, nombre, escudoStr, vidaStr;
	int escudo, vida;

	vector<string> datos;

	while(archivo_personajes >> linea) {

		split(linea, ',', datos);

		elemento = datos[0];
		nombre = datos[1];
		escudoStr = datos[2];
		vidaStr = datos[3];

		escudo = stol(escudoStr);
		vida = stol(vidaStr);

		FabricaDePersonaje fabricaDePersonaje;

		Personaje* personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre, escudo, vida);

		datos.clear();

		if(!diccionarioDePersonajes->pertenece(nombre)) {
			diccionarioDePersonajes->guardar(nombre, personaje);
		} else {
			cout << "El personaje: " << nombre << " ya fue creado anteriormente." << endl;
		}


	}

	archivo_personajes.close();

}


void Utilitario::cargarJuego(Diccionario<string, Personaje*>* diccionarioDePersonajesElegidos) {

	fstream archivo_juego(NOMBRE_ARCHIVO_JUEGO, ios::in);

	if(!archivo_juego.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_JUEGO << "\", se va a crear el archivo" << endl;
		archivo_juego.open(NOMBRE_ARCHIVO_JUEGO, ios::out);
		archivo_juego.close();
		archivo_juego.open(NOMBRE_ARCHIVO_JUEGO, ios::in);
	}

	string linea;
	string elemento, nombre, escudoStr, vidaStr, turnoStr, posXStr, posYStr;
	int escudo, vida, /*turno,*/ posX, posY;

	archivo_juego >> turnoStr;

	vector<string> datos;

	while(archivo_juego >> linea) {

		split(linea, ',', datos);

		elemento = datos[0];
		nombre = datos[1];
		escudoStr = datos[2];
		vidaStr = datos[3];
		posXStr = datos[4];
		posYStr = datos[5];

		escudo = stol(escudoStr);
		vida = stol(vidaStr);
		posX = stol(posXStr);
		posY = stol(posYStr);

		FabricaDePersonaje fabricaDePersonaje;

		Personaje* personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre, escudo, vida, posX, posY);

		datos.clear();

		if(!diccionarioDePersonajesElegidos->pertenece(nombre)) {
			diccionarioDePersonajesElegidos->guardar(nombre, personaje);
		} else {
			cout << "El personaje: " << nombre << " ya fue creado anteriormente." << endl;
		}


	}

	archivo_juego.close();

}

void Utilitario::mostrarPersonaje(Personaje* personaje) {
	cout << "~~~~ Personaje ~~~~" << endl;
	cout << "Elemento: " << personaje->obtenerElemento() << "\nNombre: " << personaje->obtenerNombre() << "\nEscudo: " << personaje->obtenerEscudo() << "\nVida: " << personaje->obtenerVida() << "\nEnergia: " << personaje->obtenerEnergia() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~\n" << endl;
}

void Utilitario::imprimirPersonaje(Personaje* personaje) {

	string nombrePersonaje = personaje->obtenerNombre();

	cout << personaje->getColorIni() << nombrePersonaje << personaje->getColorFin() << endl;
}

void Utilitario::mostrarNombresDePersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	Lista<string>* claves = diccionarioDePersonajes->obtenerClaves();
	claves->reiniciar();

	cout << "~~~~~~~~~~~~ Personajes ~~~~~~~~~~~~" << endl;
	while(claves->haySiguiente()) {
		Personaje* personaje = diccionarioDePersonajes->obtenerDato(claves->siguiente());
		imprimirPersonaje(personaje);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

Personaje* Utilitario::obtenerPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	string nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);
	Personaje* personaje = diccionarioDePersonajes->obtenerDato(nombre);
	while(!personaje) {
		cout << "El Personaje: " << nombre << " no existe..." << endl;
		nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);
		personaje = diccionarioDePersonajes->obtenerDato(nombre);
	}
	return personaje;

}

void Utilitario::buscarPersonajePorNombre(Diccionario<string, Personaje*>* diccionarioDePersonajes) {


	Personaje* personaje = obtenerPersonaje(diccionarioDePersonajes);

	if (!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		mostrarPersonaje(personaje);
	}

}



void Utilitario::agregarNuevoPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {
	string elemento, nombre;

	FabricaDePersonaje fabricaDePersonaje;

	elemento = this->terminal->obtenerDato(TEXTO_SOLICITUD_ELEMENTO);

	this->terminal->validarElemento(elemento, TEXTO_SOLICITUD_ELEMENTO);

	nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	Personaje* personaje;
	if(!diccionarioDePersonajes->pertenece(nombre)) {
		personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre);
		diccionarioDePersonajes->guardar(nombre, personaje);
	} else {
		cout << "El Personaje: " << nombre << ", ya existe." << endl << endl;
	}

}

void Utilitario::eliminarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	string nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	Personaje* personaje = diccionarioDePersonajes->borrar(nombre);

	if(!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		cout << "Se ha eliminado al personaje: " << personaje->obtenerNombre() << endl << endl;
	}

}

void Utilitario::alimentarPersonaje(Personaje* personaje) {
	cout << personaje->alimentar() << endl << endl;
}

void Utilitario::alimentarPersonaje(Diccionario<string, Personaje*>* diccionarioDePersonajes) {

	Personaje* personaje = obtenerPersonaje(diccionarioDePersonajes);

	if(!personaje) {
		cout << "El Personaje ingresado no existe." << endl << endl;
	} else {
		cout << personaje->alimentar() << endl << endl;
	}
}

void Utilitario::guardarPersonajes(Diccionario<string, Personaje*>* diccionarioDePersonajes) {
	ofstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ofstream::trunc);

	Lista<string>* claves = diccionarioDePersonajes->obtenerClaves();
	claves->reiniciar();

	Personaje* personaje;

	while(claves->haySiguiente()) {
		personaje = diccionarioDePersonajes->obtenerDato(claves->siguiente());
		archivo_personajes << personaje->toString() << endl;
	}

	archivo_personajes.close();
}

void Utilitario::guardarJuego(Diccionario<string, Personaje*>* diccionarioDePersonajes, int turno) {
	ofstream archivo_juego(NOMBRE_ARCHIVO_JUEGO, ofstream::trunc);

	Lista<string>* claves = diccionarioDePersonajes->obtenerClaves();
	claves->reiniciar();

	Personaje* personaje;
	
	archivo_juego << turno << endl;

	while(claves->haySiguiente()) {
		personaje = diccionarioDePersonajes->obtenerDato(claves->siguiente());
		archivo_juego << personaje->toString() << endl;
	}

	archivo_juego.close();
}
