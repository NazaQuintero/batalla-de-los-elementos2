#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <fstream>
#include <string>
#include "./Arista.h"
#include "./Vertice.h"
#include "tda/matriz/Matriz.h"
#include "utilitario/Utilitario.h"
#include "tda/diccionario/Diccionario.h"

using namespace std;

const int CANTIDAD_VERTICES = 8;

const int CANTIDAD_ARISTAS = CANTIDAD_VERTICES * CANTIDAD_VERTICES;

template<class T, class K>
class Grafo {
private:
	Utilitario* utilitario;
	Diccionario<string, int>* diccionarioDeCostos;
	Matriz<Vertice<T>*>* matrizDeVertices; // es necesario tener la referencia a los vertices ?
	Matriz<Arista<K>*>* matrizDeAyacencia; //relacion entre vertices

	void borrarVertices();
	void borrarAristas();
    
public: 
    //Crea un grafo vacio
    Grafo();

    Grafo(string nombreDeArchivoDeCostos);

    //Destructor
    ~Grafo();

    void insertarVertice(T data, int posX, int posY);

    bool existeVertice(int posX, int posY);

    void borrarVertice(int posX, int posY);

    void insertarArista(K peso, int posX, int posY);

    bool existeArista(int posX, int posY);

    void borrarArista(int posX, int posY);

    Diccionario<string, int>* obtenerCostos();

    void imprimirMatrizDeVertices();

    void imprimirMatrizDeAristas();

    K** floydWarshall(int desde[], int hasta[]);
    
};

template<class T, class K>
Grafo<T, K>::Grafo() {
	this->utilitario = Utilitario::obtenerInstancia();
	this->diccionarioDeCostos = new Diccionario<string, int>();
	this->matrizDeVertices = new Matriz<Vertice<T>*>(CANTIDAD_VERTICES, CANTIDAD_VERTICES);
	this->matrizDeAyacencia = new Matriz<Arista<K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);
};

template<class T, class K>
Grafo<T, K>::Grafo(string nombreDeArchivoDeCostos) {
	this->utilitario = Utilitario::obtenerInstancia();
	this->diccionarioDeCostos = new Diccionario<string, int>();
	this->matrizDeVertices = new Matriz<Vertice<T>*>(CANTIDAD_VERTICES, CANTIDAD_VERTICES);
	this->matrizDeAyacencia = new Matriz<Arista<K>*>(CANTIDAD_ARISTAS, CANTIDAD_ARISTAS);

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
		cout << "El costo de: " << terreno << " es: " << costo << endl;
		this->diccionarioDeCostos->guardar(terreno, costo);

		cout << "Se guardo: " << this->diccionarioDeCostos->obtenerDato(terreno) << endl;
	}


	archivo_costos.close();
}



// TODO: ver si se puede reutilizar la clase Coordenada
template<class T, class K>
K** Grafo<T, K>:: floydWarshall(int posDesde[], int posHasta[]) {

    K* pesos [CANTIDAD_ARISTAS][CANTIDAD_ARISTAS];

    for(int i = 0; i < CANTIDAD_ARISTAS; i++){
        //Inicializa diagonal principal en infinito
    	*(pesos[i][i]) == 999999;
    }
    
    for(int k = 0; k < CANTIDAD_ARISTAS; k++){
        for(int i = 0; i < CANTIDAD_ARISTAS; i++){
            for(int j = 0; j < CANTIDAD_ARISTAS; j++){
                K peso = *(pesos[i][k]) + *(pesos[k][j]);
                //Compara si se encuentra un peso menor al de la matriz
                if (peso < pesos[i][j])
                    pesos[i][j] = peso;
            }
        }
    }

    return pesos;

}

template<class T, class K>
void Grafo<T, K>::insertarVertice(T data, int posX, int posY) {
	Vertice<T>* vertice = new Vertice<T>(data);
	this->matrizDeVertices->insertar(vertice, posX, posY);
}

template<class T, class K>
bool Grafo<T, K>::existeVertice(int posX, int posY) {
	Vertice<T>* vertice = this->matrizDeVertices->obtener(posX, posY);
	return vertice != 0;
}

template<class T, class K>
void Grafo<T, K>::borrarVertice(int posX, int posY) {
	if(existeVertice(posX, posY))
		delete this->matrizDeVertices->obtener(posX, posY);
}

template<class T, class K>
void Grafo<T, K>::insertarArista(K peso, int posX, int posY) {
	Arista<K>* arista = new Arista<K>(peso);
	this->matrizDeAyacencia->insertar(arista, posX, posY);
}

template<class T, class K>
bool Grafo<T, K>::existeArista(int posX, int posY) {
	Arista<K>* arista = this->matrizDeAyacencia->obtener(posX, posY);
	return arista != 0;
}

template<class T, class K>
void Grafo<T, K>::borrarArista(int posX, int posY) {
	if(existeArista(posX, posY))
		delete this->matrizDeAyacencia->obtener(posX, posY);
}

template<class T, class K>
Diccionario<string, int>* Grafo<T, K>::obtenerCostos() {
	return this->diccionarioDeCostos;
}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeVertices() {
    for (int i = 0; i < CANTIDAD_VERTICES; i++) {
        for (int j = 0; j < CANTIDAD_VERTICES; j++) {
            cout << this->matrizDeVertices->obtener(i, j)->getData() << " | ";
        }
        cout << endl;
    }
}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeAristas() {
    for (int i = 0; i < CANTIDAD_ARISTAS; i++) {
        for (int j = 0; j < CANTIDAD_ARISTAS; j++) {
            cout << this->matrizDeAyacencia->obtener(i, j)->getPeso() << " | ";
        }
        cout << endl;
    }
}

template<class T, class K>
void Grafo<T, K>::borrarVertices() {
	for(int i = 0; i < CANTIDAD_VERTICES; i++) {
		for(int j = 0; j < CANTIDAD_VERTICES; j++) {
			borrarVertice(i, j);
		}
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
	delete this->matrizDeVertices;

	/*this->borrarAristas();*/
	delete this->matrizDeAyacencia;

	delete this->diccionarioDeCostos;

}

#endif /* GRAFO_H_ */
