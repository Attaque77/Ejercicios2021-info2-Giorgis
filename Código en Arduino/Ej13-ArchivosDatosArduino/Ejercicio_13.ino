#include<SPI.h>
#include<SD.h>
#define SSpin 10

File archivo;

 struct sensores{
  char sensor;
  int16_t valor;
  int32_t tiempo;
 }escribir;
 
void setup() {
  
 Serial.begin(9600);
 if(!SD.begin(SSpin)){
  Serial.println("Error con la tarjeta SD");
  while(1);
 }
 
 Serial.println("Tarjeta iniciada");

 escribir,sensor= 'A';
 escribir.valor= 40;
 escribir.tiempo= 4;

  //Apertura de archivo como escritura
  if((archivo= SD.open("Ejercicio13.txt".FILE_WRITE))==NULL){
    println("\nERROR - No se ha podido abrir el archivo -");
  }

  else
  {
    archivo.write((const uint8_t *)&escribir, sizeof(escribir));
    archivo.close(); 
  }
  
  //Apertura de archivo como lectura
  if((archivo= SD.open("Ejercicio13.txt".FILE_READ))==NULL){
    println("\nERROR - No se ha podido abrir el archivo -");
  }

  else{
    while(archivo.available()){
      Serial.write(archivo.read());
    }
    archivo.close();
  }
}

void loop() {
}
