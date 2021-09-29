#include "Veinticuatro.h"
#include <iostream>
using namespace std;

int main() {
	
	complejo g,g1,g2;
	
	g = complejo (15,5);
	g1= complejo (20,1);
	
	cout << "Primer numero: " << endl;
	g.imprimir();
	cout << "\nSegundo numero " << endl;
	g1.imprimir();
	
	g2=g.suma(g1);
	cout << "\nLa suma es: ";
	g2.imprimir();
	
	g2=g.resta(g1);
	cout << "\nLa resta es: ";
	g2.imprimir();
	
	return 0;
}

