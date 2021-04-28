//Calcular promedio

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	
	int g; 
	int n;
	float promedio=0;
	
	printf("Cantidad de n%cmeros a promediar: ",163);
	scanf("%i",&g);
	
	float numeros[g];
	printf("\nIngrese los n%cmeros que se van a promediar\n",163);
	for(int i=0; i<g; i++){
		printf("%i: ",i+1);
		scanf("%f", &numeros[i]);
	}
	system ("cls");
	
	do{
		printf("Ingrese el n%cmero 9999 para continuar: ",163);
		scanf("%i",&n);
		
		if(n==9999){
			for(int i=0; i<g; i++){
				promedio= (promedio + numeros[i]);
			}
		}
		else{
				printf("\nNo ha ingresado correctamente el n%cmero solicitado\n\n",163);
				system("pause");
				system ("cls");
			}
		
	} while(n<9999 || n>9999);
	
	promedio= promedio/g;
	printf("Su promedio es: %.2f", promedio);
}
