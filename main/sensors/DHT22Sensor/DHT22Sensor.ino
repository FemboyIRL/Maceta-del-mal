#include "DHT.h"

#define DHTPIN 4         // Pin digital conectado al sensor DHT
#define DHTTYPE DHT11    // Definir el tipo de sensor DHT22

class DHTSensor {
  private:
    DHT dht;

  public:
    DHTSensor(int pin, int type) : dht(pin, type) {}  // Constructor que inicializa el sensor

    void begin() {
      dht.begin();  // Inicializa el sensor DHT
    }

    float getHumidity() {
      return dht.readHumidity();  // Devuelve la humedad relativa en porcentaje
    }

    float getTemperatureCelsius() {
      return dht.readTemperature();  // Devuelve la temperatura en grados Celsius
    }

    float getTemperatureFahrenheit() {
      return dht.readTemperature(true);  // Devuelve la temperatura en grados Fahrenheit
    }
};
