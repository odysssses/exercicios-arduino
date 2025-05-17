//definições==================================================================================================================================================================================================================================================================
#include <Wire.h>
#include "Adafruit_TCS34725.h"

//Motores---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define mL 9 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta IN2 ponte H;
#define mR 11 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta IN4 ponte H;
#define dirL 8 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define dirR 10 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

int vel = 125;

//Segue Linha-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define sL A0
#define sR A1
int sensorL = 0;
int sensorR = 0;
int black = 150;

//cor-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int a = 1;

byte gammatable[256];

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

//Sensor ultrassônico---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define echo 6
#define trig 7
float echoTime = 0;
const float usVel = 340; //metros por segundo
const float usVelMS = 0.000340; //metros por microsegundo
float dist = 0; 

//funções=====================================================================================================================================================================================================================================================================
void obst() {
  vel = 250; turnL(1000); 
  vel = 125; mov(1100); 
  vel = 250; turnR(900); 
  vel = 125; mov(2700); 
  vel = 250; turnR(1000); 
  vel = 125; mov(1100); 
  vel = 250; turnL(1000); 
  vel = 125;
}

//cor------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

char readcolor1() {
  float red, green, blue, LUX;
  delay(50);  // takes 50ms to read
  tcs.getRGB(&red, &green, &blue);

  int r = int(red);
  int g = int(green);
  int b = int(blue);

  Serial.println(g);
  Serial.print("\n");
  if (g > 180) { return ('g');} 
  else { return ('w');}
}

//ultrassom------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void trigger() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}

float calcDist(float usTime) {
  return((usTime*usVelMS)/2);
}

//motor---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void m() {
  analogWrite(mL, vel);
  analogWrite(mR, vel);
}

void mov(int t) {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  m();
  delay(t);
}

void turnL(int t) {
  digitalWrite(dirL, HIGH);
  digitalWrite(dirR, LOW);
  m();  
  delay(t);
}

void turnR(int t) {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, HIGH);
  m();  
  delay(t);
}
void stp(int t) {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  analogWrite(mL, 0);
  analogWrite(mR, 0); 
  delay(t);
}

//seguelinha---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void segueLinha() {
  if ((sensorL < black) && (sensorR > black)) {
    stp(50); 
    turnR(200); 
    Serial.println("Right");
  }
  
  else if ((sensorL > black) && (sensorR < black)) {
    stp(50); 
    turnL(200); 
    Serial.println("Left");
  }  
  else {
    mov(1);
    Serial.println("Foward");
  }
}
//setup====================================================================================================================================================================================================================================================================

void setup() {
  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  
  pinMode(sL, INPUT);
  pinMode(sR, INPUT);

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
  
  trigger();
  delay(1000);
}


//execs====================================================================================================================================================================================================================================================================

void execUS(){
  trigger();
  echoTime = pulseIn(echo, HIGH);
  dist = calcDist(echoTime)*100;
  
  Serial.print("Distancia (cm): ");
  Serial.println(dist);
  
  if ((dist <= 12) && (dist != 0)) {
    obst();
  }
}

void execCOR() {
  char cor = readcolor1();

  Serial.println(cor);

  if (cor == 'g') { mov(200); vel = 250; turnR(1000); vel = 125;}
}

void execSEGUELINHA() {
  sensorL = analogRead(sL);
  sensorR = analogRead(sR);
  
  Serial.print(sensorL);
  Serial.print(' ');
  Serial.println(sensorR);
  
  segueLinha();
}

//main====================================================================================================================================================================================================================================================================

void loop() {
  execUS();
  
  execCOR();

  execSEGUELINHA();
}
