/*
 * UNITEC Campus Queretaro
 * 
 * 
 * Practica 4: Contador de revoluciones
 * 
 * Autor: Ing. Gustavo David Mendoza Pinto 
 * Automatización y control en la era digital
 */

//Variables para uso en el encoder
long int steps;
long int timeOld;
long int timeP;
long int sampleTime = 500;
long int stepsOld;
long int stepPerRad = 20;
double rev;
long int deltaSteps;
//V Variables de control del motor
int control_motor = 9;
int motorOutputA = 5;
int motorOutputB = 4;
// Funciones globales
void contador();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  steps = 0;
  attachInterrupt(digitalPinToInterrupt(3),contador,FALLING);
  timeOld = 0;
  pinMode(control_motor,OUTPUT);
  pinMode(motorOutputA,OUTPUT);
  pinMode(motorOutputB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motorOutputA,HIGH);
  digitalWrite(motorOutputA,LOW);
  analogWrite(control_motor,125);
  timeP = millis();
  if(timeP -timeOld >= sampleTime){
    noInterrupts();
    deltaSteps = steps - stepsOld;
    rev= deltaSteps/20;
    Serial.println(rev);
    interrupts();
    timeOld = timeP;
  }
  
  
}
void contador(){
  ++steps;
}
