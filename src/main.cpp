#include <Arduino.h>

// Define os pinos de controle do motor no ESP8266
#define pinoMotor0 26// pinoMotor0 = D1; // 1F
#define pinoMotor1 12 // Pino de controle do motor 1
#define pinoMotor2 13// 2F
#define pinoMotor3 14 // Pino de controle do motor 2

void setup() {
    Serial.begin(9600);
  pinMode(pinoMotor0, OUTPUT);
  pinMode(pinoMotor1, OUTPUT);
  pinMode(pinoMotor2, OUTPUT);
  pinMode(pinoMotor3, OUTPUT);
}

void loop() {
  // Define a direção do motor (por exemplo, para frente)
 
 
 char comando = lerComando();

  switch (comando) {
    case 'W':
      // Ambos os motores ativados
        digitalWrite(pinoMotor1, HIGH);
        digitalWrite(pinoMotor2, HIGH);
        digitalWrite(pinoMotor3, LOW);
        digitalWrite(pinoMotor0, LOW);
      break;

    case 'S':
      // Parar ambos os motores
       digitalWrite(pinoMotor1, LOW);
       digitalWrite(pinoMotor2, LOW);
       digitalWrite(pinoMotor3, LOW);
       digitalWrite(pinoMotor0, LOW);
      break;

    case 'A':
        digitalWrite(pinoMotor1, LOW);
        digitalWrite(pinoMotor2, HIGH);
        digitalWrite(pinoMotor3, LOW);
        digitalWrite(pinoMotor0, HIGH);
      break;

    case 'D':
        digitalWrite(pinoMotor1, HIGH);
        digitalWrite(pinoMotor2, LOW);
        digitalWrite(pinoMotor3, HIGH);
        digitalWrite(pinoMotor0, LOW);
      break;

     case 'T':
        digitalWrite(pinoMotor1, LOW);
        digitalWrite(pinoMotor2, LOW);
        digitalWrite(pinoMotor3, HIGH);
        digitalWrite(pinoMotor0, HIGH);
      break;
  }
}

char lerComando() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    return comando;
  }
  return '\0';
}