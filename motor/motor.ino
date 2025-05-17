const int mL = 8; // IN
const int mR = 9; // IN
const int mDL = 10; // IN
const int mDR = 11; // IN

int spd = 0;

void mov(dir, t) {
  if (dir == "right") {
    digitalWrite(mDL, HIGH);
    digitalWrite(mDR, LOW);
  } if (dir == "left") {
    digitalWrite(mDL, LOW);
    digitalWrite(mDR, HIGH);
  } else {/home/odysseus/Documentos/Arduino/codigos/seguelinha2/seguelinha2.ino
    digitalWrite(mDL, LOW);
    digitalWrite(mDR, LOW);
  }/home/odysseus/Documentos/Arduino/codigos/motor2/motor2.ino
  
  analogWrite(mL, spd);
  analogWrite(mR, spd);
  delay(t);  
}

void setup() {
  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);
  pinMode(mDL, OUTPUT);
  pinMode(mDR, OUTPUT);
}

void loop() {
  mov("", 1000)
}
