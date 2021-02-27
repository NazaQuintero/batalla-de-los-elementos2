#ifndef CASILLERO_MONTANA_H_
#define CASILLERO_MONTANA_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_MONTANA = MONTANA;

class Montana: public Casillero {
    private:
        string colorIni = "\x1B[2;49;31m";
        string colorFin = "\033[0m";

    public:

    // Constructor
    Montana(int posX, int posY);

    string getTerreno();

    string getColorIni();
    string getColorFin();

    // Destructor
    ~Montana();
};

#endif /* CASILLERO_MONTANA_H_ */