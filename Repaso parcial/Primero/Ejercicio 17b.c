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
	
}*producto,*ptr_producto;        //*ptr_producto lo utilizo para escritura   *producto lo uso para lectura

void Cargar_datos(int *cant){
	
	printf("\nCANTIDAD DE PRODUCTOS: ");
	scanf("%d",cant);
	
	for(int i=1; i<=(*cant); i++){
		
		ptr_producto=( struct mercaderia*) calloc ((*cant),sizeof(struct mercaderia) );   /*(struct mercaderia*) es el casteo, para indicar el tipo de dato 
		                                                                                   del puntero devuelto, y para que el puntero sepa la longitud
		                                                                                   del tipo de dato en la memoria*/                                                                                       
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
}
	
	void Almacenar_datos(){
		
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("SUPERMERCADO.dat","ab") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(ptr_producto, sizeof (struct mercaderia), 1, archivo);                   
			fclose(archivo);
		}
	}
		
	void Lectura_datos(int *cant){                                                      //Le paso la cantidad de productos - argumento-
			
		producto=( struct mercaderia*) calloc ((*cant),sizeof(struct mercaderia) );     //Volvemos a pedir memoria
		FILE *archivo;
			
		if( (archivo=fopen("SUPERMERCADO.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
			
		else{
				
			printf("\nlISTA DE DATOS INGRESADOR\n");
			fread(producto,sizeof(struct mercaderia),1,archivo);                       //Leemos el archivo binario
				
		while ( !feof(archivo)) {                                                      //feof= fin de archivo- hasta que no lo encuentre no termina-
			printf("\nProductos: %s\n", producto->descripcion);
			printf("Codigo: %i\n", producto->codigo);
			printf("Precio: %.2f\n",producto->precio);
			fread(producto,sizeof(struct mercaderia),1,archivo);                       //seguimos leyendo hasta que encuentre el fin de archivo              
		}
		}
			fclose(archivo);
		    free(producto);
			producto=NULL;
		}
			
		void Mostrar_datos_codigo(int *cant){
			
			int valor;	
			FILE *archivo;
			producto=( struct mercaderia*) calloc ((*cant),sizeof(struct mercaderia) );
			
			printf("\nIngrese el codigo: ");
			scanf("%d",&valor);
				
			if( (archivo=fopen("SUPERMERCADO.dat","r") ) == NULL){
				printf("Error al abrir el archivo de lectura");
			}
				
			fread(producto,sizeof(struct mercaderia),1,archivo);                      //Para que feof tenga referencia de donde leer
				
			while ( !feof(archivo)) {
					
				if(valor==(producto->codigo)){                                  
					printf("\nProductos: %s\n",producto->descripcion);
					printf("Codigo: %i\n",producto->codigo);
					printf("Precio: %.2f\n",producto->precio);
				}
					
				fread(producto,sizeof(struct mercaderia),1,archivo);	                 //Para que no me tome 2 veces un valor del archivo
				}
				fclose(archivo);
			    free(producto);
			    producto=NULL;
			}
				
int main() {
					
	int dato,cant_1;
	
	do{
		printf("COLOCAR EL NUMERO DE LA OPCION A SELECCIONAR");
		printf("\n\nCargar producto: 1");
		printf("\nMostarar listado de productos cargados: 2");
		printf("\nMostrar producto por codigo: 3 ");
		printf("\nSalir: 4");
		printf("\n\nNumero: ");
		scanf("%d",&dato);
		
		switch(dato){
			
		case 1:Cargar_datos(&cant_1);break;
		case 2:Lectura_datos(&cant_1);break;
		case 3:Mostrar_datos_codigo(&cant_1);break;
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
