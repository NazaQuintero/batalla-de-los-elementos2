#ifndef GRAFO_H_
#define GRAFO_H_

#include "./Arista.h"
#include "./Vertice.h"
#include <iostream>

using namespace std;

const int CANTIDAD_VERTICES = 8;

const int CANTIDAD_ARISTAS = CANTIDAD_VERTICES * CANTIDAD_VERTICES;

template<class T, class K>
class Grafo {
private:
	Vertice<T>* matrizDeVertices[CANTIDAD_VERTICES][CANTIDAD_VERTICES];
	Arista<K>* matrizDeAyacencia[CANTIDAD_ARISTAS][CANTIDAD_ARISTAS]; //relacion entre vertices
    
public: 
    //Crea un grafo vacio
    Grafo();

    //Destructor
    ~Grafo();

    void insertarVertice(T data, int posX, int posY);

    bool existeVertice(int posX, int posY);

    void borrarVertice(int posX, int posY);

    void insertarArista(K peso, int posX, int posY);

    bool existeArista(int posX, int posY);

    void borrarArista(int posX, int posY);

    void imprimirMatrizDeVertices();

    void imprimirMatrizDeAristas();

    K** floydWarshall(int desde[], int hasta[]);
    
};

template<class T, class K>
Grafo<T, K>::Grafo() {
	for(int i = 0; i < CANTIDAD_VERTICES; i++) {
		for(int j = 0; j < CANTIDAD_VERTICES; j++) {
			this->matrizDeVertices[i][j] = 0;
		}
	}

	for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
		for(int j = 0; j < CANTIDAD_ARISTAS; j++) {
			this->matrizDeAyacencia[i][j] = 0;
		}
	}
};




// TODO: ver si se puede reutilizar la clase Coordenada
//template<class T, class K>
//K** Grafo<T, K>:: floydWarshall(int posDesde[], int posHasta[]) {
//
//    K* pesos [CANTIDAD_ARISTAS][CANTIDAD_ARISTAS];
//
//    for(int i = 0; i < CANTIDAD_ARISTAS; i++){
//        //Inicializa diagonal principal en infinito
//    	*(pesos[i][i]) == 999999;
//    }
//
//    for(int k = 0; k < CANTIDAD_ARISTAS; k++){
//        for(int i = 0; i < CANTIDAD_ARISTAS; i++){
//            for(int j = 0; j < CANTIDAD_ARISTAS; j++){
//                K peso = *(pesos[i][k]) + *(pesos[k][j]);
//                //Compara si se encuentra un peso menor al de la matriz
//                if (peso < pesos[i][j])
//                    pesos[i][j] = peso;
//            }
//        }
//    }
//
//    return pesos;
// }

// Dados el número de nodos del grafo (n), el grafo (G) como matriz de adyacencia y una
// matriz dist (matriz dist = matriz peso), guarda en dist la distancia mínima entre cada par de nodos, de modo que
// dist[i][j] es la distancia mínima para ir del nodo i al j
// Fijarnos como pasar las matrices (con templates)
template<class T, class K>
void Floyd_Warshall<T, K>::caminoMinimo (int CANTIDAD_VERTICES, matrizDeAyacencia& G, peso& dist){
    dist = G;
    for (int i = 0; i < CANTIDAD_VERTICES ; ++i){
        for (int j = 0; j < CANTIDAD_VERTICES; ++j){
            if (i != j and dist[i][j] == 0) dist[i][j] = 9999999;
            //las parejas de nodos sin arco están a distancia 999999 (p.e. 1e9)
        }
    }

    for (int k = 0; k < CANTIDAD_VERTICES; ++k){ //por cada nodo intermedio k
        for (int i = 0; i < CANTIDAD_VERTICES; ++i){
            for (int j = 0; j < CANTIDAD_VERTICES; ++j){ //miramos todas las parejas de nodos
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                //Si pasando por k mejoramos el resultado, lo actualizamos
            }
        }
    }
}


template<class T, class K>
void Grafo<T, K>::insertarVertice(T data, int posX, int posY) {
	Vertice<T>* vertice = new Vertice<T>(data);
	this->matrizDeVertices[posX][posY] = vertice;
}

template<class T, class K>
bool Grafo<T, K>::existeVertice(int posX, int posY) {
	return this->matrizDeVertices[posX][posY] != 0;
}

template<class T, class K>
void Grafo<T, K>::borrarVertice(int posX, int posY) {
	if(existeVertice(posX, posY))
		delete this->matrizDeVertices[posX][posY];
}

template<class T, class K>
void Grafo<T, K>::insertarArista(K peso, int posX, int posY) {
	Arista<K>* arista = new Arista<K>(peso);
	this->matrizDeAyacencia[posX][posY] = arista;
}

template<class T, class K>
bool Grafo<T, K>::existeArista(int posX, int posY) {
	return this->matrizDeAyacencia[posX][posY] != 0;
}

template<class T, class K>
void Grafo<T, K>::borrarArista(int posX, int posY) {
	if(existeArista(posX, posY))
		delete this->matrizDeAyacencia[posX][posY];
}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeVertices() {
    for (int i = 0; i < CANTIDAD_VERTICES; i++) {
        for (int j = 0; j < CANTIDAD_VERTICES; j++) {
            cout << this->matrizDeVertices[i][j]->getData() << " | ";
        }
        cout << endl;
    }
}

template<class T, class K>
void Grafo<T, K>::imprimirMatrizDeAristas() {
    for (int i = 0; i < CANTIDAD_ARISTAS; i++) {
        for (int j = 0; j < CANTIDAD_ARISTAS; j++) {
            cout << this->matrizDeAyacencia[i][j]->getPeso() << " | ";
        }
        cout << endl;
    }
}

template<class T, class K>
Grafo<T, K>::~Grafo(){

    for(int i = 0; i < CANTIDAD_VERTICES; i++) {
    	for(int j = 0; j < CANTIDAD_VERTICES; j++) {
    		borrarVertice(i, j);
    	}
    }

    for(int i = 0; i < CANTIDAD_ARISTAS; i++) {
		for(int j = 0; j < CANTIDAD_ARISTAS; j++) {
			borrarArista(i, j);
		}
	}

}

#endif /* GRAFO_H_ */
