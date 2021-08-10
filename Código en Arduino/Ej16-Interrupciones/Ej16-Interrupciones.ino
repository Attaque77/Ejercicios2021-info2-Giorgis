#define C_LED 3 //cantidad de leds
#define C_PULSADORES 2 //cantidad de pulsadores

unsigned short led[C_LED] = {3,4,5};    // entradas de los leds
unsigned short pulsador[C_PULSADORES] = {2,3};  // el 2 es el derecho y 3 el izquierdo
short estado = 0; //me sirve para cambiar el estado de los leds

volatile int posicion = 0;
void Interrupcion_Derecho();
void Interrupcion_Izquierdo();

void setup() {
//configurar los pines de salida
 for(int i=0; i<C_LED; i++){
  pinMode(led[i],OUTPUT); 
 }
 
//configurar los pines de entrada
 for(int i=0; i<C_PULSADORES; i++){
  pinMode(pulsador[i],INPUT);
 }

 //Habilito las interrupciones
 attachInterrupt(0,Interrupcion_Derecho,FALLING);
 attachInterrupt(1,Interrupcion_Izquierdo,FALLING);
}

void loop() {
  
if(posicion == IZQUIERDO){
  digitalWrite(led[estado],LOW);                   //Apaga el led que se encontraba prendido anterior al que se va a prender después - de izquierda a derecha-
  estado++; 
  if(estado >= (C_LED-1); estado++){        
    estado=0;                                      //Vuelve a empezar la secuencia si llega al último led de la derecha
  }
  digitalWrite(led[estado],HIGH);                  //Va prendiendo los leds, uno a uno
}

else{
  digitalWrite(led[estado],LOW);                   //Apaga el led que se encontraba prendido anterior al que se va a prender después - de derecha a izquierda-
    estado--;
    if(estado < 0){
      estado= (C_LED-1);                           //Empieza la secuencia del ultimo led cuando ha llegado al primero
    }
    digitalWrite(led[estado],HIGH);       
  }
}

void Interrupcion_Derecho(){
  
  //Antirrebote pulsador derecho    
  if(millis()>(Tii+50){                            /* Si el tiempo que paso es mayor al ultimo tiempo+ lo que tarda el rebote significa que fue presionado el boton intensionalmente
                                                      sino es un rebote del pulsador*/
  posicion=DERECHO;                                //Cambia el valor de posición en la interrupción
  tii=millis();                                    //Toma el valor de la última medición
  } 
}

void Interrupcion_Izquierdo(){
     
  //Antirrebote pulsador izquierdo
  if(millis()<(Ti+50)){                            /* Si el tiempo que paso es mayor al ultimo tiempo+ lo que tarda el rebote significa que fue presionado el boton intensionalmente
                                                      sino es un rebote del pulsador*/
  posicion=IZQUIERDO;                              //Cambia el valor de posición en la interrupción
  Ti=millis();                                     //Toma el valor de la última medición
  }
}
