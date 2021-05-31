#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdint.h>

struct sensores{
	int16_t valor;               
	int32_t tiempo;  
	char sensor;         
}escribir,leer;

int main() {
	
	FILE *f_datos;
	
	printf("DATOS DEL SENSOR INGRESADOS\n");
	printf("Ingrese la letra del sensor: ");
	scanf("%c",&escribir.sensor);
	printf("Ingrese el valor de la lectura: ");
	scanf("%d",&escribir.valor);
	printf("Ingrese el tiempo de la lectura: ");
	scanf("%lu",&escribir.tiempo);
	
	////Apertura de archivo como escritura
	if( (f_datos=fopen("Ejercicio12.dat","w") )==NULL){
		printf("\nERROR - No se ha podido abrir el archivo -");
	}	
	else{
		fwrite(&escribir, sizeof (struct sensores) , 1, f_datos);
		fclose(f_datos);
	}
	
	//Apertura de archivo como lectura
		if( (f_datos=fopen("Ejercicio12.dat","r") )==NULL)
	{
		printf("\nERROR - No se puede abrir archivo especificado\n");
	}
		
	else
	{
		printf("\nDATOS DEL SENSOR LEIDOS");	
		fread((uint8_t*)&leer,sizeof(leer),1,f_datos);
		printf("\nNombre %c\n",leer.sensor);
		printf("Medicion %d\n",leer.valor);
		printf("Tiempo %lu\n",leer.tiempo);
		
		fclose(f_datos);
	}
     return(0);
	}
		


	

	
