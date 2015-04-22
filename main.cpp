#include "correpocoyo.h"
#include "correpocoyo.cpp"
#include <iostream>

using namespace std;

int main(){
	CorrePocoyo<int> carrera;

	carrera.nuevoCorredor('A');
	carrera.nuevoCorredor('B');
	carrera.nuevoCorredor('C');
	carrera.nuevoCorredor('D');
	cout << carrera;

	carrera.sobrepasar('D');
	cout << carrera;
	carrera.sobrepasar('D');
	cout << carrera;
	carrera.sobrepasar('D');
	cout << carrera;
	/*cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl; 	//Me devuelve 1 en lugar de true


	carrera.nuevoCorredor('A');
	carrera.nuevoCorredor('B');
	carrera.nuevoCorredor('C');
	carrera.nuevoCorredor('D');
	carrera.nuevoCorredor('E');

	cout << endl << "Cantidad de corredores: " << carrera.tamanio() << endl;
	// cout << endl << "Carrera vacia?: " << carrera.esVacia() << endl;

	cout << "Camara en: " << carrera.corredorFilmado() << endl;

	cout << carrera << endl;

	// cout << "Primero: " << carrera.damePrimero() << endl;

	// cout << "Posicion de A: " << carrera.damePosicion('A') << endl;
	// cout << "Posicion de B: " << carrera.damePosicion('B') << endl;
	// cout << "Posicion de C: " << carrera.damePosicion('C') << endl;
	// cout << "Posicion de D: " << carrera.damePosicion('D') << endl;
	// cout << "Posicion de E: " << carrera.damePosicion('E') << endl;

	// CorrePocoyo<int> carreraClone(carrera);

	// carrera.nuevoCorredor('F','A');
	// carrera.nuevoCorredor('G','E');

	// carrera.seCansa('A');
	// cout << carrera;
	// carrera.seCansa('E');
	// cout << carrera;
	// carrera.seCansa('C');
	// cout << carrera;
	// carrera.seCansa('D');
	// cout << carrera;
	// carrera.seCansa('B');
	// cout << carrera;
	
	// carrera.filmarProxExitoso();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxExitoso();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxExitoso();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxExitoso();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxPerdedor();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxPerdedor();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxPerdedor();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;
	// carrera.filmarProxPerdedor();
	// cout << "Camara en: " << carrera.corredorFilmado() << endl;


	cout << endl;
*/


	return 0;
}