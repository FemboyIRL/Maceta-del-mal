#include <HTTPClient.h>  // Asegúrate de que la librería HTTPClient está incluida

class HttpClient {
  private:
    String baseUrl;  // URL base para las peticiones

  public:
    // Constructor
    HttpClient(const char* url) {
      baseUrl = url;
    }

    // Método para registrar datos de sensores
    void registerSensorData(String id_maceta, String data) {
      String url = baseUrl + "/api/smartpots/" + id_maceta + "/sensors/add/";
      HTTPClient http;

      http.begin(url);  // Inicia la conexión
      http.addHeader("Content-Type", "application/json");  // Tipo de contenido
      http.addHeader("Authorization", "Token b73332fb3c36a251729df75b026e4bdb5f19715b");

      int httpResponseCode = http.POST(data);  // Realiza la solicitud POST

      if (httpResponseCode > 0) {
        String response = http.getString();  // Obtiene la respuesta
        Serial.println("Respuesta del servidor: " + response);
      } else {
        Serial.print("Error en la solicitud POST: ");
        Serial.println(httpResponseCode);
      }

      http.end();  // Finaliza la conexión
    }

    // Método para obtener configuraciones
    String getConfigurations(String id_maceta) {
      String url = baseUrl + "/api/macetas/" + id_maceta + "/configuraciones/";
      HTTPClient http;

      http.begin(url);  // Inicia la conexión

      int httpResponseCode = http.GET();  // Realiza la solicitud GET

      String response;
      if (httpResponseCode > 0) {
        response = http.getString();  // Obtiene la respuesta
        Serial.println("Respuesta del servidor: " + response);
      } else {
        Serial.print("Error en la solicitud GET: ");
        Serial.println(httpResponseCode);
      }

      http.end();  // Finaliza la conexión
      return response;  // Devuelve la respuesta
    }

    // Método para registrar evento de riego
    void registerIrrigationEvent(String id_maceta, String data) {
      String url = baseUrl + "/api/macetas/" + id_maceta + "/riego/";
      HTTPClient http;

      http.begin(url);  // Inicia la conexión
      http.addHeader("Content-Type", "application/json");  // Tipo de contenido

      int httpResponseCode = http.POST(data);  // Realiza la solicitud POST

      if (httpResponseCode > 0) {
        String response = http.getString();  // Obtiene la respuesta
        Serial.println("Respuesta del servidor: " + response);
      } else {
        Serial.print("Error en la solicitud POST: ");
        Serial.println(httpResponseCode);
      }

      http.end();  // Finaliza la conexión
    }
};
