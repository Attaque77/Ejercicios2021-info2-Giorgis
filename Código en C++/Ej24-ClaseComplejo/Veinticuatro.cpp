#include "Veinticuatro.h"
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

complejo complejo::suma(complejo i){
	
	complejo u;
	u.p = p + i.p;
	u.q = q + i.q;
	return u;
}

complejo complejo::resta(complejo i){
	
    complejo u;
	u.p = p - i.p;
	u.q = q - i.q;
	return u;
}

void complejo::imprimir(){
	cout<< "<" << p << "," << q << "i>" << endl;
}
