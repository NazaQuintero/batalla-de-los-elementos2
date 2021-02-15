#ifndef CASILLERO_PRECIPICIO_H_
#define CASILLERO_PRECIPICIO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_PRECIPICIO = PRECIPICIO;

class Precipicio: public Casillero {
    public:

    // Constructor
    Precipicio(int posX, int posY);

    // Destructor
    ~Precipicio();
};

#endif /* CASILLERO_PRECIPICIO_H_ */