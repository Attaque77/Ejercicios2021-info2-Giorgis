#include <stdio.h>

struct complejo{
	float real;
	float imaginario;
}x,*px,cx[100];

int main() {
	
	x.real=1.3;
	x.imaginario=-2.2;
	
	px=&x;
	px->real=1.3;
	px->imaginario=-2.2;
	
	cx[18].real=1.3;
	cx[18].imaginario=-2.2;
	
	//Comprobaciones
	
	/*
	printf("REAL: %.2f\n",x.real);
	printf("IMAGINARIO: %.2f",x.imaginario);
	
	printf("REAL: %.2f\n",px->real);
	printf("IMAGINARIO: %.2f",px->imaginario);
	
	printf("REAL: %.2f\n",cx[18].real);
	printf("IMAGINARIO: %.2f",cx[18].imaginario);
	*/
	
	return 0;
}

