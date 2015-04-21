#include "correpocoyo.h"
#include <iostream>

using namespace std;

int main(){
	CorrePocoyo<int> carrera;
	cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl; 	//Me devuelve 1 en lugar de true

	carrera.nuevoCorredor('J');
	carrera.nuevoCorredor('M');
	carrera.nuevoCorredor('H');
	carrera.nuevoCorredor('L');
	carrera.nuevoCorredor('Q');

	cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl;

	cout << carrera;
	
	cout << endl;
	return 0;
}