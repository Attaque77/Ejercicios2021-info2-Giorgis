#include "Rectangulo.h"
#include <iostream>
#include <cmath>

using namespace std;

rectangulo::rectangulo(){	
	cor_x=1;
	cor_y=1;
	ancho=1;
	largo=1;
}

void rectangulo::setear( double x, double y, double a, double l){
	cor_x=x;
	cor_y=y;
	ancho=a;
	largo=l;
}

rectangulo rectangulo::obtener(){
	rectangulo u;
	u.cor_x=cor_x;
	u.cor_y=cor_y;
	u.ancho=ancho;
	u.largo=largo;
	return u;
}

double rectangulo::area(){
	return abs(ancho*largo);
}
double rectangulo::perimetro(){
	
	if(ancho<0)
		return (ancho*2*(-1)+largo*2);
	else if(largo<0)
		return (ancho*2+largo*2*(-1));
	else{
		return (ancho*2+largo*2);
	}
}

int rectangulo::dentro(rectangulo rec){
	
	/*
	printf("\nEl valor de <cor_y> es: %.2f\n",cor_y);
	printf("El valor de <rec.cor_y> es: %.2f\n",rec.cor_y);
	printf("El valor de <cor_y-ancho> es: %.2f\n",cor_y-ancho);
	printf("El valor de <rec.cor_y> es: %.2f\n",rec.cor_y);
	
	printf("\nEl valor de <cor_y> es: %.2f\n",cor_y);
	printf("El valor de <rec.cor_y-rec.ancho> es: %.2f\n",rec.cor_y-rec.ancho);
	printf("El valor de <cor_y-ancho> es: %.2f\n",cor_y-ancho);
	printf("El valor de <rec.cor_y-rec.ancho> es: %.2f\n",rec.cor_y-rec.ancho);
	*/
	
	if( (rec.ancho<0 && ancho<0) || (rec.ancho>0 && ancho<0) ){
		
		/* Tomo el primero como referencia y pregunto si el punto de 'y' del segundo está dentro de los límites de 'y' del primero o si el 
		punto 'y' del segundo más su ancho (el otro punto de 'y' de ese rectángulo está dentro de los los líimites de los valores de 'y' del 
		primero.Entonces sé que el punto de 'y' del segundo puede estar en el primero. Falta que el punto de 'x' esté dentro también.*/
		
		if( (cor_y>=rec.cor_y && cor_y+ancho<rec.cor_y) || (cor_y>rec.cor_y+rec.ancho && cor_y+ancho<=rec.cor_y+rec.ancho) ){   
			
			//Evalúo también el punto de 'x' del segundo rectángulo del mismo modo que lo hice con 'y'.
			if( (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) || (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
				if(area()>rec.area()){                             //El de menor área está contenido en el otro, el primero lo contiene al segundo
					return 1;
				}
				else if(area()==rec.area()){                       //Si ambas áreas son iguales fijamos prioridad para la primera
					return 1;
				}
				else{                                              //El segundo contiene al primero.
					return 2;
				}
			}
			/*Puede que el punto de 'y' esté dentro de los límites de 'y' del primer rectángulo, pero no los de 'x', y entonces no puedo decir 
			que haya un solo punto dentro de otro, por lo que no se tocan*/
			else{
				return 3;
			}
		}
		//No se tocan al haber ya un punto, en este caso 'y', que no está contenido en el primer rectángulo.
		else{
			return 3;
		}
	}
	
	else if( (rec.ancho<0 && ancho>0) || (rec.ancho>0 && ancho>0) ){
		
		if( (cor_y<rec.cor_y && cor_y+ancho>=rec.cor_y) || (cor_y<=rec.cor_y+rec.ancho && cor_y+ancho>rec.cor_y+rec.ancho) ){
			if( (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) || (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
				if(area()>rec.area()){                             
					return 4;
				}
				else if(area()==rec.area()){                       
					return 4;
				}
				else{                                            
					return 5;
				}
			}
			else{
				return 6;
			}
		}
		else{
			return 6;
		}
	}
	return	-1;
}

double rectangulo::interseccion(rectangulo rec, int i){
	
	if(i==1 || i==2){
		
		double a,b,c;
		
		if( (cor_y>=rec.cor_y && cor_y+ancho<rec.cor_y) && (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x)  ){     //Primera imagen, está bien
			a= rec.cor_y-(cor_y+ancho);
			b= (cor_x+largo)-rec.cor_x;
			c=a*b;
			return c;
		}
		else if ( (cor_y>=rec.cor_y && cor_y+ancho<rec.cor_y) && (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){  //Segunda imagen,está bien
			a= rec.cor_y-(cor_y+ancho);
			b= (rec.cor_x+largo)-cor_x;
			c=a*b;
			return c;
		}
		else if( (cor_y>rec.cor_y+rec.ancho && cor_y+ancho<=rec.cor_y+rec.ancho) && (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) ){
			a= cor_y-(rec.cor_y+rec.ancho);
			b= (cor_x+largo)-rec.cor_x;
			c=a*b;
			return c;
		}
		else if( (cor_y>rec.cor_y+rec.ancho && cor_y+ancho<=rec.cor_y+rec.ancho) && (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
			a= cor_y-(rec.cor_y+rec.ancho);
			b= (rec.cor_x+rec.largo)-cor_x;
			c=a*b;
			return c;
		}
	}
	
	else if(i==4 || i==5){
		
		double a,b,c;
		
		if( (cor_y<rec.cor_y && cor_y+ancho>=rec.cor_y) &&  (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) ){
			a=rec.cor_y-cor_y;
			b=(cor_x+largo)-rec.cor_x;
			c=a*b;
			return c;
		}
		else if ( (cor_y<rec.cor_y && cor_y+ancho>=rec.cor_y) && (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
			a=rec.cor_y-cor_y;
			b=(rec.cor_x+rec.largo)-cor_x;
			c=a*b;
			return c;
		}
		else if ( (cor_y<=rec.cor_y+rec.ancho && cor_y+ancho>rec.cor_y+rec.ancho) && (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) ){
			a=(cor_y+ancho)-rec.cor_y;
			b=(cor_x+largo)-rec.cor_x;
			c=a*b;
			return c;
		}
		else if ( (cor_y<=rec.cor_y+rec.ancho && cor_y+ancho>rec.cor_y+rec.ancho) && (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
			a=(cor_y+ancho)-rec.cor_y;
			b=(rec.cor_x+rec.largo)-cor_x;
			c=a*b;
			return c;
		}
	}
	else{
		return 0;
	}
	
	return -1;
}


