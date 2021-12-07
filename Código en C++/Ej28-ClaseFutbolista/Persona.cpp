#include "Persona.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Persona:: Persona() {
	nombre = "Guillermo";
	apellido = "Giorgis";
}

Persona:: Persona( string _nombre, string _apellido){
	nombre=_nombre;
	apellido=_apellido;
}

string Persona::ObtenerNombre(){
	return nombre;
}

string Persona:: ObtenerApellido(){
	return apellido;
}

Futbolista::Futbolista(): Persona(){
	numero= 7;
}

Futbolista::Futbolista(string _nombre, string _apellido, unsigned int _numero) : Persona (_nombre,_apellido){
	numero=_numero;
}

void Futbolista::SetearAtributos(string _nombre, string _apellido, unsigned int _numero){
    apellido=_apellido;
	nombre=_nombre;
	numero=_numero;
}

unsigned int Futbolista:: ObtenerNumero(){
	return numero;
}

void Futbolista:: ImprimirAtributos(){
	cout<<"Su nombre es: "<< ObtenerNombre() << endl;
	cout<<"Su apellido es: "<< ObtenerApellido() << endl;
	cout<<"Su numero es: "<< ObtenerNumero() << endl;
}

