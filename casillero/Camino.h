#ifndef CASILLERO_CAMINO_H_
#define CASILLERO_CAMINO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_CAMINO = CAMINO;

class Camino: public Casillero {
    public:

    // Constructor
    Camino(int posX, int posY);

    string getTerreno();

    // Destructor
    ~Camino();
};

#endif /* CASILLERO_CAMINO_H_ */