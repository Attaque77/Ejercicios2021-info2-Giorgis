//Practica con punteros
#include <stdio.h>
#include <math.h>

int main ()
{
	long valor1=200000;
	long valor2;
	long *ptrL;
	ptrL=&valor1;
	printf("El valor al que apunta 'ptrL' es: %ld\n",*ptrL);
	valor2=*ptrL;
	printf("El valor de 'valor2' es de: %ld\n",valor2);
	printf("Direccion de 'valor1 es: %p\n", &valor1);
	printf("Direccion de 'ptrL' es: %p",ptrL);
	
	//La dirección que imprimió 'ptrL' es igual 'valor1' porque un puntero apunta a la  direccción de memoria de la variable que le dio su dirección
}

