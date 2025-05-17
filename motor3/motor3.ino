const int IN1 = 2;
const int IN2 = 3;
const int ENA = 5;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  analogWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3000);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  delay(2000);
}
