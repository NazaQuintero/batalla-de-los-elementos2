#ifndef CASILLERO_LAGO_H_
#define CASILLERO_LAGO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_LAGO = LAGO;

const string COLOR_LAGO = "celeste";

class Lago: public Casillero {
    private:
        string colorIni = "\x1B[1;36m";
        string colorFin = "\033[0m";

    public:

    // Constructor
    Lago(int posX, int posY);

    string getTerreno();

    string getColorIni();
    string getColorFin();

    // Destructor
    ~Lago();
};


#endif /* CASILLERO_LAGO_H_ */