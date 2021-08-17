#include <stdio.h>
#include <stdlib.h>

void Cargar_datos();
void Almacenar_datos();
void Lectura_datos();
void Aritmetica_mediciones();

struct mediciones{
	float humedad;
	float velocidad;
	float temperatura;
}*medicion,*ptr_medicion;

void Cargar_datos(int *cant){
	
	printf("CANTIDAD DE MEDICIONES: ");
	scanf("%d",cant);
	
	ptr_medicion=(struct mediciones *) calloc( (*cant),sizeof(struct mediciones));
	
	for(int i=0;i<(*cant); i++){
		
		printf("\nDATOS DEL SENSOR\n");
		printf("Humedaad: ");
		scanf("%f",&ptr_medicion[i].humedad);
		printf("Velocidad del viento: ");
		scanf("%f",&ptr_medicion[i].velocidad);
		printf("Temperatura: ");
		scanf("%f",&ptr_medicion[i].temperatura);
	}
	Almacenar_datos(cant);
	free(ptr_medicion);
	ptr_medicion=NULL;
}
	
	void Almacenar_datos(int *cant){      
		
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("MEDICIONES.dat","wb") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(ptr_medicion, sizeof (struct mediciones),(*cant), archivo);                   
			fclose(archivo);
		}
	}
		
	void Lectura_datos(int *cant){                                                      //Le paso la cantidad de productos - argumento-
			
			medicion=( struct mediciones*) calloc ((*cant),sizeof(struct mediciones) );     //Volvemos a pedir memoria
			FILE *archivo;
			
			if( (archivo=fopen("MEDICIONES.dat","rb") ) == NULL){
				printf("Error al abrir el archivo de lectura");
			}
			
			else{
				
				printf("\nLISTA DE MEDICIONES\n");
				fread(medicion,sizeof(struct mediciones),(*cant),archivo);            //Leemos el archivo binario
				fclose(archivo);
				
				for(int i=0,j=1; i<(*cant); i++,j++){
					printf("\n%d: Medicion",j);
					printf("\nHumedad: %.2f g\\m3 \n", medicion[i].humedad);
					printf("Velocidad del viento: %.2f km\\h \n", medicion[i].velocidad);
					printf("Temperatura: %.2f °C\n",medicion[i].temperatura);
				}
			}
			
		}
			
		void Aritmetica_mediciones(int *cant){
	
		float suma_hum,divisor=*cant;
		float A,B=0;
				
		for(int i=0; i<(*cant); i++){
			suma_hum+=medicion[i].humedad;
			A=medicion[i].temperatura;
					
		    if(A>B){
			B=A;
			}
		}
			printf("\nPromedio de mediociones de humedad: %.2f",(suma_hum/divisor));
			printf("\nLa mayor temperatura es: %.2f °C", B);
			free(medicion);
			medicion=NULL;	
		}
				
int main(int argc, char *argv[]) {
			int cant_medidas;
			Cargar_datos(&cant_medidas);
			Lectura_datos(&cant_medidas);
			Aritmetica_mediciones(&cant_medidas);
			return 0;
		}
				
