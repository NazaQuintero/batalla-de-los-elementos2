#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <string>
#include <iostream>

using namespace std;

class Coordenada {

private:
	// Atributos
	int posX;
    int posY;

public:

    Coordenada();
	// Constructor
	Coordenada(int posX, int posY);

    int getPosX();

    int getPosY();

    // Destructor
    ~Coordenada();

};

#endif /* CASILLERO_CASILLERO_H_ */
