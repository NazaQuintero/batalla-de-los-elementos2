#ifndef TABLERO_TABLERO_H_
#define TABLERO_TABLERO_H_

#include <string>
#include <iostream>
#include "../casillero/FabricaDeCasillero.h"
#include "../casillero/Casillero.h"
#include "../utilitario/Utilitario.h"
#include "../personaje/Personaje.h"
#include "../tda/matriz/Matriz.h"

using namespace std;

const int CANTIDAD_DE_CASILLEROS_X_FILA = 8;
const int CANTIDAD_DE_CASILLEROS_X_COLUMNA = 8;
const string NOMBRE_ARCHIVO_MAPA = "mapa.csv";

class Tablero {
    private:
        Matriz<Casillero*>* matrizCasilleros;
        int cantidadDeCasilleros;
        Utilitario* utilitario;

    public:

        // Constructor
        Tablero();

        // Posiciona al personaje en el casillero con posicion X e Y
        void posicionarPersonaje(int posX, int posY, Personaje* personaje);

        // Retorna la matriz de casilleros
        Matriz<Casillero*>* getCasilleros();

        int getCantidadDeCasillerosPorFila();

        void mostrarTablero();

        // Destructor
        ~Tablero();
};

#endif /* TABLERO_TABLERO_H_ */
