#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

void Cargar_datos();
void Almacenar_datos();
void Lectura_datos();
void Eleccion_persona();
int Mayor_de_edad();
void Vaciar_archivo();

struct Datos{
	char nombre [SIZE];
	int telefono;
	int edad;
	int dni;
}personas,*ptr_personas;

void Cargar_datos(){
	
	ptr_personas=&personas;
	printf("INGRESAR DATOS DE PERSONAS\n");
	
	memset(ptr_personas,0,sizeof(struct Datos));
	for(int i=0;i<5;i++){
		
		ptr_personas=( struct Datos *) calloc (5,sizeof(struct Datos) );   //Asignamos memoria dinámica
		ptr_personas=&personas;  
		
		printf("\nNombre: ");
		scanf("%s",ptr_personas->nombre);
		printf("Tel%cfono: ",130);
		scanf("%d",&ptr_personas->telefono);
		printf("Edad: ");
		scanf("%d",&ptr_personas->edad);
		printf("Dni: ");
		scanf("%d",&ptr_personas->dni);
		
		Almacenar_datos();                                                               //Almacenamos los datos en el archivo
		free(ptr_personas);                                                              //Liberamos memoria
		ptr_personas=NULL;                                                               /*Apuntamos a NULL porque el puntero tiene todavía las direcciones 
		                                                                                   de memoria guardadas pero no las puede usar porque ya las liberó*/
	}
	ptr_personas=( struct Datos *) calloc (5,sizeof(struct Datos) );  
	ptr_personas=&personas;  
}
	 
	void Almacenar_datos(){                                                             
		
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("DATOS_PERSONALES.dat","ab") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(&personas, sizeof (struct Datos), 1, archivo);                   
			fclose(archivo);
		}
	}
	
	void Lectura_datos(){                                                         /*Gaurdamos los datos en la estructura para utilizar un arreglo de 
		                                                                           estructuras*/     
		ptr_personas=&personas;
		FILE *archivo;

		if( (archivo=fopen("DATOS_PERSONALES.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
			
		else{
		fread(ptr_personas,sizeof(personas),5,archivo);		
		fclose(archivo);
	}
	}
	
	void Eleccion_persona(int *elegir_1){                                       
		
		FILE *archivo;
		ptr_personas=&personas;
			
		if( (archivo=fopen("DATOS_PERSONALES.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
		
		else{
			fread(ptr_personas,sizeof(personas),5,archivo);		                //Leemos todo el archivo para poder trabajar luego con el arreglo de estructuras
			fclose(archivo);
			
		printf("\nNombre: %s",ptr_personas[*elegir_1].nombre);                  //Con el valor seleccionado de la persona vamos mostrando sus datos
		printf("\nTelefono: %d",ptr_personas[*elegir_1].telefono);            
		printf("\nEdad: %d",ptr_personas[*elegir_1].edad);	
		printf("\nDni: %d",ptr_personas[*elegir_1].dni);
	}
	}	

	int Mayor_de_edad(struct Datos *mayor,int *elegir_2){                       //Recibo la un puntero a un tipo de dato estructura y el numero de la persona elegida
		if(mayor[*elegir_2].edad> 18){
			return 1;
		}
		else{
			return 0;
		}
	}
		
	void Vaciar_archivo(){
			
			FILE *archivo;                                                                    
			
			if( (archivo=fopen("DATOS_PERSONALES.dat","wb") ) == NULL){
				printf("\nError al abrir el archivo para escritura");
			}
			else{
				fclose(archivo);
			}
		}
			
int main() {
	
	int elegir,condicion;
	Cargar_datos();
	Lectura_datos();
	
	printf("\n\nELIJA UN NUMERO PARA OBTENER SUS DATOS\n\n");
	for(int i=0; i<5; i++){
		printf("%d: %s\n",i+1,ptr_personas[i].nombre);
	}
	printf("\nNumero: ");
	scanf("%d",&elegir);
	elegir-=1;
	
	Eleccion_persona(&elegir);
	
	condicion=Mayor_de_edad(ptr_personas,&elegir);
	if(condicion==1){
		printf("\nMAYOR DE EDAD");
	}
	else{
		printf("\nMENOR DE EDAD");
	}
	
	Vaciar_archivo();                                                                /*Abro y cierro el archivo en modo escritura para no tener datos al iniciar
 	                                                                                   el programa*/
	
	free(ptr_personas);                                                              //Liberamos memoria
	ptr_personas=NULL;                                                               /*Apuntamos a NULL porque el puntero tiene todavía las direcciones 
																					   de memoria guardadas pero no las puede usar porque ya las liberó*/
	
	return 0;
}

