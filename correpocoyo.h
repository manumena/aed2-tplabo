#ifndef CORREPOCOYO_H
#define CORREPOCOYO_H

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/* 
 * Se puede asumir que el tipo T tiene constructor por copia y operator==
 * No se puede asumir que el tipo T tenga operator=
 */
template<typename T>
class CorrePocoyo{

  public:

	/*
	 * Crea una nueva carrera
	 */	
	CorrePocoyo();

	/*
	 * Una vez copiada, ambas CorrePocoyos deben ser independientes, 
	 * es decir, cuando se borre una no debe borrar la otra.
	 */	
	CorrePocoyo(const CorrePocoyo<T>&);
	
	/*
	 * Acordarse de liberar toda la memoria!
	 */	 
	~CorrePocoyo();

	/*
	 * Agrega un nuevo corredor al CorrePocoyo. Lo agregará al final 
	 */
	void nuevoCorredor(const T&);
	
	/*
	 * Agrega un nuevo corredor al CorrePocoyo. El primer T es el corredor a agregar y lo hace delante del segundo
	 *
	 * PRE: Existe el segundo corredor 
	 */
	void nuevoCorredor(const T&, const T&);
	
	/*
	 * Elimina del pocoyo al que se envía, NO OLVIDAR LIBERAR LA MEMORIA
	 *
	 * PRE: Existe el corredor
	 */
	void seCansa(const T&);
	/*
	 * El corredor pasa al que está adelante 
	 *
	 * PRE: Existe un corredor delante de él y T es un corredor 
	 */
	void sobrepasar(const T&);
	
	/*
	 * Devuelve el corredor que está siendo filmado.
	 *
	 * PRE: Hay adeptos en la CorrePocoyo.
	 */
	const T& corredorFilmado() const;
	
    /*
	 * Devuelve el próximo elemento según el orden dado.
	 * Pasa a filmar al corredor de atás 
	 *
	 * PRE: Hay corredore en la CorrePocoyo.
	 */
	void filmarProxPerdedor();
	 
	/*
	 * Devuelve el próximo elemento según el orden dado.
	 * Pasa a filmar al corredor de adelante 
	 *
	 * PRE: Hay corredore en la CorrePocoyo.
	 */
	void filmarProxExitoso();
	
	/*
	 * Devuelve al Primero. 
	 *
	 * PRE: Hay elementos 
	 */
	const T& damePrimero() const;	

	/*
	 * Devuelve la posición del elemento pasado por parámetro. 
	 *
	 * PRE: Existe ese corredor 
	 */
	int damePosicion(const T& ) const;	

	/*
	 * Devuelve el corredor de la posición. 
	 *
	 * PRE: Existe al menos esa cantidad de corredores en la carrera
	 */
	const T& dameCorredorEnPos(int) const;	

	/*
	 * Dice si la CorrePocoyo tiene o no corredores.
	 */
	bool esVacia() const;

	
	/*
	 * Devuelve la cantidad de corredores de la CorrePocoyo.
	 */
	int tamanio() const;	

	/*
	 * Devuelve true si las CorrePocoyos son iguales.
	 */
	bool operator==(const CorrePocoyo<T>&) const;
	
	/*
	 * Debe mostrar la carrera por el ostream (y retornar el mismo).
	 * CorrePocoyo vacio: []
	 */
	ostream& mostrarCorrePocoyo(ostream&) const;
	
	
  private:
	/*
	 * No se puede modificar esta funcion.
	 */
	CorrePocoyo<T>& operator=(const CorrePocoyo<T>& otra) {
		assert(false);
		return *this;
	}

	/*
	 * Aca va la implementación del nodo.
	 */
	struct Nodo {
		T *corredor;
		Nodo *anterior;
		Nodo *siguiente;
	};

	Nodo *primero;
	Nodo *ultimo;
	Nodo *camara;
	int cantCorredores;
	void printNodo(Nodo*,string);

	void filmarOtro();

};

template<class T>
ostream& operator<<(ostream& out, const CorrePocoyo<T>& a) {
	return a.mostrarCorrePocoyo(out);
}

// Implementación a hacer por los alumnos.

template<typename T>
CorrePocoyo<T>::CorrePocoyo(){
	primero = NULL;
	ultimo = NULL;
	camara = NULL;
	cantCorredores = 0;
}

template<typename T>
CorrePocoyo<T>::CorrePocoyo(const CorrePocoyo<T>& cp){
	
	int i = 1;
	primero = NULL;
	ultimo = NULL;
	cantCorredores = 0;
	while(i<= cp.tamanio()){
		nuevoCorredor(cp.dameCorredorEnPos(i));
		i++;
	}
	Nodo *actual = primero;
	//cout << "corredor filmado:" << cp.corredorFilmado() << endl;
	while(*(actual->corredor) != dameCorredorEnPos(damePosicion(cp.corredorFilmado()))){		
		actual = actual->siguiente;
	}
	camara = actual;
	printNodo(camara,"camara");
}

template<typename T>
CorrePocoyo<T>::~CorrePocoyo(){
	// Los punteros nulos no se liberan
	//cout << endl << "Destruyendo... " << endl;
	while(primero != ultimo){
		//cout << endl << "sobre " << *(primero->corredor) << endl;
		primero = primero->siguiente;
		//cout << "liberando direccion " << primero->anterior << endl;
		delete primero->anterior;
		//cout << "liberado" << endl;
	}
	if(primero != NULL){
		//cout << endl << "sobre " << *(primero->corredor) << endl;
		//cout << "liberando direccion " << primero << endl;
		delete primero;
		//cout << "liberado" << endl;
	}
}

template<typename T>
void CorrePocoyo<T>::nuevoCorredor(const T& t){
	Nodo *nuevo = new Nodo;
	nuevo->corredor = new T(t);
	nuevo->anterior = ultimo;
	nuevo->siguiente = NULL;
	
	if(primero == NULL) 
		primero = nuevo;
	if(ultimo != NULL)
		ultimo->siguiente = nuevo;
	ultimo = nuevo;

	camara = nuevo;
	cantCorredores++;


	//cout << endl << "nuevo corredor" << endl;
	printNodo(nuevo,"nuevo");

}

template<typename T>
void CorrePocoyo<T>::nuevoCorredor(const T& c1, const T& c2){
	Nodo *actual = primero;
	while(*(actual->corredor) != c2){		
		actual = actual->siguiente;
	}
	
	Nodo *nuevo = new Nodo;
	nuevo->corredor = new T(c1);
	nuevo->siguiente = actual;
	nuevo->anterior = actual->anterior;


	if(actual == primero){
		primero = nuevo;
		
	}else{
		actual->anterior->siguiente = nuevo;
	}
	
	actual->anterior = nuevo;
	camara = nuevo;
	cantCorredores++;

	//cout << endl << "nuevo corredor nuevo y existente" << endl;
	printNodo(nuevo,"nuevo");
	//cout<< endl;
	printNodo(actual,"actual");
}

template<typename T>
void CorrePocoyo<T>::seCansa(const T& t){
	Nodo *actual = primero;
	while(!(*(actual->corredor) == t))
		actual = actual->siguiente;

	if(camara == actual)
		filmarOtro();

	if(actual == primero){
		if(actual == ultimo){
			primero = NULL;
			ultimo = NULL;
			camara = NULL;
		}
		else{
			primero = actual->siguiente;
			actual->siguiente->anterior = NULL;
		}
	}
	else{
		if(actual == ultimo){
			ultimo = actual->anterior;
			actual->anterior->siguiente = NULL;
		}
		else{
			actual->siguiente->anterior = actual->anterior;
			actual->anterior->siguiente = actual->siguiente;
		}
	}
	
	delete actual;
	cantCorredores--;
}

template<typename T>
void CorrePocoyo<T>:: sobrepasar(const T& c){
	Nodo *actual = primero;
	while(*(actual->corredor) != c){		
		actual = actual->siguiente;
	}
	if((ultimo == actual) && (actual->anterior == primero)){
		actual->anterior->anterior = actual;
		actual->siguiente = actual->anterior;
		actual->anterior = NULL;
		actual->siguiente->siguiente = NULL;
		ultimo = actual->siguiente;
		primero = actual;
	}else if(ultimo == actual){
		actual->anterior->anterior->siguiente = actual;
		actual->anterior->siguiente = NULL;
		actual->siguiente =actual->anterior;
		actual->anterior = actual->anterior->anterior;
		actual->siguiente->anterior = actual;
		ultimo = actual->siguiente;
	}else if(actual->anterior == primero){
		actual->siguiente->anterior = actual->anterior;
		actual->anterior->siguiente = actual->siguiente;
		actual->anterior->anterior = actual;
		actual->siguiente = actual->anterior;
		actual->anterior = NULL;
		primero = actual;
	}else{
		actual->anterior->anterior->siguiente = actual;
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
		actual->siguiente = actual->anterior;
		actual->anterior = actual->anterior->anterior;
		actual->siguiente->anterior = actual;
	}
	printNodo(actual,"actual");
	//cout << endl;
	printNodo(actual->siguiente,"pasado");
	

}

template<typename T>
const T& CorrePocoyo<T>::corredorFilmado() const{
	return *(camara->corredor);
}

template<typename T>
void CorrePocoyo<T>::filmarProxPerdedor(){
	camara = camara->siguiente;
}

template<typename T>
void CorrePocoyo<T>::filmarProxExitoso(){
	camara = camara->anterior;
}

template<typename T>
const T& CorrePocoyo<T>::damePrimero() const{
	return dameCorredorEnPos(0);
}

template<typename T>
int CorrePocoyo<T>::damePosicion(const T& t) const{
	int pos = 1;
	Nodo *actual = primero;
	while(*(actual->corredor) != t){
		pos++;
		actual = actual->siguiente;
	}
	return pos;
}

template<typename T>
const T& CorrePocoyo<T>::dameCorredorEnPos(int p) const{
	int i = 1;
	Nodo *actual = primero;
	while(i < p){
		actual = actual->siguiente;
		i++;
	}
	return *(actual->corredor);
}

template<typename T>
bool CorrePocoyo<T>::esVacia() const{
	return (cantCorredores == 0);
}

template<typename T>
int CorrePocoyo<T>::tamanio() const{
	return cantCorredores;
}

template<class T>
bool CorrePocoyo<T>::operator==(const CorrePocoyo<T>& c) const{
	if((cantCorredores != c.cantCorredores) || !(*(camara->corredor) == *(c.camara->corredor)))
		return false;
	else{
		int pos = 1;
		while(pos <= c.cantCorredores){
			//cout << "Pos: " << pos << endl;
			//cout << "Corredor en original: " << dameCorredorEnPos(pos) << endl;
			//cout << "Corredor en otra: " << c.dameCorredorEnPos(pos) << endl;
			if(dameCorredorEnPos(pos) != c.dameCorredorEnPos(pos))
				return false;
			pos++;
		}
	}
	return true;
}

template<typename T>
ostream& CorrePocoyo<T>::mostrarCorrePocoyo(ostream& stream) const{
	stream << "[";
	int pos = 1;
	Nodo *actual = primero;
	while(actual != NULL){
		stream << *(actual->corredor);
		if(actual->siguiente != NULL)
			stream << ", ";
		actual = actual->siguiente;
		pos++;
	}
	stream << "]";
	return stream;
}

template<typename T>
void CorrePocoyo<T>::filmarOtro(){
	if(camara == primero){
		if(camara == ultimo)
			camara = NULL;
		else
			filmarProxPerdedor();
	}else{
		filmarProxExitoso();
	}
}

template<typename T>
void CorrePocoyo<T>::printNodo(Nodo* n,string s){
	//cout << endl << "direccion del "<< s <<" nodo: " << n << endl; 
	//cout << "direccion "<< s <<" corredor: " << n->corredor << endl;
	//cout << "direccion del "<< s <<" anterior: " << n->anterior << endl;
	//cout << "direccion del "<< s <<" siguiente: " << n->siguiente << endl;
}

#endif //CORREPOCOYO_H
