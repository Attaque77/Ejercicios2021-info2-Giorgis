#ifndef RECTANGULO_H
#define RECTANGULO_H

class rectangulo{
	
public:
	rectangulo();
	rectangulo (double , double , double , double );
	void setear (double, double, double, double);
	rectangulo obtener();
	double area();
	double perimetro();
	int dentro(rectangulo);
protected:
	double cor_x,cor_y,ancho,largo;	
};

class cuadrado : public rectangulo{
    public:
	cuadrado( double x,  double y, double lado): rectangulo (x,y,lado,lado){}
};

#endif

