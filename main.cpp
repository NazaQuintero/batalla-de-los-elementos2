//============================================================================
// Name        : Batalla de los elementos
// Author      : Quintero Nazareno 105296
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Batalla de los elementos C++, Ansi-style
//============================================================================

#include "./Grafo.h"
#include "tablero/Tablero.h"
#include "casillero/Casillero.h"
#include "tda/diccionario/Diccionario.h"
#include "tda/lista/lista.h"

#include "terminal/Terminal.h"
#include "validaciones/Validador.h"
#include "utilitario/Utilitario.h"
#include "tda/matriz/Matriz.h"

using namespace std;

Terminal* Terminal::terminal = 0;
Validador* Validador::validador = 0;
Utilitario* Utilitario::utilitario = 0;

const string COSTOS_AGUA = "costosAgua.csv";
const string COSTOS_AIRE = "costosAire.csv";
const string COSTOS_FUEGO = "costosFuego.csv";
const string COSTOS_TIERRA = "costosTierra.csv";

int main() {

	Tablero* tablero = new Tablero();

	tablero->mostrarTablero();

	Matriz<Casillero*>* casilleros = tablero->getCasilleros();

	cout << "##########################################################" << endl << endl << endl;


	cout << "################ PRUEBA  GET CASILLEROS ##################" << endl;

	int cantidadDeCasilleros = tablero->getCantidadDeCasillerosPorFila();

	for(int i = 0; i < cantidadDeCasilleros; i++) {
		for(int j = 0; j < cantidadDeCasilleros; j++) {
			cout << casilleros->obtener(i, j)->getTerreno() << " | ";
		}
		cout << endl;
	}

	cout << "############### END PRUEBA  GET CASILLEROS ##################" << endl;

	/*cout << "Terreno: " << casillero->getTerreno() << endl;*/



	cout << "La cantidad de casilleros es: " << cantidadDeCasilleros << endl << endl << endl;


	cout << "###################### PRUEBA GRAFO AGUA #########################" << endl;


    Grafo<Casillero*, int>* grafoAgua = new Grafo<Casillero*, int>(COSTOS_AGUA);

    Diccionario<string, int>* costosAgua = grafoAgua->obtenerCostos();

    for(int i = 0; i < cantidadDeCasilleros; i++) {
		for(int j = 0; j < cantidadDeCasilleros; j++) {
			string terreno = casilleros->obtener(i, j)->getTerreno();
			int peso = costosAgua->obtenerDato(terreno);
			grafoAgua->insertarVertice(casilleros->obtener(i, j), peso/*, i, j*/);
		}
	}

    cout << "###################### PRINTING VERTIX MATRIX #########################" << endl;
    grafoAgua->imprimirVertices();
    cout << "################### END PRINTING VERTIX MATRIX #########################" << endl << endl;

    cout << "###################### PRINTING VERTIX COSTS #########################" << endl;
	grafoAgua->imprimirCostos();
	cout << "################### END PRINTING VERTIX COSTS #########################" << endl << endl;

    grafoAgua->generarMatrizDeAdyacencia();

    cout << "###################### PRINTING EDGES MATRIX #########################" << endl;



    grafoAgua->imprimirMatrizDeAristas();

    cout << "################### END PRINTING EDGES MATRIX #########################" << endl << endl;




    cout << "################### PRINTING PATHS MATRIX #########################" << endl;

    grafoAgua->inicializarMatrizDeRecorrido();

    grafoAgua->imprimirMatrizDeRecorridos();

    cout << "################### END PRINTING PATHS MATRIX #########################" << endl << endl;


    cout << "################### PRINTING FLOYD WARSHALL RESULT #########################" << endl;

    grafoAgua->floydWarshall();

    grafoAgua->imprimirMatrizDeAristas();

    cout << "################### END PRINTING FLOYD WARSHALL RESULT #########################" << endl << endl;

    cout << "################### PRINTING PATHS MATRIX AFTER WARSHALL #########################" << endl;

    grafoAgua->imprimirMatrizDeAristas();

    cout << "##################################################################################" << endl << endl;

    grafoAgua->imprimirMatrizDeRecorridos();

	cout << "################### END PRINTING PATHS MATRIX AFTER WARSHALL #########################" << endl << endl;


	cout << "#################### END PRUEBA GRAFO AGUA ###########################" << endl << endl;


	delete tablero;

	delete grafoAgua;

	/*for(int i = 0; i < CANTIDAD_ARISTAS; i ++)
		delete[] matrizDeAristas[i];
	delete[] matrizDeAristas;*/


	return 0;
}
