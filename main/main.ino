#include "sensors/DHT22Sensor/DHT22Sensor.ino"      
#include "actuators/WaterPump/WaterPump.ino" 
#include "network/WifiManager/WiFiManager.ino"  
#include "network/HttpClient/HttpClient.ino"
#include <ArduinoJson.h> 

const int pinDHTSensor=4;
const int pinWaterPump=22;
const int pinFloorHumidity=36;
const int DHTSensorType=11;

const int humedo = 265;
const int seco = 636;

// Instancias de los sensores
DHTSensor dhtSensor(pinDHTSensor,DHTSensorType);  // Pin donde está el DHT22
WaterPump waterPump(pinWaterPump);  // Pin donde esta el rele
WiFiManager wifiManager("la cabeZONA", "ivan12345");  
HttpClient httpClient("http://192.168.137.1:8000");

void setup() {
  analogReadResolution(10);
  Serial.begin(9600); 
  wifiManager.connect();
  pinMode(pinWaterPump,OUTPUT);  
}

void loop() {
  int lecturaSensor = analogRead(pinFloorHumidity);
  int porcentajeHumedad = map(lecturaSensor,humedo,seco,100,0);
  // Leer datos del DHT22
  float temperature = dhtSensor.getTemperatureCelsius();
  float humidity = dhtSensor.getHumidity();
  
  // Leer datos del sensor de humedad del suelo FC-28
  //int moisture = fc28Sensor.getMoistureLevel();

 
  // Imprimir los valores leídos
  Serial.printf("Temperatura: %.2f °C\n", temperature);
  Serial.printf("Humedad: %.2f %%\n", humidity);


   if(porcentajeHumedad<30){
    Serial.println("Suelo muy seco");
    digitalWrite(pinWaterPump,LOW);
  }else if(porcentajeHumedad>=30 && porcentajeHumedad<70){
    Serial.println("Suelo con buena humedad");
    digitalWrite(pinWaterPump,HIGH);
  }else{
    Serial.println("Suelo demasiado húmedo");
    digitalWrite(pinWaterPump, HIGH);
  }


  
  StaticJsonDocument<200> jsonDoc;
    jsonDoc["floor_humidity"] = humidity;
    jsonDoc["temperature"] = temperature;
    jsonDoc["light_level"] = 23;
    jsonDoc["water_level"] = 23;

     String jsonData;
    serializeJson(jsonDoc, jsonData);

    httpClient.registerSensorData("9", jsonData);



  
  // Esperar un tiempo antes de la siguiente lectura
  delay(10000);  // Espera 5 segundos
}