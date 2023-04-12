#include <Servo.h>

// Macros para los pines de los servos
#define S1 5
#define S2 9
#define S3 10
#define S4 11

// Macros para los pines analógicos de los potes
#define P1 A1
#define P2 A2
#define P3 A3
#define P4 A4


// Creación de los objetos servo en el código
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Declaración de las variables que leerán los valores de los potenciómetros.
int pot1;
int pot2;
int pot3;
int pot4;

// Declaración de las variables que darán la posición a los servos
int ser1;
int ser2;
int ser3;
int ser4;

void setup() {
  pinMode(P1,INPUT);
  pinMode(P2,INPUT);
  pinMode(P3,INPUT);
  pinMode(P4,INPUT);
  
  // Para leer la posición de los servos y los potes en pantalla
  Serial.begin(9600);

  // Unimos los servos al pin que les corresponde
  servo1.attach(S1);
  servo2.attach(S2);
  servo3.attach(S3);
  servo4.attach(S4);

}

void loop() {

  // Leemos el valor de los 4 potenciómetros
  pot1 = analogRead(P1);
  pot2 = analogRead(P2);
  pot3 = analogRead(P3);
  pot4 = analogRead(P4);

  // Convertimos el valor de los potenciómetros a un ángulo del servo
  ser1 = map(pot1, 0, 1024, 0, 180);
  ser2 = map(pot2, 0, 1024, 0, 180);
  ser3 = map(pot3, 0, 1024, 0, 180);
  ser4 = map(pot4, 0, 1024, 0, 180);

  // Llevamos el servo a la posición marcada
  servo1.write(ser1);
  servo2.write(ser2);
  servo3.write(ser3);
  servo4.write(ser4);

  //Le damos un pequeño tiempo para que el servo alcance la posición
}
