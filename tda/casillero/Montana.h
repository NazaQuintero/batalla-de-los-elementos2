#ifndef CASILLERO_MONTANA_H_
#define CASILLERO_MONTANA_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_MONTANA = montana;

class Montana: public Casillero {
    public:

    // Constructor
    Montana(int posX, int posY);

    // Destructor
    ~Montana();
};

#endif /* CASILLERO_MONTANA_H_ */