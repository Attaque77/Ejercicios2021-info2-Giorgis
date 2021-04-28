#include <stdio.h>

struct sensores{
	 char sensor;             // 1 byte
	 int valor;               // 4 byte
	 unsigned long tiempo;    // 4 byte
}muestra;


int main() {
	
	/*El espacio ucupado por la estructura es el tamaño de memoria del tipo de dato que ocupa mayor cantidad de memoria, multiplicado por la 
	  cantidad de datos que haya en la estrucura*/
	printf("El tama%co que ocupa la estructura sensores es de: %u byts",164,sizeof(muestra)); 
	
	return 0;
}

