#define LED 13
String datosRecibidos;

void setup() {
 Serial.begin(9600);
 pinMode(LED,OUTPUT);
}

void loop() {
  if(Serial.available()>0){

    datosRecibidos=Serial.readString();
    Serial.print("OK");
    Serial.println(datosRecibidos);
    
    if(datosRecibidos == "E"){
      digitalWrite(LED,HIGH);
    }
    
    else if(datosRecibidos == "A"){
      digitalWrite(LED,LOW);
    }
  }
}
