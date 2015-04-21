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
	cantCorredores = 0;
}

template<typename T>
CorrePocoyo<T>::~CorrePocoyo(){
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

	cantCorredores++;

	cout << endl << "nuevo corredor" << endl << "direccion del nuevo nodo: " << nuevo << endl << "direccion nuevo corredor: " << nuevo->corredor << endl << "direccion del anterior: " << nuevo->anterior << endl << "direccion del siguiente: " << nuevo->siguiente << endl;
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
	Nodo *actual;
	actual = primero;
	while(actual != NULL){
		stream << pos << "\t" << *(actual->corredor) << endl;
		actual = actual->siguiente;
		pos++;
	}
	return stream;
}