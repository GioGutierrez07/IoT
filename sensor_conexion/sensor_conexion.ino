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