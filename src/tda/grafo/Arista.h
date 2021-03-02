#ifndef ARISTA_H_
#define ARISTA_H_

template<class K>
class Arista {
private:
	K peso;
    
public:
	Arista();
    // Crea la arista
    Arista(K peso);

    // Guarda el peso de la arista
    void setPeso(K peso);

    // Devuelve el peso de la arista
    K getPeso();

    // Destructor
    ~Arista();
	
};

template<class K>
Arista<K>::Arista(){

}

template<class K>
Arista<K>::Arista(K peso){
    this->peso = peso;
}

template<class K>
Arista<K>::~Arista() {
    
}

template<class K>
void Arista<K>::setPeso(K peso){
    this->peso = peso;
}

template<class K>
K Arista<K>::getPeso(){
    return this->peso;
}


#endif /* ARISTA_H_ */
