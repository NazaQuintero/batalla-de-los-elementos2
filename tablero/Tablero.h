#ifndef TABLERO_TABLERO_H_
#define TABLERO_TABLERO_H_

#include <string>
#include <iostream>
#include "../casillero/Casillero.h"

using namespace std;

const int CANTIDAD_DE_CASILLEROS = 8;

class Tablero {
    private:
        Casillero** matrizCasilleros[CANTIDAD_DE_CASILLEROS][CANTIDAD_DE_CASILLEROS];
        int cantidadDeVertices;

    public:

        // Constructor
        Tablero();

        void generarMatriz();

        void guardarPersonaje();

        // Destructor
        ~Tablero();
};

#endif /* TABLERO_TABLERO_H_ */