#include "../sensors/DHTSensor/DHTSensor.h"   
#include "../sensors/FC28Sensor/FC28Sensor.h"   
#include "../sensors/NPKSensor/NPKSensor.h"   

// Instancias de los sensores
DHTSensor dhtSensor();  // Pin donde está el DHT22
FC28Sensor fc28Sensor(32);  // Pin donde está el FC-28
NPKSensor npkSensor();  // Pines de RE y DE para el NPK

void setup() {
  Serial.begin(115200);  // Asegúrate de que la velocidad es adecuada
}

void loop() {
  // Leer datos del DHT22
  float temperature = dhtSensor.readTemperature();
  float humidity = dhtSensor.readHumidity();
  
  // Leer datos del sensor de humedad del suelo FC-28
  int moisture = fc28Sensor.getMoistureLevel();
  
  // Leer datos del NPK sensor
  byte nitrogen = npkSensor.getNitrogen();
  byte phosphorus = npkSensor.getPhosphorus();
  byte potassium = npkSensor.getPotassium();

  // Imprimir los valores leídos
  Serial.printf("Temperatura: %.2f °C\n", temperature);
  Serial.printf("Humedad: %.2f %%\n", humidity);
  Serial.printf("Humedad del suelo: %d\n", moisture);
  Serial.printf("Nitrógeno: %d\n", nitrogen);
  Serial.printf("Fósforo: %d\n", phosphorus);
  Serial.printf("Potasio: %d\n", potassium);

  if(humidity < ){

  }
  
  // Esperar un tiempo antes de la siguiente lectura
  delay(5000);  // Espera 5 segundos
}