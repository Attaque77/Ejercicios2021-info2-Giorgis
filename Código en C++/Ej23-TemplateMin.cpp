#include <iostream>
using namespace std;

template < class tipo>

    tipo minimo (tipo A, tipo B){
	
	if (A<B){
	    return A;
	}
 	else if (B<A){
	    return B;
	}
	
	return 0;
    }
		
    int main(int argc, char *argv[]) {
			
		cout<<"Valor int: "<< minimo ( int(1), int(2)) <<endl;
		cout<<"Valor float: "<< minimo ( float(2.5), float(3.0)) <<endl;
		cout<<"Valor char: "<< minimo ( char(4), char(5)) <<endl;
		
		return 0;
		}
		
