#include "tda/grafo/Grafo.h"
#include "tablero/Tablero.h"
#include "casillero/Casillero.h"
#include "tda/diccionario/Diccionario.h"
#include "tda/lista/lista.h"

#include "terminal/Terminal.h"
#include "validaciones/Validador.h"
#include "utilitario/Utilitario.h"
#include "tda/matriz/Matriz.h"
#include "juego/Juego.h"


using namespace std;

Terminal* Terminal::terminal = 0;
Validador* Validador::validador = 0;
Utilitario* Utilitario::utilitario = 0;

const string TEXTO_SOLICITUD_OPCION = "Por favor, ingrese una opcion para continuar:";

int main() {

	cout << "~~~~ BATALLA DE LOS ELEMENTOS II ~~~~" << endl;
	cout << endl;

	Juego* juego = new Juego();

	Menu* menuPrincipal = juego->getMenuPrincipal();
	Diccionario<string, Personaje*>* personajesDisponibles = juego->getPersonajesDisponibles();
	juego->mostrarMenuPrincipal();
	int opcion = menuPrincipal->obtenerOpcion(TEXTO_SOLICITUD_OPCION);
	int systemResult = juego->validarOpcionPrincipal(opcion, personajesDisponibles, TEXTO_SOLICITUD_OPCION, menuPrincipal);

	delete juego;

	return systemResult;
}
