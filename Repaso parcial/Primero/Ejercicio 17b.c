#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

void Cargar_datos();
void Almacenar_datos();
void Lectura_datos();
void Mostrar_datos_codigo();

struct mercaderia{
	
	int codigo;
	float precio;
	char descripcion [SIZE];
	
}producto,*ptr_producto;        

void Cargar_datos(){
	
	int cant;
	printf("\nCANTIDAD DE PRODUCTOS: ");
	scanf("%d",&cant);
	
	for(int i=1; i<=cant; i++){
		
		ptr_producto=( struct mercaderia *) calloc (cant,sizeof(struct mercaderia) );   //Asignamos memoria dinámica
		ptr_producto=&producto;                                                         //Inicializamos el puntero a la direccion de memoria de la estructura
		
		printf("\nIngrese su producto: ");
		scanf("%s",ptr_producto->descripcion);
		printf("Ingrese el c%cdigo: ",162);
		scanf("%d",&ptr_producto->codigo);
		printf("Ingrese el precio: "); 
		scanf("%f",&ptr_producto->precio);
	
		Almacenar_datos();                                                               //Almacenamos los datos en el archivo
		free(ptr_producto);                                                              //Liberamos memoria
		ptr_producto=NULL;                                                               /*Apuntamos a NULL porque el puntero tiene todavía las direcciones 
		                                                                                   de memoria guardadas pero no las puede usar porque ya las liberó*/
	}  
	
	ptr_producto=( struct mercaderia *) calloc (cant,sizeof(struct mercaderia) );
	ptr_producto=&producto;
}
	
	void Almacenar_datos(){
		
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("SUPERMERCADO.dat","ab") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(&producto, sizeof (struct mercaderia), 1, archivo);                   
			fclose(archivo);
		}
	}
		
	void Lectura_datos(){
			
		ptr_producto=&producto;
		FILE *archivo;
			
		if( (archivo=fopen("SUPERMERCADO.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
			
		else{
				
			printf("\nlISTA DE DATOS INGRESADOR\n");
			fread(ptr_producto,sizeof(producto),1,archivo);
				
		while ( !feof(archivo)) {
			printf("\nProductos: %s\n", ptr_producto->descripcion);
			printf("Codigo: %i\n", ptr_producto->codigo);
			printf("Precio: %.2f\n",ptr_producto->precio);
			fread(ptr_producto,sizeof(producto),1,archivo);               //Si no se coloca entra en un bucle infinito,                                      
		}
		}
			fclose(archivo);
		}
			
		void Mostrar_datos_codigo(){
			
			int valor;	
			FILE *archivo;
			ptr_producto=&producto;
			
			printf("\nIngrese el codigo: ");
			scanf("%d",&valor);
				
			if( (archivo=fopen("SUPERMERCADO.dat","r") ) == NULL){
				printf("Error al abrir el archivo de lectura");
			}
				
			fread(ptr_producto,sizeof(producto),1,archivo);                      //Para que feof tenga referencia de donde leer
				
			while ( !feof(archivo)) {
					
				if(valor==(ptr_producto->codigo)){                                  
					printf("\nProductos: %s\n", ptr_producto->descripcion);
					printf("Codigo: %i\n",ptr_producto->codigo);
					printf("Precio: %.2f\n",ptr_producto->precio);
				}
					
				fread(ptr_producto,sizeof(producto),1,archivo);	                 //Para que no me tome 2 veces un valor del archivo
				}
				fclose(archivo);
			}
				
int main() {
					
	int dato;
	
	do{
		printf("COLOCAR EL NUMERO DE LA OPCION A SELECCIONAR");
		printf("\n\nCargar producto: 1");
		printf("\nMostarar listado de productos cargados: 2");
		printf("\nMostrar producto por codigo: 3 ");
		printf("\nSalir: 4");
		printf("\n\nNumero: ");
		scanf("%d",&dato);
		
		switch(dato){
			
		case 1:Cargar_datos();break;
		case 2:Lectura_datos();break;
		case 3:Mostrar_datos_codigo();break;
		}
		
		printf("\n");
		system("pause");      
		system ("cls");
		
	} while( (0<=dato) && (dato<=3) );
	
	free(ptr_producto);                                                              //Liberamos memoria
	ptr_producto=NULL;                                                               /*Apuntamos a NULL porque el puntero tiene todavía las direcciones 
	                                                                                   de memoria guardadas pero no las puede usar porque ya las liberó*/
	return 0;
}
