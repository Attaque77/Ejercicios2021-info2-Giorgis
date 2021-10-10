#ifndef VEINTISEIS_25_H
#define VEINTISEIS_25_H

class rectangulo{
	
public:
	rectangulo();
	void setear(double, double, double, double);
	rectangulo obtener()const;
	
	//PARA USAR EL THIS EN CASCADA
	rectangulo &area(double *_area);
	rectangulo &perimetro(double *_perimetro);
	
	//PARA USARLA EN LA LIBRERÍA PARA CÁLCULOS
	double area();
	double perimetro();

	int dentro(rectangulo);
	double interseccion(rectangulo,int);
	
private:
	double cor_x,cor_y,ancho,largo;
	
};

#endif

