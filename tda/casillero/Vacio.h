#ifndef CASILLERO_VACIO_H_
#define CASILLERO_VACIO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_VACIO = vacio;

class Vacio: public Casillero {
    public:

    // Constructor
    Vacio(int posX, int posY);

    // Destructor
    ~Vacio();
};

#endif /* CASILLERO_VACIO_H_ */