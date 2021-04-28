#define FOTO_R A5
unsigned short lectura=0;        
unsigned short convertidor=0;             
short LED=2;

void setup() {
  Serial.begin(9600); //Visualizar el monitor serie
  pinMode(LED,OUTPUT);
}

void loop() {
 Serial.println(analogRead(FOTO_R)); //Imprimir los valores
 delay(500);

 if(analogRead(FOTO_R)>10){             
  lectura=analogRead(FOTO_R);           
  convertidor=(lectura*255)/1023;       //Para adecuar la resolución de 10 bits del ADC a la de 8 bits del PWM
  digitalWrite(LED,convertidor);        //Configura el PWM con el valor de la lectura
 }
 if(analogRead(FOTO_R)<10){             
  digitalWrite(LED,LOW);
 }

}
