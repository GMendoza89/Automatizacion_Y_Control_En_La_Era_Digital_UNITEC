
byte intSensor = A0;                            // Seleccion de sensor análogico
unsigned long int tiempo;                       // Variable almacenadora de tiempo
const unsigned long int tiempoMuestreo = 100;   // Variable de tiempo de muestro
const unsigned int N = 400;                     // Número de muestras a guardar
float datos[N];                                 // Vector de datos muestreados
unsigned int index = 0;                         // Inicialización el indice de lectura en 0
void setup() {        
  Serial.begin(115200);                         // Inicializamos comunicación serial en 115200 baudios
  tiempo =  micros();                           // Almacenamos el tiempo para esperar a guardar muestras
}

void loop() {
 while(index < N){                               // Inicia ciclo de llenado de datos del vector
  if( micros() - tiempo > tiempoMuestreo){      // verificamos si ya paso el tiempo suficiente entre muestras
    int lectura = analogRead(intSensor);        // hacemos lectura del sensor
    float valor = (float(lectura)/1023.0)*5.0;  // convertimos el valor de lectura en un nivel de voltaje
    datos[index] = valor;                        // guardamos el nivel de voltaje en el vector de los datos
    ++index;                                     // incrementamos el dato 
    tiempo = micros();                           // Almacenamos el nuevo tiempo
  }
 }
 for(int i0 = 0; i0 < N;++i0){                    // Iniciamos envio de cada uno de los vectores de datos por el monitor serial
  Serial.println(datos[i0]);                      // 
 }
 index = 0;                                       // Reiniciamos el indice del vector de datos a 0

}
