//IN 1 e 2: OUT2 
//IN 3 e 4: OUT1
#define dirR 7 // direção do motor direito: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define mR 8 // velocidade do motor direito ( 0 a 255) _ Porta IN2 ponte H; 
#define dirL 9 //direção do motor /home/odysseus/Documentos/exercicios_arduino/motor/motor.inoesquerdo: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;
#define mL 10 // velocidade do motor esquerdo ( 0 a 255) _ Porta IN4 ponte H;

int vel = 255;
int vel0 = 0;

void setup() {
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);

  digitalWrite(dirL,LOW);
  digitalWrite(dirR, LOW);
} 

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
  digitalWrite(dirL, LOW);/home/odysseus/Documentos/Arduino/codigos/C¢digos/Keli/OBR2023/OBR2023.ino
  digitalWrite(dirR, HIGH);
  m();  
  delay(t);
}/home/odysseus/Documentos/Arduino/codigos/robot/robot.ino

void stp(int t) {
  digitalWrite(dirL, LOW);
  digitalWrite(dirR, LOW);
  analogWrite(mL, vel0);
  analogWrite(mR, vel0);
  delay(t);
}

void loop() {/home/odysseus/Documentos/Arduino/codigos/C¢digos/Keli/Keli2.3/Novo_c_digo_OBR/Novo_c_digo_OBR.ino
  mov(1000);
  turnR(1000);
  turnL(1000);
  stp(1000);
//  analogWrite(mL, vel);
//  analogWrite(mR, vel);
//  delay(1000);
//  analogWrite(mL, vel0);
//  analogWrite(mR, vel);
//  delay(1000);
//  analogWrite(mL, vel);
//  analogWrite(mR, vel0);
//  delay(1000);
//  analogWrite(mL, vel0);
//  analogWrite(mR, vel0);
//  delay(1000);
}
