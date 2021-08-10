
#include <iostream>
using namespace std;

	void minimo (int A=3, int B=5){
	if (A<B)
		cout<<"El valor mas chico es:"<< A << endl;
	else if (B<A)
		cout<<"El valor mas chico es:"<< B << endl;
}
	void minimo (float A=3.0, float B=5.0){
		if (A<B)
			cout<<"El valor mas chico es:"<< A << endl;
		else if (B<A)
			cout<<"El valor mas chico es:"<< B << endl;
	}
		
int main(int argc, char *argv[]) {
	
	float a=4.5;
	float b=1.6;
	minimo(a,b);
	minimo(1,2);
	return 0;
}

