#ifndef CASILLERO_VOLCAN_H_
#define CASILLERO_VOLCAN_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_VOLCAN = VOLCAN;

class Volcan: public Casillero {
    public:

    // Constructor
    Volcan(int posX, int posY);

    string getTerreno();

    // Destructor
    ~Volcan();
};

#endif /* CASILLERO_VOLCAN_H_ */