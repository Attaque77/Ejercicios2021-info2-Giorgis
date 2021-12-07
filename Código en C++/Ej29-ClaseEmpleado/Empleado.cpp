#include "Empleado.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Empleado::Empleado() {
	nombre= "Ingrese su nombre";
	edad = 0;
	salario = 0;
}

Empleado:: Empleado(string _nombre, unsigned int _edad, double _salario){
	nombre=_nombre;
	edad=_edad;
	salario=_salario;
}

void Empleado:: SetearNombre(string _nombre){
	nombre=_nombre;
}

void Empleado:: SetearEdad (unsigned int _edad){
	edad=_edad;
}

void Empleado:: SetearSalario(double _salario){
	salario=_salario;
}

string Empleado:: ObtenerNombre(){
	return nombre;
}

unsigned int Empleado::ObtenerEdad(){
	return edad;
}

double Empleado:: ObtenerSalario(){
	return (salario+plus);
}

void Empleado::Plus(unsigned int _plus){
	plus=_plus;
}


Comercial::Comercial() : Empleado(){
	comision=0;	
}

Comercial:: Comercial(string _nombre, unsigned int _edad, double _salario, double _comision) : Empleado (_nombre,_edad,_salario){
	SetearComision(_comision);
	if (ObtenerEdad()>30 && ObtenerComision()>25000){
		Plus(5000);
	}
	else{
		Plus(0);
	}
}

void Comercial:: SetearComision(double _comision){
	comision=_comision;
}

double Comercial:: ObtenerComision(){
	return comision;
}


Repartidor::Repartidor(): Empleado(){
	zona=0;
}

Repartidor::Repartidor(string _nombre, unsigned int _edad, double _salario, int _zona) : Empleado(_nombre, _edad,_salario){
	SetearZona(_zona);
	if (ObtenerEdad()<25 && ObtenerZona()==3){
		Plus(5000);
	}
	else{
		Plus(0);
	}
}

void Repartidor:: SetearZona(int _zona){
	zona=_zona;
}

int Repartidor:: ObtenerZona(){
	return zona;
}


