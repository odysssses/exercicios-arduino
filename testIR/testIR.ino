#define PinSensor 12
#define PinSensor2 13 // Entrada digital do Arduino conectado ao pino OUT do Sensor 
int LeituraSensor; //Váriavel que irá armazenar os valores de leitura do sensor
int LeituraSensor2;

void setup() {
  Serial.begin(9600); //Inicializa a comunicação serial
  pinMode(PinSensor, INPUT); // Declara o pino do sensor como entrada (INPUT)
  pinMode(PinSensor2, INPUT);
}

void loop() {
  LeituraSensor = analogRead(PinSensor);
  LeituraSensor2 = analogRead(PinSensor2);//Leitura de dados do sensor
  Serial.print("Leitura dos sensores: ");
  Serial.println(LeituraSensor);
  Serial.println(LeituraSensor2);
}
