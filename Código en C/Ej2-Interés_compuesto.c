//Cálculo de interés compuesto
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main ()
{
	double tasa;  //interes
	double monto;  // monto acumulado por interes en los años
	double principal=1000;  //monto principal
	int anio;  //contador de años
    
	for(tasa=.05; tasa<=.1; tasa=tasa+.01 ){    // la variable 'tasa' es del 5% y va hasta 10%     
		
		if (tasa == .07){
			tasa=tasa+.01;
		}
		
			printf("%4s %21s %8s\n", "Anio", "Cantidad en deposito","interes");
			for (anio=1;anio <= 10;anio++)
			{
				monto = principal * pow(1.0+tasa,anio);
				printf("%2d %21.2f %8.2f\n", anio, monto, tasa);
			}
			system("pause");
			system ("cls");
	}
			
	return 0;
}


