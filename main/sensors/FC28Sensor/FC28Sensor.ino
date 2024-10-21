class FC28Sensor {
  private:
    int sensorPin;  // Pin al que está conectado el FC-28

  public:
    FC28Sensor(int pin) : sensorPin(pin) {}  // Constructor para inicializar el pin del sensor

    void begin() {
      pinMode(sensorPin, INPUT);  // Configura el pin como entrada
    }

    int getMoistureLevel() {
      int moistureValue = analogRead(sensorPin);  // Lee el valor analógico del sensor
      return moistureValue;  // Devuelve el nivel de humedad
    }
};
