/**
 * \file ESP32_connectToWiFi_basic main.cpp
 * \brief Conexión básica de ESP32 a WiFi. Mientras espera la conexión el programa se bloquea.
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include <WiFi.h>
#include "secrets.hpp" // Archivo con credenciales de servicio y contraseñas de usuario.

// DECLARACIÓN DE FUNCIONES
void connectToWiFi();

void setup()
{
  // Inicializar la comunicación serial a 115200 baudios.
  Serial.begin(115200);

  // Conexión a WiFi
  connectToWiFi();
}

void loop()
{
}

// IMPLEMENTACIÓN DE FUNCIONES
// Función para conectarse a WiFi.
void connectToWiFi()
{
  // Se configura al modulo WiFi del ESP32 en modo estación.
  WiFi.mode(WIFI_STA);
  // Iniciar conexión WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.printf("\nConectandose a la red WiFi: %s.", WIFI_SSID);

  // Mientras el ESP32 se conecta, el programa se bloquea en este while.
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
  }

  // Una vez conectado se imprime la IP y la fuerza de la señal WiFi.
  Serial.printf("\nWiFi conectado. IP: ");
  Serial.print(WiFi.localIP());
  Serial.printf(" RSSI: %d\n", WiFi.RSSI());
}