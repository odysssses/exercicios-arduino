//Motor
const int mL = 9; //IN2
const int mR = 11; //IN4
const int dirL = 10; //IN3
const int dirR = 8; //IN1
int vel = 75;

//Infravermelho
const int IRL = 6;
const int IRR = 7;
//0 = com linha, 1 = sem linha
bool sL = 1;
bool sR = 1;

void moveF() {
  analogWrite(mL, vel);
  analogWrite(mR, vel);
}

void brake() {
  analogWrite(mL, 0);
  analogWrite(mR, 0);
}

void turnR() {
  analogWrite(mL, 0);
  analogWrite(mR, vel);
}

void turnL() {
  analogWrite(mL, vel);
  analogWrite(mR, 0);
}

void setup() {
  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);

  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  
}

void loop() {
  sL = digitalRead(IRL);
  sR = digitalRead(IRR);
  
  if ((sL == 0) && (sR == 1)) { 
    turnL();
  } else if((sL == 1) && (sR == 0)) {
    turnR();
  } else {
     moveF();
  }
}
