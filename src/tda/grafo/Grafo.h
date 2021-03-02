#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <string>
#include "./Arista.h"
#include "./Vertice.h"
#include "../matriz/Matriz.h"
#include "../../utilitario/Utilitario.h"
#include "../diccionario/Diccionario.h"
#include "../lista/lista.h"

using namespace std;

const int CANTIDAD_VERTICES = 8;

const int CANTIDAD_ARISTAS = CANTIDAD_VERTICES * CANTIDAD_VERTICES;

template<class T, class K>
class Grafo {
private:
	Utilitario* utilitario;
	Diccionario<string, int>* diccionarioDeCostos;
	Lista<Vertice<T, K>*>* listaDeVertices; 
	Matriz<Arista<K>*>* matrizDeAdyacencia; //relacion entre vertices
	Matriz<Vertice<T, K>*>* matrizDeRecorridos;

	void borrarVertices();
	void borrarAristas();
    
public: 
    //Crea un grafo vacio
    Grafo();

    Grafo(string nombreDeArchivoDeCostos);

    //Destructor
    ~Grafo();

    void insertarVertice(T data, K peso);

    bool existeVertice(int posX);

    Vertice<T, K>* obtenerVertice(int pos);

    Lista<Vertice<T, K>*>* obtenerListaDeVertices();

    void borrarVertice(int posX);

    void insertarArista(K peso, int posX, int posY);

    bool existeArista(int posX, int posY);

    void borrarArista(int posX, int posY);

    bool sonAdyacentes(Vertice<T, K>* vertice1, Vertice<T, K>* vertice2);

    Diccionario<string, int>* obtenerCostos();

    void imprimirVertices();

    void imprimirCostos();

    void inicializarMatrizDeRecorrido();

    void imprimirMatrizDeRecorridos();

    void generarMatrizDeAdyacencia();

    void imprimirMatrizDeAristas();

	Matriz<Arista<K>*>* getMatrizDeAdyacencia();

	Matriz<Vertice<T, K>*>* getMatrizDeRecorridos();

    void floydWarshall();
    
};

template<class T, class K>
Grafo<T, K>::Grafo() {
	this->utilitario = Utilitario::obtenerInstancia();
	this->diccionarioDeCostos = new Diccionario<string, int>();
	this->listaDeVertices = new Lista<Vertice<T, K>*>();
	this->matrizDeAdyacencia = new Matriz<Arista<K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);
	this->matrizDeRecorridos = new Matriz<Vertice<T, K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);
};

template<class T, class K>
Grafo<T, K>::Grafo(string nombreDeArchivoDeCostos) {
	this->utilitario = Utilitario::obtenerInstancia();
	this->diccionarioDeCostos = new Diccionario<string, int>();
	this->listaDeVertices = new Lista<Vertice<T, K>*>();
	this->matrizDeAdyacencia = new Matriz<Arista<K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);
	this->matrizDeRecorridos = new Matriz<Vertice<T, K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);

	fstream archivo_costos(nombreDeArchivoDeCostos, ios::in);

	if(!archivo_costos.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << nombreDeArchivoDeCostos << "\"." << endl;
	}

	string linea;
	string terreno;
	string costoStr;

	while(archivo_costos >> linea) {
		vector<string> terrenoYCosto;

		this->utilitario->split(linea, ',', terrenoYCosto);

		terreno = terrenoYCosto[0];
		costoStr = terrenoYCosto[1];
		int costo = stoi(costoStr);
		this->diccionarioDeCostos->guardar(terreno, costo);
	}


	archivo_costos.close();
}

template<class T, class K>
void Grafo<T, K>::floydWarshall() {

	for(int k = 0; k < CANTIDAD_ARISTAS; k++) {
		for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
			for(int j = 0; j < CANTIDAD_ARISTAS; j++){
				int suma = this->matrizDeAdyacencia->obtener(i,k)->getPeso() + this->matrizDeAdyacencia->obtener(k,j)->getPeso();
				if(suma < this->matrizDeAdyacencia->obtener(i,j)->getPeso()) {
					this->matrizDeAdyacencia->obtener(i, j)->setPeso(suma);
					this->matrizDeRecorridos->insertar(this->listaDeVertices->consulta(k+1),j,i);
				}
			}
		}
	}
}

template<class T, class K>
void Grafo<T, K>::insertarVertice(T data, K peso) {
	Vertice<T, K>* vertice = new Vertice<T, K>(data, peso);
	int largo = this->listaDeVertices->obtenerCantidad();
	this->listaDeVertices->alta(vertice, largo + 1);
}

template<class T, class K>
bool Grafo<T, K>::existeVertice(int posX) {
	Vertice<T, K>* vertice = this->listaDeVertices->consulta(posX);
	return vertice != 0;
}

template<class T, class K>
Vertice<T, K>* Grafo<T, K>::obtenerVertice(int pos) {
	return this->listaDeVertices->consulta(pos);
}

template<class T, class K>
Lista<Vertice<T, K>*>* Grafo<T, K>::obtenerListaDeVertices() {
	return this->listaDeVertices;
}

template<class T, class K>
void Grafo<T, K>::borrarVertice(int posX) {
	if(existeVertice(posX))
		this->listaDeVertices->baja(posX);
}

template<class T, class K>
void Grafo<T, K>::insertarArista(K peso, int posX, int posY) {
	Arista<K>* arista = new Arista<K>(peso);
	this->matrizDeAdyacencia->insertar(arista, posX, posY);
}

template<class T, class K>
bool Grafo<T, K>::existeArista(int posX, int posY) {
	Arista<K>* arista = this->matrizDeAdyacencia->obtener(posX, posY);
	return arista != 0;
}

template<class T, class K>
void Grafo<T, K>::borrarArista(int posX, int posY) {
	if(existeArista(posX, posY))
		delete this->matrizDeAdyacencia->obtener(posX, posY);
}

template<class T, class K>
bool Grafo<T, K>::sonAdyacentes(Vertice<T, K>* vertice1, Vertice<T, K>* vertice2) {
	bool sonAdyacentes = false;
	int* posVertice1 = vertice1->getData()->getPos();
	int* posVertice2 = vertice2->getData()->getPos();

	if(posVertice1[0] + 1 == posVertice2[0] || posVertice1[0] - 1 == posVertice2[0]) {
		if(posVertice1[1] == posVertice2[1]) {
			sonAdyacentes = true;
		}
	} else if (posVertice1[1] + 1 == posVertice2[1] || posVertice1[1] - 1 == posVertice2[1]) {
		if(posVertice1[0] == posVertice2[0]) {
			sonAdyacentes = true;
		}
	}
	return sonAdyacentes;
}

template<class T, class K>
Diccionario<string, int>* Grafo<T, K>::obtenerCostos() {
	return this->diccionarioDeCostos;
}

template<class T, class K>
void Grafo<T, K>::imprimirVertices() {
	int cont = 0;
	this->listaDeVertices->reiniciar();
	while(this->listaDeVertices->haySiguiente()) {
		cout << this->listaDeVertices->siguiente()->getData()->getTerreno() << " | ";
		if (cont < CANTIDAD_VERTICES - 1) {
			cont++;
		} else {
			cout << endl;
			cont = 0;
		}
	}
}

template<class T, class K>
void Grafo<T, K>::imprimirCostos() {
	int cont = 0;
	this->listaDeVertices->reiniciar();
	while(this->listaDeVertices->haySiguiente()) {
		cout << this->listaDeVertices->siguiente()->getPeso() << " | ";
		if (cont < CANTIDAD_VERTICES - 1) {
			cont++;
		} else {
			cout << endl;
			cont = 0;
		}
	}
}

template<class T, class K>
void Grafo<T, K>::inicializarMatrizDeRecorrido() {
	for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
		for(int j = 0; j < CANTIDAD_ARISTAS; j++) {
			if(i != j) {
				this->matrizDeRecorridos->insertar(this->listaDeVertices->consulta(i), i, j);
			} else {
				this->matrizDeRecorridos->insertar(nullptr, i, j);
			}
		}
	}
}

template<class T, class K>
void Grafo<T, K>::generarMatrizDeAdyacencia() {

	for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
		for(int j = 0; j < CANTIDAD_ARISTAS; j++) {
			if(i != j) {
				Vertice<T, K>* vertice1 = this->listaDeVertices->consulta(i+1);
				Vertice<T, K>* vertice2 = this->listaDeVertices->consulta(j+1);
				// si son adyacentes, entonces inserto el peso
				if(sonAdyacentes(vertice1, vertice2)) {
					// dado 2 vertices del grafo, decidir si son adyacentes o no
					insertarArista(vertice1->getPeso(), i, j);
				} else {
					insertarArista(99999, i, j);
				}
			} else {
				insertarArista(0, i, j);
			}
		}
	}

}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeAristas() {
    for (int i = 0; i < CANTIDAD_ARISTAS; i++) {
        for (int j = 0; j < CANTIDAD_ARISTAS; j++) {
            cout << this->matrizDeAdyacencia->obtener(i, j)->getPeso() << " | ";
        }
        cout << endl;
    }
}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeRecorridos() {
    for (int i = 0; i < CANTIDAD_ARISTAS; i++) {
        for (int j = 0; j < CANTIDAD_ARISTAS; j++) {
        	if(i != j) {
        		cout << this->matrizDeRecorridos->obtener(i, j)->getData()->getPosString() << " | ";
        	} else {
        		cout << "----- | ";
        	}
        }
        cout << endl;
    }
}

template<class T, class K>
Matriz<Arista<K>*>* Grafo<T, K>::getMatrizDeAdyacencia() {
	return this->matrizDeAdyacencia;
}

template<class T, class K>
Matriz<Vertice<T, K>*>* Grafo<T, K>::getMatrizDeRecorridos() {
	return this->matrizDeRecorridos;
}

template<class T, class K>
void Grafo<T, K>::borrarVertices() {
	for(int i = 0; i < this->listaDeVertices->obtenerCantidad(); i++) {
		borrarVertice(i);
	}
}

template<class T, class K>
void Grafo<T, K>::borrarAristas() {
	for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
		for(int j = 0; j < CANTIDAD_ARISTAS; j++) {
			borrarArista(i, j);
		}
	}
}

template<class T, class K>
Grafo<T, K>::~Grafo(){

	this->borrarVertices();
	delete this->listaDeVertices;

	delete this->matrizDeAdyacencia;

	delete this->diccionarioDeCostos;

}

#endif /* GRAFO_H_ */
