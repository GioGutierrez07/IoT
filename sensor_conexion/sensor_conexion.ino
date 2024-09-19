#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "MATEBOOK 7565";  
const char* password = "kakao2002";

String URL = "https://iotchaketinte.000webhostapp.com/insertar_temperatura.php"; // URL del servidor donde enviar los datos

const int lm35Pin = 32; // Pin al que está conectado el LM35
const int trigPin = 13; // Pin del ESP32 conectado al pin Trig del sensor ultrasónico
const int echoPin = 12; // Pin del ESP32 conectado al pin Echo del sensor ultrasónico
const int buzzerPin = 14; // Pin del ESP32 conectado al zumbador pasivo

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  connectWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  float temperature = readLM35();
  float distance = readUltrasonic();

  String postData = "temperature=" + String(temperature) + "&distance=" + String(distance);

  if (distance >= 11) {
    digitalWrite(buzzerPin, HIGH); // Activa el zumbador
  } else {
    digitalWrite(buzzerPin, LOW); // Desactiva el zumbador
  }

}

WiFiClientSecure client;
  client.setInsecure(); // No verifiques el certificado SSL

  HTTPClient http;
  http.begin(client, URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);
  String payload = "";

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }