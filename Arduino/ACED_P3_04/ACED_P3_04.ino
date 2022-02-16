/*
 *  Programa 3 practica 3 
 *  Automatización y Control en la era Digital
 *  UNITEC -  Campus Querétaro
 *  Control de Motor con Arduino y Puente H
 *  Autor: Ing. Gustavo David Mendoza Pinto
 */

// Variables de pines
byte signalEN = 6; // Indicamos la salida pwm del arduino
byte signalA = 8;
byte signalB = 7;
byte pot = A0;
byte pinInterrupsion = 3;
// variables para control de motor
int lectura;
int velocidad;
// variables para control de pasos
long int pasosAnterior;
long int pasos;
long int tiempoPasado;
long int deltaPasos;
const long int tiempoMuestreo = 1000; // Tiempo de muestreo en milisegundos
//funcion de interrupcion
void contador();
// Configuracion del encoder
int pasosPorRevolucion = 20;

void setup() {
  pinMode(signalEN, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalA, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalB, OUTPUT); // Configuramos puerto como salida digital

  digitalWrite(signalA,HIGH); // enviamos un uno lógico a la salida A
  digitalWrite(signalB,LOW);  // enviamos un cero lógico a la salida A
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(pinInterrupsion),contador,FALLING);
  tiempoPasado = millis();
  
}
void loop() {

  lectura = analogRead(pot);
  velocidad = map(lectura,0,1023,0,255);
  analogWrite(signalEN,velocidad);
  if(millis() - tiempoPasado >= tiempoMuestreo){
    deltaPasos = pasos - pasosAnterior;
    double revoluciones = deltaPasos/pasosPorRevolucion;
    double RPS = (revoluciones/double(tiempoMuestreo))*1000;
    Serial.print("RPS: ");
    Serial.println(RPS);
    tiempoPasado = millis();
    pasosAnterior = pasos; 
  }
  
}
void contador(){
  ++pasos;
}
