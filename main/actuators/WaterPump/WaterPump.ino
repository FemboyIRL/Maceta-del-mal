class WaterPump {
  private:
    int pin;  // Pin al que está conectado el relé

  public:
    // Constructor
    WaterPump(int p) {
      pin = p;
      pinMode(pin, OUTPUT);  // Configura el pin como salida
      digitalWrite(pin, LOW);  // Asegura que la bomba esté apagada al inicio
    }

    // Método para encender la bomba
    void turnOn() {
      digitalWrite(pin, HIGH);  // Enciende la bomba
    }

    // Método para apagar la bomba
    void turnOff() {
      digitalWrite(pin, LOW);  // Apaga la bomba
    }
};
