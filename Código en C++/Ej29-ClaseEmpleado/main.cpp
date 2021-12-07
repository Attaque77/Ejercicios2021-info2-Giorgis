#include<iostream>
#include "Empleado.h"
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]) {
	
	Comercial C1, C2;
	Repartidor R1, R2;
	
	C1= Comercial ("Lucas", 31, 80000, 25020);
	C2= Comercial ("Juan", 25, 30000, 13000);
	
	R1= Repartidor ( "Francisco", 24, 35000, 3);
	R2= Repartidor (" Mauricio", 33, 60000, 1);
	
	cout<<"El salario de Lucas es: $"<<C1.ObtenerSalario()<<endl;
	cout<<"El salario de Juan es: $"<<C2.ObtenerSalario()<<endl;
	cout<<"El salario de Francisco es: $"<<R1.ObtenerSalario()<<endl;
	cout<<"El salario de Mauricio es: $"<<R2.ObtenerSalario()<<endl;
		
	return 0;
}

