/*
 *  Programa 2 practica 3 
 *  Automatización y Control en la era Digital
 *  UNITEC -  Campus Querétaro
 *  Control de Motor con Arduino y Puente H
 *  Autor: Ing. Gustavo David Mendoza Pinto
 */

byte signalEN = 6; // Indicamos la salida pwm del arduino
byte signalA = 8;
byte signalB = 7;
void setup() {
  pinMode(signalEN, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalA, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalB, OUTPUT); // Configuramos puerto como salida digital
}
void loop() {
  digitalWrite(signalA,HIGH); // enviamos un uno lógico a la salida A
  digitalWrite(signalB,LOW);  // enviamos un cero lógico a la salida A
  //Iniciamos ciclos de salida
  for(byte i0 = 0; i0<256; ++i0){
    analogWrite(signalEN,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }
  //Cambiamos el pulso de forma decreciente
  for(byte i0 = 255; i0>0; --i0){
    analogWrite(signalEN,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }
  digitalWrite(signalA,LOW); // enviamos un uno lógico a la salida A
  digitalWrite(signalB,HIGH);  // enviamos un cero lógico a la salida A
  //Iniciamos ciclos de salida
  for(byte i0 = 0; i0<256; ++i0){
    analogWrite(signalEN,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }
  //Cambiamos el pulso de forma decreciente
  for(byte i0 = 255; i0>0; --i0){
    analogWrite(signalEN,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }

}
