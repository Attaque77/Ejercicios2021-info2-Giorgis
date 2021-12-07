#ifndef Persona_H
#define Persona_H

#include <cstdlib>
#include <iostream>
using namespace std;

class Persona {
public:
	Persona();
	Persona (string _nombre, string _apellido);
	string ObtenerNombre();
	string ObtenerApellido();
protected:
	string nombre, apellido;
};

class Futbolista : public Persona {
public:
	Futbolista ();
	Futbolista ( string _nombre, string _apellido, unsigned int _numero);
	void SetearAtributos(string _nombre, string _apellido, unsigned int _numero);
	unsigned int ObtenerNumero();
	void ImprimirAtributos();
private:
	unsigned int numero;
};

#endif

