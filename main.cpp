#include "correpocoyo.h"
#include "correpocoyo.cpp"
#include <iostream>

using namespace std;

int main(){
	CorrePocoyo<int> carrera;
	cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl; 	//Me devuelve 1 en lugar de true

	carrera.nuevoCorredor('A');
	carrera.nuevoCorredor('B');
	carrera.nuevoCorredor('C');
	carrera.nuevoCorredor('D');
	carrera.nuevoCorredor('E');

	cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl;

	cout << carrera;


	//CorrePocoyo<int> carreraClone(carrera);
	carrera.nuevoCorredor('F','A');
	carrera.nuevoCorredor('G','E');

	cout << carrera;
	




	
	cout << endl;
	return 0;
}