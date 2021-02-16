#ifndef VERTICE_H_
#define VERTICE_H_

template<class T>
class Vertice {
private:
    T data;
    bool visitado;

    
public:
    // Crea un vertice
    Vertice(T data);

    // Destruye el vertice
    ~Vertice();

    // Destructortemplate<class K>
void Arista<K>::setPeso(int peso){
    this->peso = peso;
} 

    // Agrega la data al vertice
    void setData(T data);

    void setVisitado();

    T getData();

    bool fueVisitado();
	
};

template<class T>
Vertice<T>::~Vertice() {
    
}

template<class T>
Vertice<T>::Vertice(T data) {
    this->visitado = false;
    this->data = data;
}

template<class T>
void Vertice<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Vertice<T>::setVisitado() {
    this->visitado = !this->visitado;
}

template<class T>
T Vertice<T>::getData() {
    return this->data;
}

template<class T>
bool Vertice<T>:: fueVisitado(){
    return this->visitado == true;
}

#endif /* VERTICE_H_ */