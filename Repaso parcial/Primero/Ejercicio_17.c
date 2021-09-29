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
	printf("CANTIDAD DE PRODUCTOS: ");
	scanf("%d",&cant);
	
	printf("\n");
	for(int i=1; i<=cant; i++){
		
		printf("Ingrese su producto: ");
		scanf("%s",producto.descripcion);
		printf("Ingrese el c%cdigo: ",162);
		scanf("%d",&producto.codigo);
		printf("Ingrese el precio: "); 
		scanf("%f",&producto.precio);
		
		Almacenar_datos();
		system("pause");      
		system ("cls");
	}
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
			
			printf("lISTA DE DATOS INGRESADOR");
			fread(ptr_producto,sizeof(producto),1,archivo);
			
			while ( !feof(archivo)) {
				printf("\nProductos: %s\n", producto.descripcion);
				printf("Codigo: %i\n", producto.codigo);
				printf("Precio: %.2f\n",producto.precio);
				fread(ptr_producto,sizeof(producto),1,archivo);
			}
		}
		fclose(archivo);
	}
		
		void Mostrar_datos_codigo(){
			
			ptr_producto=&producto;
			int valor;
			FILE *archivo;
			
			printf("\nIngrese el codigo: ");
			scanf("%d",&valor);
			
			if( (archivo=fopen("SUPERMERCADO.dat","r") ) == NULL){
				printf("Error al abrir el archivo de lectura");
			}
			
			fread(ptr_producto,sizeof(producto),1,archivo);
			
			while ( !feof(archivo)) {
				
					if(valor==producto.codigo){
						printf("\nProductos: %s\n", producto.descripcion);
						printf("Codigo: %i\n",producto.codigo);
						printf("Precio: %.2f\n",producto.precio);
					}
					
					fread(ptr_producto,sizeof(producto),1,archivo);	
				}
			fclose(archivo);
			}
			
int main() {
	
	Cargar_datos();
	Lectura_datos();
	Mostrar_datos_codigo();
	
	return 0;
}

