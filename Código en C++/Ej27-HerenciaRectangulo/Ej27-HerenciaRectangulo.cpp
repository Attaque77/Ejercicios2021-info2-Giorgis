#include <iostream>
#include  <locale.h>     //Librer�a para colocar simbolos del c�digo ascii
#include "Rectangulo.h"

using namespace std;

int main(){
	
	setlocale (LC_CTYPE, "Spanish");  //funci�n para los acentos
	
	int i;
	cuadrado m (0,3,3); 
	cuadrado m1 (1,1,5);;
	
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
	
	return 0;
}
	
