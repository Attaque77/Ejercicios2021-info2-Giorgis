#include <iostream>
using namespace std;

    double  tripleLlamadaPorValor(double A){
	A=A*3;                                    //Triplica el valor de A; no el de C
	return A;      
    }
	
	double triplePorReferencia(double &B){
		B=B*3;                               //Triplica el valor de B, pero también el de C
		return B;                               
	}
							  
int main(int argc, char *argv[]) {
	
	double cuenta=2.5;
	tripleLlamadaPorValor(cuenta);
	triplePorReferencia(cuenta);
	
	return 0;
}

