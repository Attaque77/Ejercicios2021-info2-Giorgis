#include <iostream>
#include <cstdlib>
#include "Persona.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	//Una manera de inicializar un objeto
	//Futbolista Jugador;
	//Jugador = Futbolista ( "Sebastian", "Battaglia" , 5); 
	
	//Otra forma de inicializar un objeto
	Futbolista Jugador ( "Martin", "Palermo", 9); 
	
	Jugador.ImprimirAtributos();
	Jugador.SetearAtributos( "Roberto", "Abbondanzieri", 1);
	
	cout<<"\nSu nombre es: "<< Jugador.ObtenerNombre() << endl;
	cout<<"Su apellido es: "<<Jugador.ObtenerApellido()<< endl;
	cout<<"Su numero es: "<<Jugador.ObtenerNumero()<<endl;
	
	return 0;
}

