//IN 1 e 2: OUT2 
//IN 3 e 4: OUT1
#define dirR 7 // direção do motor direito: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define movR 8 // velocidade do motor direito ( 0 a 255) _ Porta IN2 ponte H; 
#define dirL 9 //direção do motor esquerdo: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;
#define movL 10 // velocidade do motor esquerdo ( 0 a 255) _ Porta IN4 ponte H;

int vel = 255;
int vel0 = 0;

void setup() {
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  pinMode(movL, OUTPUT);
  pinMode(movR, OUTPUT);

  digitalWrite(dirL,LOW);
  digitalWrite(dirR, LOW);
} 

void loop() {
  analogWrite(movL, vel);
  analogWrite(movR, vel);
  delay(1000);
  analogWrite(movL, vel0);
  analogWrite(movR, vel);
  delay(1000);
  analogWrite(movL, vel);
  analogWrite(movR, vel0);
  delay(1000);
  analogWrite(movL, vel0);
  analogWrite(movR, vel0);
  delay(1000);
}
