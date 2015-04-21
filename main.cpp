#include "correpocoyo.h"
#include <iostream>

using namespace std;

int main(){
	CorrePocoyo<int> carrera;
	cout << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << "Carrera vacia?: " << carrera.esVacia() << endl; 	//Me devuelve 1 en lugar de true

	carrera.nuevoCorredor(3);
	cout << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << "Carrera vacia?: " << carrera.esVacia() << endl;

	cout << carrera;
	return 0;
}