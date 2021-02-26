#ifndef CASILLERO_VACIO_H_
#define CASILLERO_VACIO_H_

#include <string>
#include <iostream>
#include "Casillero.h"

using namespace std;

const Terreno TERRENO_VACIO = VACIO;

class Vacio: public Casillero {
    private:
        string colorIni = "\x1B[2;49;35m";
        string colorFin = "\033[0m\t\t";
    public:

    // Constructor
    Vacio(int posX, int posY);

    string getTerreno();

    string getColorIni();

    string getColorFin();

    // Destructor
    ~Vacio();
};

#endif /* CASILLERO_VACIO_H_ */