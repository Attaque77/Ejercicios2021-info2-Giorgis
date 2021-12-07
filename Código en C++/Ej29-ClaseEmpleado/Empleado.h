#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <cstdlib>
#include <iostream>
using namespace std;

class Empleado {
public:
	Empleado();
	Empleado(string _nombre, unsigned int _edad, double _salario);
	void SetearNombre(string _nombre);
	void SetearEdad(unsigned int _edad);
	void SetearSalario(double _salario);
	string ObtenerNombre();
	unsigned int ObtenerEdad();
	double ObtenerSalario();
	void Plus(unsigned int);
private:
	string nombre;
	unsigned int edad;
	double salario;
	int plus;
};

class Comercial : public Empleado{
public:
	Comercial();
	Comercial(string _nombre, unsigned int _edad, double _salario, double _comision);
	void SetearComision(double _comision);
	double ObtenerComision();
private:
	double comision;
};

class Repartidor: public Empleado{
public:
	Repartidor();
	Repartidor(string _nombre, unsigned int _edad, double _salario, int _zona);
	void SetearZona(int _zona);
	int ObtenerZona();
private:
	int zona;
};
#endif

