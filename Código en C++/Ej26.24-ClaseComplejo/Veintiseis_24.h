#ifndef VEINTISEIS_24_H
#define VEINTISEIS_24_H

class complejo{
	
public:
	complejo();
	complejo(double _p, double _q);
	complejo &suma(complejo i);
	complejo &resta(complejo i);
	void imprimir()const;
	void imprimir(complejo *u,int i) const;
private:
	double p,q;
};

#endif


