#include "Tablero.h"

Tablero::Tablero() {
    this->cantidadDeCasilleros = CANTIDAD_DE_CASILLEROS * CANTIDAD_DE_CASILLEROS;
    this->utilitario = Utilitario::obtenerInstancia();


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

        for (int i = 0; i < CANTIDAD_DE_CASILLEROS; i++) {
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

void Tablero::mostrarTablero() {
    for (size_t i = 0; i < CANTIDAD_DE_CASILLEROS; i++) {
        for (size_t j = 0; j < CANTIDAD_DE_CASILLEROS; j++) {
            cout << this->matrizCasilleros[i][j]->getTerreno() << " | ";
        }
        cout << endl;
    }    
}

Tablero::~Tablero() {
    
}