#include "Tablero.h"

Tablero::Tablero() {
    this->cantidadDeCasilleros = CANTIDAD_DE_CASILLEROS_X_FILA * CANTIDAD_DE_CASILLEROS_X_COLUMNA;
    this->utilitario = Utilitario::obtenerInstancia();


    this->matrizCasilleros = new Matriz<Casillero*>(CANTIDAD_DE_CASILLEROS_X_FILA, CANTIDAD_DE_CASILLEROS_X_COLUMNA);

    fstream archivo_mapa(NOMBRE_ARCHIVO_MAPA, ios::in);

	if(!archivo_mapa.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_MAPA << "\"." << endl;
	}

    string linea;
    string tipoDeTerreno;

    FabricaDeCasillero fabricaDeCasillero;
    int j = 0;

    while(archivo_mapa >> linea) {
    	vector<string> tiposDeTerreno;

        this->utilitario->split(linea, ',', tiposDeTerreno);

        for (int i = 0; i < CANTIDAD_DE_CASILLEROS_X_FILA; i++) {
            tipoDeTerreno = tiposDeTerreno[i];

            Casillero* casillero = fabricaDeCasillero.obtenerCasillero(tipoDeTerreno, j, i);

            this->matrizCasilleros->insertar(casillero, j, i);
        }
        j++;
    }
    archivo_mapa.close();

}


void Tablero::posicionarPersonaje(int posX, int posY, Personaje* personaje) {

    Casillero* casillero = this->matrizCasilleros->obtener(posX, posY);
    
    casillero->setPersonaje(personaje);

}

Matriz<Casillero*>* Tablero::getCasilleros() {
    return this->matrizCasilleros;
}

int Tablero::getCantidadDeCasillerosPorFila() {
    return CANTIDAD_DE_CASILLEROS_X_FILA;
}

void Tablero::mostrarTablero() {
    for (int i = 0; i < CANTIDAD_DE_CASILLEROS_X_FILA; i++) {
        for (int j = 0; j < CANTIDAD_DE_CASILLEROS_X_COLUMNA; j++) {
            cout << this->matrizCasilleros->obtener(i, j)->getTerreno() << " | ";
        }
        cout << endl;
    }    
}

Tablero::~Tablero() {
    for(int i = 0; i < CANTIDAD_DE_CASILLEROS_X_FILA; i++) {
    	for(int j = 0; j < CANTIDAD_DE_CASILLEROS_X_COLUMNA; j++) {
    		delete this->matrizCasilleros->obtener(i, j);
    	}
    }
    delete this->matrizCasilleros;
}
