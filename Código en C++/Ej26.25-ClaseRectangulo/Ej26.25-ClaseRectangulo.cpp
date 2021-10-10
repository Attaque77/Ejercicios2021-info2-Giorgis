#include <iostream>
#include <cstdlib>
#include  <locale.h>     //Librer�a para colocar simbolos del c�digo ascii
#include "Veintiseis_25.h"

using namespace std;

int main(){
	
	setlocale (LC_CTYPE, "Spanish");  //funci�n para los acentos
	
	rectangulo m,m1,m3;
	m.setear(0,3,-3,2);    //x,y,ancho en y,largo en x
	m1.setear(-1,1,-2,2);
	int i;
	
	//Modificaciones para usar this
	//Uso memoria din�mica.No uso variables para pasarle una direcci�n a los punteros porque no las voy a usar despu�s.
	double *_area,*_perimetro;
	double *_area1,*_perimetro1;
	_area= (double*)malloc(sizeof(double));
	_perimetro= (double*)malloc(sizeof(double));
	_area1= (double*)malloc(sizeof(double));
	_perimetro1= (double*)malloc(sizeof(double));

	m.area(_area).perimetro(_perimetro);
	cout<<"El �rea del primer rect�ngulo es: "<< (*_area) <<endl;
	cout<<"El per�metro del primer rect�ngulo es: "<< (*_perimetro) <<endl;
	
	m1.area(_area1).perimetro(_perimetro1);
	cout<<"El �rea del primer rect�ngulo es: "<< (*_area1) <<endl;
	cout<<"El per�metro del segundo rect�ngulo es: "<< (*_perimetro1) <<endl;
	
	i=m.dentro(m1);

	if(i==1 || i==4){
		cout<<"El primero lo contiene al segundo"<<endl;
	}
	else if(i==2 || i==5){
		cout<<"El segundo contiene al primero"<<endl;
	}
	else if (i==3 || i==6){
		cout<<"Ninguno contiene a ninguno, no se tocan"<<endl;
	}
	
	cout<<"La �rea de intersecci�n es: "<< m.interseccion(m1,i) <<endl;
	return 0;
	
	//libero la memoria utilizada
	free(_area);
	free(_perimetro);
	free(_area1);
	free(_perimetro1);
}
