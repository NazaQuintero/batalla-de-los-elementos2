#ifndef CASILLERO_PRECIPICIO_H_
#define CASILLERO_PRECIPICIO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_PRECIPICIO = PRECIPICIO;

class Precipicio: public Casillero {
    private:
        string colorIni = "\x1B[2;49;39m";
        string colorFin = "\033[0m\t\t";

    public:
    // Constructor
    Precipicio(int posX, int posY);

    string getTerreno();

    string getColorIni();

    string getColorFin();

    // Destructor
    ~Precipicio();
};

#endif /* CASILLERO_PRECIPICIO_H_ */