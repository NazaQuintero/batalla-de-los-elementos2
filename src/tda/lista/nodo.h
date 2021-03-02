#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>

using namespace std;


template<class Dato>
class Nodo {
private:
    // atributos
    Dato dato;
    Nodo* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    Nodo(Dato d);

    // destructor
    ~Nodo();

    // PRE:
    // POS: cambia el dato del nodo.
    void cambiarDato(Dato d);

    // PRE:
    // POS: cambia la referencia al siguiente nodo del parametro implicito
    void cambiarSiguiente(Nodo* s);

    // PRE:
    // POS: devuelve el dato del nodo.
    Dato obtenerDato();

    // PRE:
    // POS: devuelve el nodo siguiente al nodo pasado por parametro implicito.
    Nodo* obtenerSiguiente();
};

template<class Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

template<class Dato>
Nodo<Dato>::~Nodo() {

}

template<class Dato>
void Nodo<Dato>::cambiarDato(Dato d) {
    dato = d;
}

template<class Dato>
void Nodo<Dato>::cambiarSiguiente(Nodo* s) {
    this->siguiente = s;
}

template<class Dato>
Dato Nodo<Dato>::obtenerDato() {
    return dato;
}

template<class Dato>
Nodo<Dato>* Nodo<Dato>::obtenerSiguiente() {
    return siguiente;
}

#endif // NODO_H_INCLUDED
