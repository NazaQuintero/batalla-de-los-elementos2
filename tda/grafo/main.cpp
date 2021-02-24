//============================================================================
// Name        : Batalla de los elementos
// Author      : Quintero Nazareno 105296
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Batalla de los elementos C++, Ansi-style
//============================================================================

#include "./Grafo.h"

using namespace std;

int main() {

	int cantidadDeVertices = 8;

	int cantidadDeAristas = cantidadDeVertices * cantidadDeVertices;

    int** matrizDeAristas;

    matrizDeAristas = new int* [cantidadDeAristas];

    for (int w = 0; w < cantidadDeAristas; w++) {
    	matrizDeAristas[w] = new int[cantidadDeAristas];
    }

    int k = 1;
    for(int i = 0; i < cantidadDeAristas; i++) {
    	for(int j = 0; j < cantidadDeAristas; j++) {
    		matrizDeAristas[i][j] = k;
    		k++;
    	}
    }

    string matrizDeVertices2[8][8] = {
		{"Lago","Lago","Precipicio","Precipicio","Precipicio","Vacio","Volcan","Volcan"},
		{"Lago","Lago","Precipicio","Vacio","Volcan","Volcan","Volcan","Volcan"},
		{"Precipicio","Volcan","Volcan","Volcan","Volcan","Precipicio","Precipicio","Precipicio"},
		{"Volcan","Camino","Camino","Camino","Lago","Vacio","Camino","Camino"},
		{"Camino","Camino","Vacio","Camino","Camino","Camino","Camino","Precipicio"},
		{"Camino","Camino","Camino","Vacio","Montana","Montana","Montana","Precipicio"},
		{"Precipicio","Montana","Montana","Montana","Montana","Lago","Lago","Lago"},
		{"Precipicio","Precipicio","Montana","Precipicio","Vacio","Lago","Lago","Lago"}
	};

    Grafo<string, int>* grafo2 = new Grafo<string, int>();

	for(int i = 0; i < cantidadDeVertices; i++) {
		for(int j = 0; j < cantidadDeVertices; j++) {
			grafo2->insertarVertice(matrizDeVertices2[i][j], i, j);
		}
	}

	for(int i = 0; i < cantidadDeAristas; i++) {
		for(int j = 0; j < cantidadDeAristas; j++) {
			grafo2->insertarArista(matrizDeAristas[i][j], i, j);
		}
	}

	grafo2->imprimirMatrizDeVertices();

	grafo2->imprimirMatrizDeAristas();

	cout << "##########################################################" << endl;

	delete grafo2;

	for(int i = 0; i < CANTIDAD_ARISTAS; i ++)
		delete[] matrizDeAristas[i];
	delete[] matrizDeAristas;


	return 0;
}
