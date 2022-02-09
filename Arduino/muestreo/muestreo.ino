
byte intSensor = A0;    
unsigned long int tiempo;
unsigned long int tiempoMuestreo; 
float datos[50];
int dato;
int N;
void setup() {
  Serial.begin(9600);
  tiempoMuestreo = 250;
  tiempo =  micros();
  dato = 0;
  N = 500;

}

void loop() {
 while(dato < N){
  if( micros() - tiempo > tiempoMuestreo){
    datos[dato] = (analogRead(intSensor)/1023)*5;
    ++dato;
  }
 }
 for(int i0 = 0; i0 < N;++i0){
  Serial.println(datos[i0]);
 }
 dato = 0;

}
