#ifndef RECTANGULO_H
#define RECTANGULO_H

class rectangulo{
	
	public:
	 rectangulo();
	 void setear(double, double, double, double);
	 rectangulo obtener();
	 double area();
	 double perimetro();
	 int dentro(rectangulo);
	 double interseccion(rectangulo,int);
	 
	private:
	 double cor_x,cor_y,ancho,largo;
	 
};

#endif

