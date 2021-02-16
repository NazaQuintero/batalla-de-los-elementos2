#ifndef GRAFO_H_
#define GRAFO_H_

#include "./Arista.h"
#include "./Vertice.h"
#include "./lista.h"
#include <iostream>

const int CANTIDAD_VERTICES = 8;

template<class T>
class Grafo {
private:
	Arista<T>* matrizDeAyacencia [][]; //relacion entre vertices
    Vertice<T>* matrizDeVertices [][]; //referencia a cada vertice
    Vertice<T>* matrizDeRecorridoMinimo [][];
    
public: 
    //Crea un grafo vacio
    Grafo();

    //Destructor
    ~Grafo();

    //Inserta en el grafo el nodo recibido como argumento
    //PRE: Grafo != null 
    //POS: Se inserta el nuevo nodo en el grafo.
    insertarNodo(T data);
    
    //Inserta en el grafo la arista recibida como argumento
    //PRE: Grafo != null 
    //POS: Se inserta la arista al grafo.
    insertarArista(int peso);

    //Elimina del grafo un nodo recibido como argumento
    //PRE: Grafo != null.
    //POS: El grafo queda modificado por la eliminación de la arista
    eliminarNodo();

    //Elimina del grafo una arista recibida como argumento
    //PRE: Grafo != null.
    //POS: El grafo queda modificado por la eliminación de la arista
    eliminarArista();

    //Recibe una arista y retorna un valor logico indicando si la arista existe en el grafo
    //PRE: Grafo != null
    //POS: arista es un valor válido
    existeArista();
    
    //Recibe una arista y retorna un booleano indicando si el nodo existe o no en el grafo.
    //PRE: Grafo != null
    //POS: nodo es un valor válido
    existeNodo();
    
    // Recorrido en anchura
    void BFS();

    Vertice<T>** floydWarshall(int desde[], int hasta[]);
    
};


template<class T>
Grafo<T>::Grafo(){
    Vertice<T>** matrizDeVertices;
    matrizDeVertices = new T*[CANTIDAD_VERTICES];
    
    for(int i = 0; i < CANTIDAD_VERTICES; i++)
        matrizDeVertices[i] = new T[CANTIDAD_VERTICES];

    Arista<T>** matrizDeAyacencia;
    matrizDeAyacencia = new T*[CANTIDAD_VERTICES];
    
    for(int i = 0; i < CANTIDAD_VERTICES; i++)
        matrizDeAyacencia[i] = new T[CANTIDAD_VERTICES];
    
}

template<class T>
Grafo<T>::~Grafo(){
    for(int i = 0; i < CANTIDAD_VERTICES; i++)
        delete[] matrizDeVertices[i];
    
    delete[] matrizDeVertices;

    for(int i = 0; i < CANTIDAD_VERTICES; i++)
        delete[] matrizDeAyacencia[i];
    
    delete[] matrizDeAyacencia;
}

template<class T>
Vertice<T>** Grafo<T>:: floydWarshall(int posDesde[], int posHasta[]) {


    Vertice<T>* pesos = this->matrizDeRecorridoMinimo;
    for(int i = 0; i < CANTIDAD_VERTICES, i++){
        //Inicializa diagonal principal en infinito
        distancia[i][i] == 999999;
    }
    
    for(int k = 0; k < CANTIDAD_VERTICES, k++){
        for(int i = 0; i < CANTIDAD_VERTICES, i++){
            for(int j = 0; j < CANTIDAD_VERTICES, j++){
                int peso = pesos[i][k] + pesos[k][j];
                //Compara si se encuentra un peso menor al de la matriz
                if (peso < pesos[i][j])
                    pesos[i][j] = peso;
            }
        }
    }

    return pesos;

}

#endif /* GRAFO_H_ */