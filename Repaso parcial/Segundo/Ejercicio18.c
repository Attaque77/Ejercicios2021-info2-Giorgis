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
}*personas,*ptr_personas;

    void Cargar_datos(){
	
	printf("INGRESAR DATOS DE PERSONAS\n");
	
	for(int i=0;i<5;i++){
		
		ptr_personas=( struct Datos *) calloc (1,sizeof(struct Datos) );                 //Asignamos memoria dinámica

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
}
	
	void Almacenar_datos(){      
		
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("DATOS_PERSONALES.dat","ab") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(ptr_personas, sizeof (struct Datos), 1, archivo);                   
			fclose(archivo);
		}
	}
	
	void Lectura_datos(){                                                         /*Gaurdamos los datos en la estructura para utilizar un arreglo de 
																				estructuras */   
		FILE *archivo;
		personas=( struct Datos *) calloc (5,sizeof(struct Datos) );
		
		if( (archivo=fopen("DATOS_PERSONALES.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
			
		else{
		fread(personas,sizeof(struct Datos),5,archivo);		
	
		fclose(archivo);
	}
	}
	
	void Eleccion_persona(int *elegir_1){                                       
		
		FILE *archivo;
		personas= (struct Datos *) calloc (5,sizeof(struct Datos) );;
			
		if( (archivo=fopen("DATOS_PERSONALES.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
		
		else{
			fread(personas,sizeof(struct Datos),5,archivo);		         //Leemos todo el archivo para poder trabajar luego con el arreglo de estructuras
			fclose(archivo);
			
		printf("\nNombre: %s",personas[*elegir_1].nombre);             //Con el valor seleccionado de la persona vamos mostrando sus datos
		printf("\nTelefono: %d",personas[*elegir_1].telefono);            
		printf("\nEdad: %d",personas[*elegir_1].edad);	
		printf("\nDni: %d",personas[*elegir_1].dni);
	}
		free(personas);
		personas=NULL;
	}	

	int Mayor_de_edad(struct Datos *mayor,int *elegir_2){              //Recibo un puntero a un tipo de dato estructura y el numero de la persona elegida
		
		FILE *archivo;
		
		if( (archivo=fopen("DATOS_PERSONALES.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
		
		else{
			fread(mayor,sizeof(struct Datos),5,archivo);		      //Leemos todo el archivo 
			fclose(archivo);
		}
		
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
		printf("%d: %s\n",i+1,personas[i].nombre);
	}
	printf("\nNumero: ");
	scanf("%d",&elegir);
	elegir-=1;
	
	free(personas);                                                          //Liberamos memoria caundo pedimos en la lectura
	personas=NULL;            
	
	Eleccion_persona(&elegir);
	
	personas= (struct Datos *) calloc (5,sizeof(struct Datos) );             
		
	condicion=Mayor_de_edad(personas,&elegir);
	if(condicion==1){
		printf("\n\nMAYOR DE EDAD");
	}
	else{
		printf("\n\nMENOR DE EDAD");
	}
	
	Vaciar_archivo();                                                       /*Abro y cierro el archivo en modo escritura para no tener datos a iniciar
																	        el programa*/

	
	return 0;
}

