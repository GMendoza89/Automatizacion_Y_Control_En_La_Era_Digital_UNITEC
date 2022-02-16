/*
 *  Programa 1 practica 3 
 *  Automatización y Control en la era Digital
 *  UNITEC -  Campus Querétaro
 *  Salida de Señal Pwm V
 *  Autor: Ing. Gustavo David Mendoza Pinto
 */


byte pwmSignal = 6; // Indicamos la salida pwm del arduino
void setup() {
  pinMode(pwmSignal, OUTPUT); // Configuramos puerto como salida digital
}
void loop() {

  //Iniciamos ciclos de salida
  for(byte i0 = 0; i0<256; ++i0){
    analogWrite(pwmSignal,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }
  //Cambiamos el pulso de forma decreciente
  for(byte i0 = 255; i0>0; --i0){
    analogWrite(pwmSignal,i0); //escribimos el ciclo de trabajo en el pwm con la funcion analogWrite
    delay(100);                // esperamos 100 mS antes de escribir el ciclo nuevamente
  }

}
