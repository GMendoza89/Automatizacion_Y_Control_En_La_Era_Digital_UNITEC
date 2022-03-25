/*
 *  Programa 1 practica 4 
 *  Automatización y Control en la era Digital
 *  UNITEC -  Campus Querétaro
 *  Control de Motor con Arduino y Puente H
 *  Autor: Ing. Gustavo David Mendoza Pinto
 */

//Variables para uso en el encoder
long int steps;
long int timeOld;
long int timeP;
long int sampleTime = 100;
long int stepsOld;
long int stepPerRad = 20;
long int deltaTime;
double revolutions;
double RPS;
long int deltaSteps;
// Variables de control de motor
int reading;
int angularVel;

//V Variables de pines
byte signalEN = 6; // Indicamos la salida pwm del arduino
byte signalA = 8;
byte signalB = 7;
byte pot = A0;
byte pinInterrupsion = 3;

// Funciones globales
void counter();
void setup() {
  pinMode(signalEN, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalA, OUTPUT); // Configuramos puerto como salida digital
  pinMode(signalB, OUTPUT); // Configuramos puerto como salida digital

  digitalWrite(signalA,HIGH); // enviamos un uno lógico a la salida A
  digitalWrite(signalB,LOW);  // enviamos un cero lógico a la salida A
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(pinInterrupsion),counter,FALLING);
  steps = 0;
  timeOld = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(signalA,HIGH);
  digitalWrite(signalB,LOW);
  reading = analogRead(pot);
  angularVel = map(reading,0,1023,0,255);
  analogWrite(signalEN,angularVel);
  timeP = millis();
  deltaTime = timeP-timeOld;
  
  if(deltaTime >= sampleTime){
    noInterrupts();
    deltaSteps = steps - stepsOld;
    revolutions= deltaSteps/20;
    RPS = (revolutions/double(deltaTime))*1000;
    Serial.println(RPS);
    interrupts();
    timeOld = timeP;
  }
  
  
}
void counter(){
  ++steps;
}
