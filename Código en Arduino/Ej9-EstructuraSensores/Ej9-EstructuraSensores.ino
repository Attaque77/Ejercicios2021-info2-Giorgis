 struct sensores{
  char tipo_sensor;        // 1 byte
  int valor;               // 2 byte
  unsigned long tiempo;    // 4 byte
}muestra;

int alpha=0;

void setup(){
  //Configuramos el puerto serial
  Serial.begin(9600);
  Serial.println("HÚRSULA");
}
 
void loop(){
  alpha=sizeof(muestra);
  //El espacio ucupado por la estructura es la suma de los tamaños de memoria de cada tipo de dato
  Serial.println(alpha); //Imprimimos el valor de el tamaño de la estructura 'muestra'
  delay(5000); 
}
