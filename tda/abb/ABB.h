/*
 * ABB.h
 *
 *  Created on: Feb 4, 2021
 *      Author: nazaquintero
 */

#ifndef SRC_ABB_H_
#define SRC_ABB_H_

#include "./NodoAbb.h"
#include <iostream>

template<class K, class T>
class ABB {
private:
	// Atributos
	NodoABB<K, T> *raiz;

	// Métodos
	NodoABB<K, T>* insertar(NodoABB<K, T> *nodo, K clave, T data);
	void imprimirInOrder(NodoABB<K, T> *nodo);
	NodoABB<K, T>* buscar(NodoABB<K, T> *nodo, K clave);
	K obtenerMin(NodoABB<K, T> *nodo);
	K obtenerMax(NodoABB<K, T> *nodo);
	K sucesor(NodoABB<K, T> *nodo);
	K predecesor(NodoABB<K, T> *nodo);
	NodoABB<K, T>* borrar(NodoABB<K, T> *nodo, K clave);
	void borrarTodo(NodoABB<K, T> *nodo);

public:
	// Metodos

	// Crea un ABB vacio.
	ABB();

	// Agrega un nuevo nodo al ABB actual. Si el ABB estaVacio
	// el nodo insertado será la raíz.
	bool insertar(K clave, T data);

	// Imprime la informacion guardada en el ABB.
	// Ordenada de menor a mayor
	void imprimirInOrder();

	// Busca una clave dada en el ABB.
	// Si la clave existe devuelve TRUE.
	bool buscar(K clave);

	// Busca la clave dada en el ABB y devuelve el dato.
	T getDato(K clave);

	// Busca el valor minimo de clave existente en el ABB.
	K obtenerMin();

	// Busca el valor maximo de clave existente en el ABB.
	K obtenerMax();

	// Encuentra el sucesor de una clave dada.
	K sucesor(K clave);

	// Encuentra el predecesor de una clave dada.
	K predecesor(K clave);

	// Remueve la data correspondiente a una clave del ABB.
	T borrar(K clave);

	// Devuelve la raiz del ABB.
	NodoABB<K, T>* getRaiz();

	//Devuelve TRUE si el ABB esta vacio.
	bool estaVacio();

	// Borra todos los nodos del ABB.
	void borrarTodo();

	virtual ~ABB<K, T>();

};

template<class K, class T>
ABB<K, T>::ABB() {
	this->raiz = 0;
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::insertar(NodoABB<K, T> *nodo, K clave, T data) {

	if (!nodo) {
		nodo = new NodoABB<K, T>(clave, data);
	}

	else if (clave > nodo->getClave()) {
		nodo->setDerecho(insertar(nodo->getDerecho(), clave, data), nodo);
	}

	else {
		nodo->setIzquierdo(insertar(nodo->getIzquierdo(), clave, data), nodo);
	}
	return nodo;
}

template<class K, class T>
bool ABB<K, T>::insertar(K clave, T data) {
	this->raiz = insertar(this->raiz, clave, data);
	return this->raiz != 0;
}

template<class K, class T>
void ABB<K, T>::imprimirInOrder(NodoABB<K, T> *nodo) {
	if (nodo != 0) {
		imprimirInOrder(nodo->getIzquierdo());
		std::cout << nodo->getClave() << " vida: " << nodo->getData() << "|";
		imprimirInOrder(nodo->getDerecho());
	}
}

template<class K, class T>
void ABB<K, T>::imprimirInOrder() {
	this->imprimirInOrder(this->raiz);
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::buscar(NodoABB<K, T> *nodo, K clave) {
	if (!nodo || nodo->getClave() == clave)
		return nodo;

	if (clave > nodo->getClave())
		return buscar(nodo->getDerecho(), clave);

	return buscar(nodo->getIzquierdo(), clave);
}

template<class K, class T>
bool ABB<K, T>::buscar(K clave) {
	NodoABB<K, T> *result = buscar(this->raiz, clave);

	return result != 0;
}

template<class K, class T>
T ABB<K, T>::getDato(K clave) {
	NodoABB<K, T> *nodo = buscar(this->raiz, clave);
	if (!nodo)
		return 0;

	return nodo->getData();
}

template<class K, class T>
K ABB<K, T>::obtenerMin(NodoABB<K, T> *nodo) {
	if (!nodo)
		return 0;
	else if (!nodo->getIzquierdo())
		return nodo->getClave();
	else
		return obtenerMin(nodo->getIzquierdo());
}

template<class K, class T>
K ABB<K, T>::obtenerMin() {
	return obtenerMin(this->raiz);
}

template<class K, class T>
K ABB<K, T>::obtenerMax(NodoABB<K, T> *nodo) {
	if (!nodo)
		return -1;
	else if (!nodo->getDerecho())
		return nodo->getClave();
	else
		return obtenerMax(nodo->getDerecho());
}

template<class K, class T>
K ABB<K, T>::obtenerMax() {
	return obtenerMax(this->raiz);
}

template<class K, class T>
K ABB<K, T>::sucesor(NodoABB<K, T> *nodo) {
	if (nodo->getDerecho() != 0) {
		return obtenerMin(nodo->getDerecho());
	}
	NodoABB<K, T> *sucesor = 0;
	NodoABB<K, T> *ancestro = this->raiz;
	while (ancestro != nodo) {
		if (nodo->getClave() < ancestro->getClave()) {
			sucesor = ancestro;
			ancestro = ancestro->getIzquierdo();
		} else
			ancestro = ancestro->getDerecho();
	}
	return sucesor->getClave();
}

template<class K, class T>
K ABB<K, T>::sucesor(K clave) {
	NodoABB<K, T> *nodo = this->buscar(this->raiz, clave);
	// Devuelve la clave. Si no encuentra la clave o en el sucesor, devuelve -1
	if (!nodo)
		return 0;
	else
		return sucesor(nodo);
}

template<class K, class T>
K ABB<K, T>::predecesor(NodoABB<K, T> *nodo) {
	if (nodo->getIzquierdo() != 0) {
		return obtenerMax(nodo->getIzquierdo());
	}

	NodoABB<K, T> *sucesor = 0;
	NodoABB<K, T> *ancestro = this->raiz;
	while (ancestro != nodo) {
		if (nodo->getClave() > ancestro->getClave()) {
			sucesor = ancestro;
			ancestro = ancestro->getDerecho();
		} else
			ancestro = ancestro->getIzquierdo();
	}
	return sucesor->getClave();
}

template<class K, class T>
K ABB<K, T>::predecesor(K clave) {
	NodoABB<K, T> *nodo = this->buscar(this->raiz, clave);

	if (!nodo)
		return -1;
	else
		return predecesor(nodo);
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::borrar(NodoABB<K, T> *nodo, K clave) {
	// El nodo no se encuentra en el ABB
	if (!nodo)
		return 0;

	if (nodo->getClave() == clave) {
		if (nodo->esHoja())
			delete nodo;
		else if (nodo->tieneSoloHijoDerecho()) {
			nodo->getDerecho()->setPadre(nodo->getPadre());

			NodoABB<K, T> *aux = nodo;
			nodo = nodo->getDerecho();
			delete aux;
		} else if (nodo->tieneSoloHijoIzquierdo()) {
			nodo->getIzquierdo()->setPadre(nodo->getPadre());

			NodoABB<K, T> *aux = nodo;
			nodo = nodo->getIzquierdo();
			delete aux;
		}

		// El nodo tiene dos hijos (izquierdo y derecho)
		else {

			K sucesor_clave = this->sucesor(clave);

			// Reemplaza la clave del nodo por la de su sucesor
			nodo->setClave(sucesor_clave);

			// Elimina la antigua clave del sucesor
			nodo->setDerecho(borrar(nodo->getDerecho(), sucesor_clave));
		}
	}

	else if (nodo->getClave() < clave)
		nodo->setDerecho(borrar(nodo->getDerecho(), clave));

	else
		nodo->setIzquierdo(borrar(nodo->getIzquierdo(), clave));

	return nodo;
}

template<class K, class T>
T ABB<K, T>::borrar(K clave) {
	this->raiz = borrar(this->raiz, clave);
	return this->raiz->getData();
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::getRaiz() {
	return this->raiz;
}

template<class K, class T>
bool ABB<K, T>::estaVacio() {
	return this->raiz == 0;
}

template<class K, class T>
void ABB<K, T>::borrarTodo(NodoABB<K, T> *nodo) {
	if (!nodo)
		return;
	
	borrarTodo(nodo->getIzquierdo());
	borrarTodo(nodo->getDerecho());
	delete nodo;
}

template<class K, class T>
void ABB<K, T>::borrarTodo() {
	borrarTodo(this->raiz);
}

template<class K, class T>
ABB<K, T>::~ABB<K, T>() {
	borrarTodo();
}

#endif /* SRC_ABB_H_ */
