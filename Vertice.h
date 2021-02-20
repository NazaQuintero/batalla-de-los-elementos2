/*
 * Vertice.h
 *
 *  Created on: Feb 17, 2021
 *      Author: nazaquintero
 */

#ifndef VERTICE_H_
#define VERTICE_H_

template<class T>
class Vertice {
private:
	T data;

public:
	Vertice();
    // Crea la arista
    Vertice(T data);

    // Guarda el data de la arista
    void setData(T data);

    // Devuelve el data de la arista
    T getData();

    // Destructor
    ~Vertice();

};

template<class T>
Vertice<T>::Vertice(){

}

template<class T>
Vertice<T>::Vertice(T data){
    this->data = data;
}

template<class T>
Vertice<T>::~Vertice() {

}

template<class T>
void Vertice<T>::setData(T data){
    this->data = data;
}

template<class T>
T Vertice<T>::getData(){
    return this->data;
}



#endif /* VERTICE_H_ */
