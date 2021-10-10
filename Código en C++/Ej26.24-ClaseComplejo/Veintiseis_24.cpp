#include "Veintiseis_24.h"
#include <iostream>
using namespace std;

complejo::complejo(){
	p=0;
	q=0;
}

complejo::complejo(double _p, double _q){
	p=_p;
	q=_q;
}

complejo &complejo::suma(complejo i){
	complejo k;
	complejo *u=&k;
	(*u).p = p + i.p;
	(*u).q = q + i.q;
	imprimir(u,0);
	return *this;
}

complejo &complejo::resta(complejo i){
	complejo k;
	complejo *u=&k;
	(*u).p = p - i.p;
	(*u).q = q - i.q;
	imprimir(u,1);
	return *this;
}

// sobrecarga de operadores
void complejo::imprimir() const{
	cout<< "<" << p << "," << q << "i>" << endl;
}

void complejo::imprimir(complejo *u,int i) const{
	if(i==0){
		cout<<"\nSUMA: <" << (*u).p << "," << (*u).q << "i>" << endl;
	}
	else if(i==1){
		cout<<"RESTA: <" << (*u).p << "," << (*u).q << "i>" << endl;
	}
}



