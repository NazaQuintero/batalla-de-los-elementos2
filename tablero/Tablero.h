#ifndef TABLERO_TABLERO_H_
#define TABLERO_TABLERO_H_

#include <string>
#include <iostream>
#include "../casillero/FabricaDeCasillero.h"
#include "../casillero/Casillero.h"
#include "../utilitario/Utilitario.h"

using namespace std;

const int CANTIDAD_DE_CASILLEROS = 8;
const string NOMBRE_ARCHIVO_MAPA = "mapa.csv";

class Tablero {
    private:
        Casillero matrizCasilleros[CANTIDAD_DE_CASILLEROS][CANTIDAD_DE_CASILLEROS];
        int cantidadDeCasilleros;
        Utilitario* utilitario;

    public:

        // Constructor
        Tablero();

        void cargarMatriz();

        // Posiciona al personaje en el casillero con posicion X e Y
        void posicionarPersonaje(int posX, int posY, Personaje* personaje);

        // Destructor
        ~Tablero();
};

#endif /* TABLERO_TABLERO_H_ */