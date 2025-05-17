const int ledverde = 4;
const int ledverm = 3;
#define sensorL A3
#define sensorR A1

int pretogL;
int pretogR;
String ivL;
String ivR;

void pisca(int t, int led) {
  for (int i = 0; i < t; i++) {
    delay(1000);
    digitalWrite(led, HIGH);
    Serial.print("piscou: ");
    switch (led) {case 3: Serial.println("vermelho"); break; case 4: Serial.println("verde");}
    delay(50);
    digitalWrite(led, LOW);
  }
}

String defcor(int val, int pretog) {
  if (val <= pretog + 70 ) {
    return "preto";
  } else {
    return "branco";
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledverde, OUTPUT);
  pinMode(ledverm, OUTPUT);  

  pinMode(sensorL, INPUT);
  pinMode(sensorR, INPUT);

  pisca(3, ledverm); pretogL = analogRead(sensorL); pisca(1, ledverde);
  pisca(3, ledverm); pretogR = analogRead(sensorR); pisca(1, ledverde);
}

void loop() { 
  int sensval[2] = {analogRead(sensorL), analogRead(sensorR)};
  ivL = defcor(sensval[0], pretogL); ivR = defcor(sensval[1], pretogR);
  Serial.print("Sensor esquerdo: "); Serial.print(ivL); Serial.print(" " + String(sensval[0]));
  Serial.print(" \\ Sensor direito: "); Serial.print(ivR); Serial.println(" " + String(sensval[1]));
}
