#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char nombre[20];
	char domicilio[20];
	char ciudad[20];
	char estado[10];
	
	int codigo_postal;
	
	cout<<"Ingrese su nombre: "<<  endl;
	cin>>nombre;
	
	cout<<"Ingrese su domicilio: "<< endl;
	cin>>domicilio;
	
	cout<<"Ingrese su ciudad: "<< endl;
	cin>>ciudad;
	
	cout<<"Ingrese su estado civil: "<< endl;
	cin>>estado;
	
	cout<<"Ingrese su codigo postal: "<< endl;
	cin>>codigo_postal;
	
	return 0;
}

