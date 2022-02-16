/*
 *  Programa 3 practica 3 
 *  Automatización y Control en la era Digital
 *  UNITEC -  Campus Querétaro
 *  Control de Motor con Arduino y Puente H
 *  Autor: Ing. Gustavo David Mendoza Pinto
 */

byte signalEN = 6; // Indicamos la salida pwm del arduino
byte signalA = 8;
byte signalB = 7;
byte pot = A0;
int lectura;
int velocidad;
void setup() {
  pinMode(signalEN, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalA, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalB, OUTPUT); // Configuramos puerto como salida digital

  digitalWrite(signalA,HIGH); // enviamos un uno lógico a la salida A
  digitalWrite(signalB,LOW);  // enviamos un cero lógico a la salida A
}
void loop() {

  lectura = analogRead(pot);
  velocidad = map(lectura,0,1023,0,255);
  analogWrite(signalEN,velocidad);
  delay(100); // esperamos 100 mili segundos
}
