#ifndef CASILLERO_CAMINO_H_
#define CASILLERO_CAMINO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_CAMINO = CAMINO;

class Camino: public Casillero {
    private:
        string colorIni = "\x1B[1;37m";
        string colorFin = "\033[0m\t\t";

    public:

    // Constructor
    Camino(int posX, int posY);

    string getTerreno();

    string getColorIni();

    string getColorFin();

    // Destructor
    ~Camino();
};

#endif /* CASILLERO_CAMINO_H_ */