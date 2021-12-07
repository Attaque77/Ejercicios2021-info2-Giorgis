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

rectangulo:: rectangulo ( double x, double y, double a, double l){
	this->setear(x,y,a,l);
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
	
	if( (rec.ancho<0 && ancho<0) || (rec.ancho>0 && ancho<0) ){
		
		/* Tomo el primero como referencia y pregunto si el punto de 'y' del segundo est� dentro de los l�mites de 'y' del primero o si el 
		punto 'y' del segundo m�s su ancho (el otro punto de 'y' de ese rect�ngulo est� dentro de los los l�imites de los valores de 'y' del 
		primero.Entonces s� que el punto de 'y' del segundo puede estar en el primero. Falta que el punto de 'x' est� dentro tambi�n.*/
		
		if( (cor_y>=rec.cor_y && cor_y+ancho<rec.cor_y) || (cor_y>rec.cor_y+rec.ancho && cor_y+ancho<=rec.cor_y+rec.ancho) ){   
			
			//Eval�o tambi�n el punto de 'x' del segundo rect�ngulo del mismo modo que lo hice con 'y'.
			if( (cor_x<=rec.cor_x && cor_x+largo>rec.cor_x) || (cor_x<rec.cor_x+rec.largo && cor_x+largo>=rec.cor_x+rec.largo) ){
				if(area()>rec.area()){                             //El de menor �rea est� contenido en el otro, el primero lo contiene al segundo
					return 1;
				}
				else if(area()==rec.area()){                       //Si ambas �reas son iguales fijamos prioridad para la primera
					return 1;
				}
				else{                                              //El segundo contiene al primero.
					return 2;
				}
			}
			/*Puede que el punto de 'y' est� dentro de los l�mites de 'y' del primer rect�ngulo, pero no los de 'x', y entonces no puedo decir 
			que haya un solo punto dentro de otro, por lo que no se tocan*/
			else{
				return 3;
			}
		}
		//No se tocan al haber ya un punto, en este caso 'y', que no est� contenido en el primer rect�ngulo.
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

