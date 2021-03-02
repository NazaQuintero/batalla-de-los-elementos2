#ifndef CASILLERO_VOLCAN_H_
#define CASILLERO_VOLCAN_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_VOLCAN = VOLCAN;

class Volcan: public Casillero {
    private:
        string colorIni = "\x1B[1;31m";
        string colorFin = "\033[0m";

    public:

    // Constructor
    Volcan(int posX, int posY);

    string getTerreno();

    string getColorIni();
    string getColorFin();

    // Destructor
    ~Volcan();
};

#endif /* CASILLERO_VOLCAN_H_ */