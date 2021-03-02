#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

template<class Dato>
class Lista {
private:
    // atributos
    Nodo<Dato>* primero;
    Nodo<Dato>* actual;
    int cantidad;

public:
    // constructor
    // POS: crea una cola vacia
    Lista();

    // PRE: 0 < pos <= cantidad + 1
    // POS: inserta el dato d en la posicion pos, la 1 es la primera
    //        ademas incrementa cantidad en 1
    void alta(Dato d, int pos);

    // PRE: 0 < pos <= cantidad
    // POS: saca el elemento que esta en pos
    void baja(int pos);

    void baja(Dato d);

    // PRE: 0 < pos <= cantidad
    // POS: devuelve el elemento que esta en pos
    Dato consulta(int pos);

    // PRE:
    // POS: devuelve true si la lista esta vacia.
    bool vacia();

    // POS: libera la memoria
    virtual ~Lista();

    // PRE:
    // POS: devuelve la cantidad de elementos en la lista.
    int obtenerCantidad();

    // PRE:
    // POS: reinicia la posicion actual del iterador.
    void reiniciar();

    // PRE:
    // POS: devuelve true si el iterador puede seguir avanzando a la siguiente posicion, false caso contrario.
    bool haySiguiente();

    // PRE: haySiguiente() == true
    // POS: devuelve el Dato de la siguiente posicion.
    Dato siguiente();

    //POS: devuelve true si d esta en lista, false caso contrario
    bool esta(Dato d);

    //POS: devuelve la posicion en la que se encuentra d, retorna -1 si no se encuentra
    int obtenerPosicion(Dato d);

private:
    Nodo<Dato>* obtenerNodo(int pos);
};


template<class Dato>
Lista<Dato>::Lista() {
    primero = 0;
    actual = 0;
    cantidad = 0;
}

template<class Dato>
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

template<class Dato>
void Lista<Dato>::alta(Dato d, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (pos == 1) {
        nuevo->cambiarSiguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else {
        Nodo<Dato>* anterior = obtenerNodo(pos - 1);
        Nodo<Dato>* siguiente = anterior->obtenerSiguiente();
        nuevo->cambiarSiguiente(siguiente);
        anterior->cambiarSiguiente(nuevo);
    }

    cantidad++;
}

template<class Dato>
Nodo<Dato>* Lista<Dato>::obtenerNodo(int pos) {
    Nodo<Dato>* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtenerSiguiente();
    return aux;
}

template<class Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* aux = obtenerNodo(pos);
    return aux->obtenerDato();
}


template<class Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato>* nodoABorrar;
    if (pos == 1) {
    	nodoABorrar = primero;
        primero = nodoABorrar->obtenerSiguiente();
    } else {
        Nodo<Dato>* anterior = obtenerNodo(pos - 1);
        nodoABorrar = anterior->obtenerSiguiente();
        Nodo<Dato>* siguiente = nodoABorrar->obtenerSiguiente();
        anterior->cambiarSiguiente(siguiente);
    }
    reiniciar();
    delete nodoABorrar;
    cantidad--;
}

template<class Dato>
Lista<Dato>::~Lista()  {
    while (! vacia())
        baja(1);
}

template<class Dato>
int Lista<Dato>::obtenerCantidad()  {
    return cantidad;
}

template<class Dato>
void Lista<Dato>::reiniciar() {
	this->actual = this->primero;
}

template<class Dato>
bool Lista<Dato>::haySiguiente() {
	return (this->actual != 0);
}

template<class Dato>
Dato Lista<Dato>::siguiente() {
	Nodo<Dato>* aux = this->actual;
	this->actual = this->actual->obtenerSiguiente();
	return aux->obtenerDato();
}

template<class Dato>
bool Lista<Dato>::esta(Dato d) {

	bool encontrado = false;
	reiniciar();

	while (haySiguiente() && !encontrado) {
		encontrado = siguiente() == d;
	}

	return encontrado;
}

template<class Dato>
int Lista<Dato>::obtenerPosicion(Dato d) {
	int pos = 0;
	bool encontrado = false;
	reiniciar();

	while (haySiguiente() && !encontrado) {
		encontrado = siguiente() == d;
		pos++;
	}

	if(!encontrado) {
		pos = -1;
	}

	return pos;
}

template<class Dato>
void Lista<Dato>::baja(Dato d) {
	int pos = obtenerPosicion(d);
	if (pos > 0)
		baja(pos);
}


#endif // LISTA_H_INCLUDED
