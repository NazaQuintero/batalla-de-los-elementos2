#ifndef CASILLERO_LAGO_H_
#define CASILLERO_LAGO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_LAGO = LAGO;

const string COLOR_LAGO = "celeste";

class Lago: public Casillero {
    public:

    // Constructor
    Lago(int posX, int posY);

    // Destructor
    ~Lago();
};


#endif /* CASILLERO_LAGO_H_ */