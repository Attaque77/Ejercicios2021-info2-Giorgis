void setup()
{
// para display de 8x8 CASERO
  DDRD = DDRD | B11111100; // puerto D2-D7 como salida. 2-5 (COLUMNAS) 6-7 (FILAS)
  DDRB = DDRB | B00111111; // puerto B0-B5 como salida. 8-13 (FILAS)
  DDRC = DDRC | B00011110; // puerto B1-B4 como salida. A1-A4 (COLUMNAS)
}
            
byte fila, columna;

void loop()
{
  int i=1;
  //primeras 6 filas
  for(fila=B00100000;fila>=B00000001;fila=fila>>1){                    // Filas de arriba, empieza en el pin 13 hasta el pin 8. En puertos: B5-B0.
  PORTB=~fila;                                                         /*Niega el valor de fila, para obtener un 0 (cátodo) en la posición del led y pone un 1 en las demás posiciones 
                                                                       para que no se prendan porque tiene un 1 en ambas patas del LED.*/
                                                         
    for(columna=B00100000;columna>=B00000100;columna=columna>>1){      //Pone un 1 en la primera columna en el pin 5 hasta el 2. En puertos D5-D2;
    PORTD= columna | B11000000;                                        /*Operción OR, los piner 7 y 6 se les pone un UNO para que no se prendan cuando se prende la primera columna cuando
                                                                       se usa el puerto D que lo comparte con las columnas.*/
    delay(200);
    PORTD=B11000000;                                                   //Apago la columna y dejo como está las filas del puerto D, para que no se me prendan cuando cambio de columna.
    }

      for(columna=B00010000;columna>=B00000010;columna=columna>>1){    /*Uso las etradas analógicas para la otra mitad de la matriz que corresponden al puerto C. Voy del pin A4 aL A1. 
                                                                         En puerto; D4-D1*/
      PORTC=columna;                                                    //Mando los valores lógicos al puerto C. 
        delay(200);
      PORTC=B00000000;                                                  //Apago el puerto C.
      } 
  }
  
  if(i==1){
    
    PORTB=B00111111;                                                   //Coloco un 1 en el puerto B para que no se prendan los LEDS cunado prendo la primera columna

    //´anteúltimo led
    for(columna=B00100000;columna>=B00000100;columna=columna>>1){      //Prendo la primer columna.
    PORTD= columna | B01000000;                                        /*Prendo la primera columna, pongo un 0 (cátodo) en la anteúltima fila para prenderla, y en la última un 1 para 
                                                                         que no se prenda*/
    delay(200);
    PORTD=B01000000;                                                   /*Apago las columnas del puero D y la fila anteúltima, y dejo prendido la fila última para que no se prenda 
                                                                         uando cambie de columna*/
                                                                       
    }
      
      for(columna=B00010000;columna>=B00000010;columna=columna>>1){    //Realizo la misma operación que cuando trabajé con los pines analógos más arriba del código
      PORTC=columna;
        delay(200);
      PORTC=B00000000;
      } 
    }
  
  i++;
  
  if(i==2){

    //última fila 
    for(columna=B00100000;columna>=B00000100;columna=columna>>1){     //Prendo la primera columna para hacer la última fila
    PORTD= columna | B10000000;                                       //Operación OR entre el estado de la columna y la fila que va a prender, un 1 para que no se prenda la anteúltima fila.
    delay(200);
    PORTD=B10000000;                                                  //Apago las columnas del puero D y la fila última, y dejo prendido la fila anteúltima para que no se prenda uando cambie de columna
    }
      
      for(columna=B00010000;columna>=B00000010;columna=columna>>1){   //Realizo la misma operación que cuando trabajé con los pines analógos más arriba del código
      PORTC=columna;
        delay(200);
      PORTC=B00000000;                            
      } 
    }
  
  }
  



