 byte segmentos;
 
  void setup()
{
  DDRD= DDRD | B11111111; // puerto D0-D6 como salida. 
}

void loop()
{
  for (segmentos= B00000001; segmentos <= B10000000; segmentos= segmentos<<1)
  { 
    PORTD=segmentos;
    delay(500);
  }
}
