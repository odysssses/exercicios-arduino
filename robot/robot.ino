// motorLEFT :: ENA | motorRIGHT :: ENB
const int ENA = 2;
const int ENB = 3;
//motorLEFT :: IN1 && IN2 | motorRIGHT :: IN3 && IN4
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;

//Infrareds
const int sLEFT = 9;
const int sMID = 10;
const int sRIGHT = 11;
const int sFRONT_Line = 12;
const int sFRONT_Bot = 13;

//Ultrassonic
const int trig = 14;
const int echo = 15;

//Color Sensors
//left
const int s01 = 17;
const int s11 = 18;
const int s21 = 19;
const int s31 = 20;
const int sOut1 = 21;
//right
const int s02 = 22;
const int s12 = 23;
const int s22 = 24;
const int s32 = 25;
const int sOut2 = 26;

long msToCm(long duration) {
  return duration / 29 / 2;
}

void moveF() {
  digitalWrite(IN1, HIGH);  
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, HIGH);  
  digitalWrite(IN4, LOW);
}
void stopB() {
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, LOW);
}

void turnR() {
  digitalWrite(IN1, HIGH);  
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, LOW);
}

void turnL() {
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, HIGH);  
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(sLEFT, INPUT);
  pinMode(sMID, INPUT);
  pinMode(sRIGHT, INPUT);
  pinMode(sUP, INPUT);
  pinMode(sFront, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sOut, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

void loop() {
  //Infrared values (HIGH && LOW)
  //                 black && white

  int leftVal = digitalRead(sLEFT);
  int midVal = digitalRead(sMID);
  int rightVal = digitalRead(sRIGHT);
  int frontValLine = digitalRead(sFRONT_Line);
  int frontValBot = digitalRead(sFRONT_BOT);

  digitalWrite(s21, LOW);
  digitalWrite(s31, LOW);
  int rl = pulseIn(sOut, LOW);
  digitalWrite(s21, HIGH);
  digitalWrite(s31, HIGH);
  int gl = pulseIn(sOut, LOW);
  digitalWrite(s21, LOW);
  digitalWrite(s31, HIGH);
  int bl = pulseIn(sOut, LOW);

  digitalWrite(s22, LOW);
  digitalWrite(s32, LOW);
  int rr = pulseIn(sOut, LOW);
  digitalWrite(s22, HIGH);
  digitalWrite(s32, HIGH);
  int gr = pulseIn(sOut, LOW);
  digitalWrite(s22, LOW);
  digitalWrite(s32, HIGH);
  int br = pulseIn(sOut, LOW);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = msToCm(duration);

  //Moves foward if there is a straight line in front
  while (midVal == HIGH && frontValLine == HIGH) {
    int leftVal = digitalRead(sLEFT);
    int midVal = digitalRead(sMID);
    int rightVal = digitalRead(sRIGHT);
    int frontValLine = digitalRead(sFRONT_Line);
    int frontValBot = digitalRead(sFRONT_BOT);

    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    int r = pulseIn(sOut, LOW);
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    int g = pulseIn(sOut, LOW);
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    int b = pulseIn(sOut, LOW);

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    cm = msToCm(duration);
 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    if (cm <= 6) {
      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, LOW);  
      digitalWrite(IN4, LOW);
      delay(250)

      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(500)

      digitalWrite(IN1, LOW);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(250)

      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(1000)

      digitalWrite(IN1, LOW);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(250)

      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(500)

      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, LOW);  
      digitalWrite(IN4, LOW);
      delay(250)
    }
    if (rl < 100 && gl > 120 && bl < 100 && rr < 100 && gr < 100 && br < 100){
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);    
       digitalWrite(IN1, LOW);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);
    }
    else if (rl < 100 && gl < 100 && bl < 100 && rr < 100 && gr > 120 && br < 100){
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, LOW);  
       digitalWrite(IN4, LOW);
       delay(500);
    }
  }
  //checks if there is a turn all-way intersection, and if there is, the robot will turn around, go back, and turn at the first
  if (midVal == HIGH && frontValLine == LOW && leftVal == HIGH && rightVal == HIGH) {
      if (rl < 100 && gl > 120 && bl < 100 && rr < 100 && gr < 100 && br < 100){
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);
       digitalWrite(IN1, LOW);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);
    }
    else if (rl < 100 && gl < 100 && bl < 100 && rr < 100 && gr > 120 && br < 100){
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, HIGH);  
       digitalWrite(IN4, LOW);
       delay(500);
       digitalWrite(IN1, HIGH);  
       digitalWrite(IN2, LOW);  
       digitalWrite(IN3, LOW);  
       digitalWrite(IN4, LOW);
       delay(500);
    }  
    digitalWrite(IN1, LOW);  
    digitalWrite(IN2, LOW);  
    digitalWrite(IN3, HIGH);  
    digitalWrite(IN4, LOW);
    delay(1000);
    while (midVal == HIGH && frontValLine == HIGH) {
      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      if (rightVal == HIGH && leftVal == LOW) {
        digitalWrite(IN1, HIGH);  
        digitalWrite(IN2, LOW);  
        digitalWrite(IN3, LOW);  
        digitalWrite(IN4, LOW);
        delay(250);
        if (rightVal == HIGH && leftVal == LOW) {
          digitalWrite(IN1, HIGH);  
          digitalWrite(IN2, LOW);  
          digitalWrite(IN3, LOW);  
          digitalWrite(IN4, LOW);
          delay(250);
      }
      else if (rightVal == LOW && leftVal == HIGH) {
        digitalWrite(IN1, LOW);  
        digitalWrite(IN2, LOW);  
        digitalWrite(IN3, HIGH);  
        digitalWrite(IN4, LOW);
        delay(250);
        if (rightVal == LOW && leftVal == HIGH) {
          digitalWrite(IN1, LOW);  
          digitalWrite(IN2, LOW);  
          digitalWrite(IN3, HIGH);  
          digitalWrite(IN4, LOW);
          delay(250);
      }
    }
  }
  //When that straight line stops, and there are turns, will check where should it turn (and turn)
  while (midVal == HIGH && frontValLine == LOW) {
    digitalWrite(IN1, HIGH);  
    digitalWrite(IN2, LOW);  
    digitalWrite(IN3, HIGH);  
    digitalWrite(IN4, LOW);
    delay(500);
    if (leftVal == HIGH && rightVal == LOW) {
      digitalWrite(IN1, LOW);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, HIGH);  
      digitalWrite(IN4, LOW);
      delay(250);
      if (leftVal == HIGH && rightVal == LOW) {
        digitalWrite(IN1, LOW);  
        digitalWrite(IN2, LOW);  
        digitalWrite(IN3, HIGH);  
        digitalWrite(IN4, LOW);
        delay(250);
      }
    }
    else if (leftVal == LOW && rightVal == HIGH) {
      digitalWrite(IN1, HIGH);  
      digitalWrite(IN2, LOW);  
      digitalWrite(IN3, LOW);  
      digitalWrite(IN4, LOW);
      delay(250);
      if (leftVal == LOW && rightVal == HIGH) `{
        digitalWrite(IN1, HIGH);  
        digitalWrite(IN2, LOW);  
        digitalWrite(IN3, LOW);  
        digitalWrite(IN4, LOW);
        delay(250);
      }
    }
  }
  //when that straight line stops, and there are no turns, this means it is a gap, so it should just move
  while (midVal == LOW && leftVal == LOW && rightVal == LOW) {
    digitalWrite(IN1, HIGH);  
    digitalWrite(IN2, LOW);  
    digitalWrite(IN3, HIGH);  
    digitalWrite(IN4, LOW);
  }
}
