#define mL 9 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta IN2 ponte H;
#define mR 11 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta IN4 ponte H;
#define dirL 8 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define dirR 10 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

int vel = 125;

//Sensor ultrassônico
#define echo 6
#define trig 7
float echoTime = 0;
const float usVel = 340; //metros por segundo
const float usVelMS = 0.000340; //metros por microsegundo
float dist = 0; 

void obst() {
  vel = 250; turnL(); delay(1000);
  vel = 125; mov(); delay(1100);
  vel = 250; turnR(); delay(1000);
  vel = 125; mov(); delay(2000);
  vel = 250; turnR(); delay(100);
  vel = 125; mov(); delay(1100);
  
  vel = 250; turnL(); delay(1000);
  vel = 125;
}

void trigger() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}

float calcDist(float usTime) {
  return((usTime*usVelMS)/2);
}

void m() {
  analogWrite(mL, vel);
  analogWrite(mR, vel);
}

void stp() {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  analogWrite(mL, 0);
  analogWrite(mR, 0); 
}

void mov() {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  m();
}

void back() {
  digitalWrite(dirL, HIGH);
  digitalWrite(dirR, HIGH);
  m();
}

void turnL() {
  digitalWrite(dirL, HIGH);
  digitalWrite(dirR, LOW);
  m();  
}

void turnR() {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, HIGH);
  m();  
}

void setup() {
  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

  Serial.begin(9600);
  
  trigger();
  delay(1000);
}

void loop() {
  trigger();
  echoTime = pulseIn(echo, HIGH);
  dist = calcDist(echoTime)*100;
  
  Serial.print("Distancia (cm): ");
  Serial.println(dist);
  
  if ((dist <= 13) && (dist != 0)) { obst(); } else { mov(); }
  
}
