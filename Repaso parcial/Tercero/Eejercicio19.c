#include <stdio.h>
#include <stdlib.h>

struct mediciones{
	int humedad;
	int velocidad;
	int temperatura;
}medicion,*ptr_medicion;

int main(int argc, char *argv[]) {
	
	int cant, i=0;	
	printf("Ingrese la cantidad de mediciones: ");
	scanf("%d",&cant);

	for(i;i<cant; i++){
		
		ptr_medicion=(struct mediciones *)calloc(cant,sizeof(struct mediciones));
		
		
		printf("Ingrese la humedaad: ");
		scanf("%d", &ptr_medicion[i].humedad);
		printf("Ingrese la velocidad del viento: ");
		scanf("%d",&ptr_medicion[i].velocidad);
		printf("Ingrese la temperatura: ");
		sacanf("%d",&ptr_medicion[i].temperatura);
		
		Almacenar_datos();
		free(ptr_medicion);
		ptr_medicion=NULL;
	}
	
	
	
	return 0;
}

