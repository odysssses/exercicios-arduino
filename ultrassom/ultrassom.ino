const int ping = 5;
const int echo = 6;
const int led = 3;

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void setup() {
  pinMode(echo, INPUT);
  pinMode(ping, OUTPUT);
  
}

void loop() {
  digitalWrite(ping, LOW);
  delayMicroseconds(2);
  digitalWrite(ping, HIGH);
  delayMicroseconds(10);
  digitalWrite(ping, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = microsecondsToCentimeters(duration);

  if (distance <= 5){
    digitalWrite(led, HIGH);
    }
  else {
    digitalWrite(led, LOW);
    }
}
  
