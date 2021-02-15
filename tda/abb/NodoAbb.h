/*
 * NodoAbb.h
 *
 *  Created on: Feb 4, 2021
 *      Author: nazaquintero
 */

#ifndef SRC_NODOABB_H_
#define SRC_NODOABB_H_

template<class K, class T>
class NodoABB {
private:
	K clave;
	T data;
	NodoABB<K, T> *izquierdo; //Hijo izquierdo.
	NodoABB<K, T> *derecho; //Hijo derecho.
	NodoABB<K, T> *padre;

public:
	NodoABB(K clave, T data);
	T getData();
	void setData(K clave);
	K getClave();
	void setClave(K clave);
	void setDerecho(NodoABB<K, T> *derecho, NodoABB<K, T> *padre);
	void setIzquierdo(NodoABB<K, T> *izquierdo, NodoABB<K, T> *padre);
	void setIzquierdo(NodoABB<K, T> *izquierdo);
	void setDerecho(NodoABB<K, T> *derecho);
	void setPadre(NodoABB<K, T> *padre);
	NodoABB<K, T>* getDerecho();
	NodoABB<K, T>* getIzquierdo();
	NodoABB<K, T>* getPadre();
	bool esHoja();
	bool tieneSoloHijoDerecho();
	bool tieneSoloHijoIzquierdo();
	virtual ~NodoABB<K, T>();
};

template<class K, class T>
NodoABB<K, T>::NodoABB(K clave, T data) {
	this->clave = clave;
	this->data = data;
	this->izquierdo = nullptr;
	this->derecho = nullptr;
	this->padre = nullptr;
}

template<class K, class T>
T NodoABB<K, T>::getData() {
	return this->data;
}

template<class K, class T>
void NodoABB<K, T>::setData(K clave) {
	this->data = data;
}

template<class K, class T>
K NodoABB<K, T>::getClave() {
	return this->clave;
}

template<class K, class T>
void NodoABB<K, T>::setClave(K clave) {
	this->clave = clave;
}

template<class K, class T>
void NodoABB<K, T>::setDerecho(NodoABB<K, T> *derecho, NodoABB<K, T> *padre) {
	this->derecho = derecho;
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::setDerecho(NodoABB<K, T> *derecho) {
	this->derecho = derecho;
}

template<class K, class T>
void NodoABB<K, T>::setIzquierdo(NodoABB<K, T> *izquierdo,
		NodoABB<K, T> *padre) {
	this->izquierdo = izquierdo;
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::setPadre(NodoABB<K, T> *padre) {
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::setIzquierdo(NodoABB<K, T> *izquierdo) {
	this->izquierdo = izquierdo;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::getDerecho() {
	return this->derecho;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::getIzquierdo() {
	return this->izquierdo;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::getPadre() {
	return this->padre;
}

template<class K, class T>
bool NodoABB<K, T>::esHoja() {
	return (!this->getIzquierdo() && !this->getDerecho());
}

template<class K, class T>
bool NodoABB<K, T>::tieneSoloHijoDerecho() {
	return (!this->getIzquierdo() && this->getDerecho() != 0);
}

template<class K, class T>
bool NodoABB<K, T>::tieneSoloHijoIzquierdo() {
	return (this->getIzquierdo() != 0 && !this->getDerecho());
}

template<class K, class T>
NodoABB<K, T>::~NodoABB<K, T>() {
	delete data;
}

#endif /* SRC_NODOABB_H_ */
