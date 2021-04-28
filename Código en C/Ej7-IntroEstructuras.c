#include <stdio.h>
#include <string.h>

struct cliente{
	char apellido[15];
	char nombre[15];
	int numeroCliente;
	struct{
		char numeroTelefonico [20];
		char direccion [50];
		char ciudad [15];
		char estado [10];
		char codigoPostal[6];
	}personal;
	}registroCliente,*ptrCliente;

int main() {
	ptrCliente=&registroCliente;
	
	//manejo de estructura con variable
	strcpy(registroCliente.apellido,"Rodolfo");
	strcpy(registroCliente.nombre,"Menendez");
	registroCliente.numeroCliente = 1;
	strcpy(registroCliente.personal.numeroTelefonico,"3547-401345");
	strcpy(registroCliente.personal.direccion, "Dean Funes 456");
	strcpy(registroCliente.personal.ciudad, "Alta Gracia");
	strcpy(registroCliente.personal.estado, "Soltero");
	strcpy(registroCliente.personal.codigoPostal, "X5186");
	
	/*
	printf("Nombre: %s ",registroCliente.apellido);
	printf("\nApellido: %s ",registroCliente.nombre);
	printf("\nN%cmero de cliente: %i",163,registroCliente.numeroCliente);
	printf("\nN%cmero telef%cnico: %s ",163,162,registroCliente.personal.numeroTelefonico);
	printf("\nDirecci%cn: %s ",162,registroCliente.personal.direccion);
	printf("\nCiudad: %s ",registroCliente.personal.ciudad);
	printf("\nEstado: %s ",registroCliente.personal.estado);
	printf("\nC%cdigo postal: %s ",162,registroCliente.personal.codigoPostal);
	*/
	
	//manejo de estructura con variable de tipo puntero
	strcpy(ptrCliente->apellido,"Rodolfo");
	strcpy(ptrCliente->nombre,"Menendez");
	ptrCliente->numeroCliente = 1;
	strcpy(ptrCliente->personal.numeroTelefonico,"3547-401345");
	strcpy(ptrCliente->personal.direccion, "Dean Funes 456");
	strcpy(ptrCliente->personal.ciudad, "Alta Gracia");
	strcpy(ptrCliente->personal.estado, "Soltero");
	strcpy(ptrCliente->personal.codigoPostal, "X5186");
	
	/*
	printf("Nombre: %s ",ptrCliente->apellido);
	printf("\nApellido: %s ",ptrCliente->nombre);
	printf("\nN%cmero de cliente: %i",163,ptrCliente->numeroCliente);
	printf("\nN%cmero telef%cnico: %s ",163,162,ptrCliente->personal.numeroTelefonico);
	printf("\nDirecci%cn: %s ",162,ptrCliente->personal.direccion);
	printf("\nCiudad: %s ",ptrCliente->personal.ciudad);
	printf("\nEstado: %s ",ptrCliente->personal.estado);
	printf("\nC%cdigo postal: %s ",162,ptrCliente->personal.codigoPostal);
	*/
	
	return 0;
}

