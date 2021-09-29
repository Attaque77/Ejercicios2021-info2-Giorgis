#ifndef VEINTICUATRO_H
#define VEINTICUATRO_H
class complejo{
 public:
	 complejo();
	 complejo(double _p, double _q);
	 complejo suma(complejo i);
	 complejo resta(complejo i);
	 void imprimir();
 private:
	 double p,q;
};
#endif
