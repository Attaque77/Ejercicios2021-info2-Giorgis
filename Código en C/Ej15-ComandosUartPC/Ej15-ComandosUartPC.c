#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "rs232.h"

#define LONG_BUFFER 4096

int main()
{
	int puertoCOM=2;             //N�mero de puerto. 2 es para el COM3 en windows
	int baudios=9600;            //Velocidad en baudios
	char modo[]={'8','N','1',0}; // 8 bits de datos, no paridad, 1 bit de parada
	
	unsigned char bufferRecepcion[LONG_BUFFER];
	int cantidadBytes;
	
	
	if(RS232_OpenComport(puertoCOM, baudios, modo, 0)) //Prueba abrir el puerto, devuelve 1 en caso de error
	{
		printf("No se puede abrir el puerto COM\n");
		return(0);
	}
	
	while(1)
	{
		//Env�a un byte sobre el puerto COM elegido
		RS232_SendByte(puertoCOM, 'E');
		Sleep(1000); //Retardo de 100 ms
		
		//Lee los datos almacenados en el buffer del puerto COM y los guarda en bufferRecepcion
		//Devuelve la cantidad de bytes le�dos
		cantidadBytes = RS232_PollComport(puertoCOM, bufferRecepcion, LONG_BUFFER-1);
		
		if(cantidadBytes > 0)
		{
			bufferRecepcion[cantidadBytes] = 0;   // Poner un NULL al final del string
			
			printf("Se recibieron %i bytes: %s\n", cantidadBytes, (char*) bufferRecepcion);
		}
		
		RS232_SendByte(puertoCOM, 'A');
		Sleep(1000); //Retardo de 100 ms
		
		cantidadBytes = RS232_PollComport(puertoCOM, bufferRecepcion, LONG_BUFFER-1);
		
		if(cantidadBytes > 0)
		{
			bufferRecepcion[cantidadBytes] = 0;   // Poner un NULL al final del string
			
			printf("Se recibieron %i bytes: %s\n", cantidadBytes, (char *)bufferRecepcion);
		}
		
	}
	
	return(0);
}
