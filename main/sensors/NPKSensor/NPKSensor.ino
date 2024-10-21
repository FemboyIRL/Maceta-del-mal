#include <SoftwareSerial.h>

#define RE 2   // Pin para habilitar recepción
#define DE 0   // Pin para habilitar transmisión

class NPKSensor {
  private:
    SoftwareSerial mod;  // Objeto SoftwareSerial para la comunicación con el sensor
    const byte nitroCmd[8] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
    const byte phosCmd[8] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
    const byte potaCmd[8] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
    byte values[11];

    byte sendCommand(const byte* command, size_t length) {
      digitalWrite(DE, HIGH);   // Habilita la transmisión
      digitalWrite(RE, HIGH);
      delay(10);
      if (mod.write(command, length) == 8) {  // Envía el comando al sensor
        digitalWrite(DE, LOW);  // Cambia a modo recepción
        digitalWrite(RE, LOW);
        delay(10);              // Espera para que lleguen los datos
        for (byte i = 0; i < 7; i++) {
          values[i] = mod.read();  // Lee los valores recibidos
        }
      }
      return values[4];  // Devuelve el valor relevante
    }

  public:
    NPKSensor(int rxPin, int txPin) : mod(rxPin, txPin) {}  // Constructor para inicializar SoftwareSerial

    void begin(long baudRate) {
      mod.begin(baudRate);
      pinMode(RE, OUTPUT);
      pinMode(DE, OUTPUT);
      digitalWrite(RE, LOW);  // Inicia en modo recepción
      digitalWrite(DE, LOW);
    }

    byte getNitrogen() {
      return sendCommand(nitroCmd, sizeof(nitroCmd));
    }

    byte getPhosphorus() {
      return sendCommand(phosCmd, sizeof(phosCmd));
    }

    byte getPotassium() {
      return sendCommand(potaCmd, sizeof(potaCmd));
    }
};
