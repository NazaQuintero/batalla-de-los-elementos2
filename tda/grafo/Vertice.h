/*
 * Vertice.h
 *
 *  Created on: Feb 17, 2021
 *      Author: nazaquintero
 */

#ifndef VERTICE_H_
#define VERTICE_H_

template<class T, class K>
class Vertice {
private:
	T data;
	K peso;

public:
	Vertice();
    
    // Crea la arista
    Vertice(T data, K peso);

    // Guarda el data de la arista
    void setData(T data);

    // Devuelve el data de la arista
    T getData();

    void setPeso(K peso);

    K getPeso();

    // Destructor
    ~Vertice();

};

template<class T, class K>
Vertice<T, K>::Vertice(){

}

template<class T, class K>
Vertice<T, K>::Vertice(T data, K peso){
    this->data = data;
    this->peso = peso;
}

template<class T, class K>
Vertice<T, K>::~Vertice() {

}

template<class T, class K>
void Vertice<T, K>::setData(T data){
    this->data = data;
}

template<class T, class K>
T Vertice<T, K>::getData(){
    return this->data;
}

template<class T, class K>
void Vertice<T, K>::setPeso(K peso){
    this->peso = peso;
}

template<class T, class K>
K Vertice<T, K>::getPeso(){
    return this->peso;
}



#endif /* VERTICE_H_ */
