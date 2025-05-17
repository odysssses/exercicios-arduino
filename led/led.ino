void setup() 
{
  pinmode(11, OUTPUT);
}
void loop() {
  digitalwrite(11, HIGH);

  delay(5000);

  digitalwrite(11, LOW);

  delay(1000);
 
}
