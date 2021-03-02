#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

using namespace std;


template<class Dato>
class Matriz {
private:
    // atributos
    Dato** datos;
    int cantidadDeFilas;
    int cantidadDeColumnas;

public:
    // constructor
    // POS: crea una matriz vacia
    Matriz();

    Matriz(int cantidadDeFilas, int cantidadDeColumnas);

    void insertar(Dato dato, int posX, int posY);

    Dato obtener(int posX, int posY);

    void imprimir();

    ~Matriz();

private:

};


template<class Dato>
Matriz<Dato>::Matriz() {
	this->datos = 0;
	this->cantidadDeFilas = 0;
	this->cantidadDeColumnas = 0;
}

template<class Dato>
Matriz<Dato>::Matriz(int cantidadDeFilas, int cantidadDeColumnas) {
	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;

	this->datos = new Dato* [cantidadDeFilas];

	for(int i = 0; i < cantidadDeFilas; i++) {
		this->datos[i] = new Dato[cantidadDeColumnas];
	}
}

template<class Dato>
void Matriz<Dato>::insertar(Dato dato, int posX, int posY) {
	this->datos[posX][posY] = dato;
}

template<class Dato>
Dato Matriz<Dato>::obtener(int posX, int posY) {
	return this->datos[posX][posY];
}

template<class Dato>
void Matriz<Dato>::imprimir() {
	for(int i = 0; i < cantidadDeFilas; i++) {
		for(int j = 0; j < cantidadDeColumnas; j++) {
			cout << this->datos[i][j] << " | ";
		}
		cout << endl;
	}
}

template<class Dato>
Matriz<Dato>::~Matriz() {
	for (int i = 0; i < cantidadDeFilas; i++) {
		delete[] this->datos[i];
	}
	delete [] this->datos;
}

#endif // MATRIZ_H_INCLUDED
