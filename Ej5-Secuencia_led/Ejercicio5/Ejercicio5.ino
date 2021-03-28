#define led1 2
#define led2 3
#define led3 4

#define pulsa1 5
#define pulsa2 6
unsigned int pulsa1_der=1;
unsigned int pulsa2_izq=1;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
  pinMode(pulsa1,INPUT);
  pinMode(pulsa2,INPUT);
}

void loop() {

//Antirrebote pulsador derecha
  if(digitalRead(pulsa1) && pulsa1_der==1){ 
    led_derecha();
    pulsa1_der=0;
  }
  if(digitalRead(pulsa1)==0){
    pulsa1_der=1;
  }
  
 //Antirrebote pulsador izquierdo
  if(digitalRead(pulsa2) && pulsa2_izq==1 ){
    led_izquierdo();
    pulsa2_izq=0;
  }
  if(digitalRead(pulsa2)==0){
    pulsa2_izq=1;
  }
}

void led_derecha(){
   
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(200);

digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3,LOW);
delay(200);

digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,HIGH);
delay(200);
}

void led_izquierdo(){
  
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,HIGH);
delay(200);

digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3,LOW);
delay(200);

digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
delay(200);
}
  
