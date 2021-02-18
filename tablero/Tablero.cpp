#include "Tablero.h"

Tablero::Tablero() {
    this->cantidadDeCasilleros = CANTIDAD_DE_CASILLEROS_X_FILA * CANTIDAD_DE_CASILLEROS_X_COLUMNA;
    this->utilitario = Utilitario::obtenerInstancia();


    this->matrizCasilleros = new Casillero* [CANTIDAD_DE_CASILLEROS_X_FILA];

    for(int i = 0; i < CANTIDAD_DE_CASILLEROS_X_FILA; i++) {
    	this->matrizCasilleros[i] = new Casillero[CANTIDAD_DE_CASILLEROS_X_COLUMNA];
    }

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
            this->matrizCasilleros[j][i] = casillero;
        }
        j++;
    }

}


void Tablero::posicionarPersonaje(int posX, int posY, Personaje* personaje) {

    Casillero* casillero = this->matrizCasilleros[posX][posY];
    
    casillero->setPersonaje(personaje);

}

Casillero** Tablero::getCasilleros() {
    return this->matrizCasilleros[CANTIDAD_DE_CASILLEROS_X_FILA];
}

int Tablero::getCantidadDeCasillerosPorFila() {
    return CANTIDAD_DE_CASILLEROS_X_FILA;
}

void Tablero::mostrarTablero() {
    for (size_t i = 0; i < CANTIDAD_DE_CASILLEROS_X_FILA; i++) {
        for (size_t j = 0; j < CANTIDAD_DE_CASILLEROS_X_COLUMNA; j++) {
            cout << this->matrizCasilleros[i][j].getTerreno() << " | ";
        }
        cout << endl;
    }    
}

Tablero::~Tablero() {
    
}
