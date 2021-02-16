#ifndef ARISTA_H_
#define ARISTA_H_

template<class K>
class Arista {
private:
	int peso;
    
public:
    // Crea la arista
    Arista(int peso);

    // Guarda el peso de la arista
    void setPeso(int peso);

    // Devuelve el peso de la arista
    int getPeso();

    // Destructor
    ~Arista();
	
};

template<class K>
Arista<K>::Arista(int peso){
    this->peso = peso;
}

template<class K>
Arista<K>::~Arista() {
    
}

template<class K>
void Arista<K>::setPeso(int peso){
    this->peso = peso;
}

template<class K>
int Arista<K>::getPeso(){
    return this->peso;
}


#endif /* ARISTA_H_ */