#include "Veintiseis_24.h"
#include <iostream>
using namespace std;

int main() {
	
	complejo g,g1;
	
	g = complejo (15,5);
	g1= complejo (20,1);
	
	cout << "Primer numero: " << endl;
	g.imprimir();
	cout << "\nSegundo numero " << endl;
	g1.imprimir();
	
	g.suma(g1).resta(g1);
	
	return 0;
}
