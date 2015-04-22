#include "correpocoyo.h"

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
	cout << "corredor filmado:" << cp.corredorFilmado() << endl;
	while(*(actual->corredor) != dameCorredorEnPos(damePosicion(cp.corredorFilmado()))){		
		actual = actual->siguiente;
	}
	camara = actual;
	printNodo(camara,"camara");
	//RESOLVER CAMARA con indices
}

template<typename T>
CorrePocoyo<T>::~CorrePocoyo(){
	// Los punteros nulos no se liberan
	cout << endl << "Destruyendo... " << endl;
	while(primero != ultimo){
		cout << endl << "sobre " << *(primero->corredor) << endl;
		primero = primero->siguiente;
		cout << "liberando direccion " << primero->anterior << endl;
		delete primero->anterior;
		cout << "liberado" << endl;
	}
	if(primero != NULL){
		cout << endl << "sobre " << *(primero->corredor) << endl;
		cout << "liberando direccion " << primero << endl;
		delete primero;
		cout << "liberado" << endl;
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


	cout << endl << "nuevo corredor nuevo " << endl;
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

	cout << endl << "nuevo corredor nuevo y existente" << endl;
	printNodo(nuevo,"nuevo");
	cout<< endl;
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
void CorrePocoyo<T>:: sobrepasar(const T& c){
	Nodo *actual;
	actual = primero;
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

	}else if((actual->anterior == primero)){
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
	cout << endl;
	printNodo(actual->siguiente,"pasado");
	

}

template<typename T>
bool CorrePocoyo<T>::esVacia() const{
	return (cantCorredores == 0);
}

template<typename T>
int CorrePocoyo<T>::tamanio() const{
	return cantCorredores;
}

template<typename T>
ostream& CorrePocoyo<T>::mostrarCorrePocoyo(ostream& stream) const{
	stream << endl << "Lista de posiciones: " << endl << endl;
	int pos = 1;
	Nodo *actual = primero;
	while(actual != NULL){
		stream << pos << "\t" << *(actual->corredor) << endl;
		actual = actual->siguiente;
		pos++;
	}
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
	cout << "direccion del "<< s <<" nodo: " << n << endl; 
	cout << "direccion "<< s <<" corredor: " << n->corredor << endl;
	cout << "direccion del "<< s <<" anterior: " << n->anterior << endl;
	cout << "direccion del "<< s <<" siguiente: " << n->siguiente << endl;
}