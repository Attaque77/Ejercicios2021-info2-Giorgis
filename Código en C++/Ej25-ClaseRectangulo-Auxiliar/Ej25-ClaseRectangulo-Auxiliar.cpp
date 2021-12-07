#include <iostream>
#include  <locale.h>
#include "Rectangulo.h"

using namespace std;

int main(){
	
	setlocale (LC_CTYPE, "Spanish");
	
	rectangulo m,m1,m3;
	m.setear(0,3,-3,2);    //x,y,ancho en y,largo en x
	m1.setear(-1,1,-2,2);
	int i;
	
	cout<<"El �rea del primer rect�ngulo es: "<< m.area() <<endl;
	cout<<"El �rea del segundo rect�ngulo es: "<< m1.area() <<endl;
	cout<<"El per�metro del primer rect�ngulo es: "<< m.perimetro() <<endl;
	cout<<"El per�metro del segundo rect�ngulo es: "<< m1.perimetro() <<endl;
	
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
}
	
