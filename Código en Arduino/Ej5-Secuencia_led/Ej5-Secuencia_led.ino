#define C_LED 3 //cantidad de leds
#define C_PULSADORES 2 //cantidad de pulsadores

unsigned short led[C_LED] = {3,4,5};    // entradas de los leds
unsigned short pulsador[C_PULSADORES] = {6,7};  // el 6 es el derecho y 7 el izquierdo
short estado = 0; //me sirve para cambiar el estado de los leds

//condiciones para el antirrebote de los pulsadores
bool pulsa_der_1=1;   //me va a ayudar como condición para que no avance los led cuando queda sin presionar el botón derecho
bool pulsa_izq_1=1;   //me va a ayudar como condición para que no avance los led cuando queda sin presionar el botón izquierdo

void setup() {
//configurar los pines de salida
 for(int i=0; i<C_LED; i++){
  pinMode(led[i],OUTPUT); 
 }
 
//configurar los pines de entrada
 for(int i=0; i<C_PULSADORES; i++){
  pinMode(pulsador[i],INPUT);
 }
}

void loop() {

//Antirrebote pulsador izquierdo
  if(digitalRead(pulsador[1]) && pulsa_izq_1==1){     // pulsador iquierdo presionado y condición 
    led_izquierdo();                                  //función para ir incrementando los leds
    pulsa_izq_1=0;                                    //se pone a 0 para evitar que entre en la condición nuevamente mientras haya un rebote en el pulsador
  }
  if(digitalRead(pulsador[1])==0){                     //Cuando el pulsador se estabiliza, su valor es 0
    pulsa_izq_1=1;                                    //vuelvo a la misma condición inicial 
  }

//Antirrebote pulsador derecha - se aplica el mismo método que en el otro pulsador-
  if(digitalRead(pulsador[0]) && pulsa_der_1==1){  
    led_derecho();
    pulsa_der_1=0;
  }
  if(digitalRead(pulsador[0])==0){
    pulsa_der_1=1;
  }
}

void led_izquierdo(){
  digitalWrite(led[estado],LOW);             //Apaga el led que se encontraba prendido anterior al que se va a prender después - de izquierda a derecha-
  estado++; 
  if(estado >= (C_LED-1); estado++){        
    estado=0;                                //Vuelve a empezar la secuencia si llega al último led de la derecha
  }
  digitalWrite(led[estado],HIGH);          //Va prendiendo los leds, uno a uno
}

void led_derecho(){
  digitalWrite(led[estado],LOW);          //Apaga el led que se encontraba prendido anterior al que se va a prender después - de derecha a izquierda-
    estado--;
    if(estado < 0){
      estado= (C_LED-1);                  //Empieza la secuencia del ultimo led cuando ha llegado al primero
    }
    digitalWrite(led[estado],HIGH);       
  }


  
