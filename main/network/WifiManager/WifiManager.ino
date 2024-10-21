#include <WiFi.h>  // Asegúrate de que la librería WiFi está incluida

class WiFiManager {
  private:
    const char* ssid;  // Nombre de la red Wi-Fi
    const char* password;  // Contraseña de la red Wi-Fi

  public:
    // Constructor
    WiFiManager(const char* ssid, const char* password) {
      this->ssid = ssid;
      this->password = password;
    }

    // Método para conectar al Wi-Fi
    void connect() {
      Serial.print("Conectando a Wi-Fi...");
      WiFi.begin(ssid, password);  // Inicia la conexión

      // Espera a que se conecte
      while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
      }
      Serial.println("Conectado!");
      Serial.print("Dirección IP: ");
      Serial.println(WiFi.localIP());  // Imprime la dirección IP asignada
    }

    // Método para comprobar si está conectado
    bool isConnected() {
      return WiFi.status() == WL_CONNECTED;
    }

    // Método para desconectarse del Wi-Fi
    void disconnect() {
      WiFi.disconnect();
      Serial.println("Desconectado del Wi-Fi");
    }
};
