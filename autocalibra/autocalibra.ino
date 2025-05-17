const int ledverde = 4;
const int ledverm = 3;
const int sensor = A3;

int pretog;
char iv;

void pisca(int t) {
  for (int i = 0; i < t; i++) {
    delay(1000);
    digitalWrite(ledverm, HIGH);
    Serial.println("piscou");
    delay(50);
    digitalWrite(ledverm, LOW);
  }
}

void defcor(int val) {
  if (val <= pretog + 70 ) {
    iv = 'p';
  } else {
    iv = 'b';
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledverde, OUTPUT);
  pinMode(ledverm, OUTPUT);  

  pinMode(sensor, INPUT);

  pisca(3);
  delay(1000);
  pretog = analogRead(sensor);
  digitalWrite(ledverde, HIGH); Serial.println("piscouv"); delay(50); digitalWrite(ledverde, LOW);
}

void loop() {
  int sensval = analogRead(sensor); 
  defcor(sensval);
  Serial.println(iv);
  Serial.print(" " + String(sensval));
}
