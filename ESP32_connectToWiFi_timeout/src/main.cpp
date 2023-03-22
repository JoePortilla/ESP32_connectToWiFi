/**
 * \file ESP32_connectToWiFi_timeout main.cpp
 * \brief Conexión de ESP32 a WiFi. Se define un timeout para intentar conectarse.
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include <WiFi.h>
#include "secrets.hpp" // Archivo con credenciales de servicio y contraseñas de usuario.

// VARIABLES Y CONSTANTES
const uint16_t timeoutWifi = 10000; // Tiempo de espera para conexión WiFi [ms].

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

  // Se almacena el tiempo de inicio del intento de conexión WiFi.
  uint32_t t0Wifi = millis();

  // Mientras que el ESP32 no se haya conectado y el tiempo sea menor al definido
  // en timeoutWifi el programa se bloquea.
  while (WiFi.status() != WL_CONNECTED && millis() - t0Wifi < timeoutWifi)
  {
    Serial.print(".");
    delay(200);
  }

  // Después de conectarse a WiFi ó esperar el tiempo definido en timeoutWifi se
  // comprueba el estado de conexión WiFi.
  if (WiFi.status() == WL_CONNECTED)
  {
    // Si la conexión fue correcta se imprime la IP y la fuerza de la señal WiFi.
    Serial.printf("\nWiFi conectado. IP: ");
    Serial.print(WiFi.localIP());
    Serial.printf(" RSSI: %d\n", WiFi.RSSI());
  }
  else
  {
    Serial.printf("\nConexión a WiFi fallida\n");
    // Acciones a ejecutar si no se pudo conectar a WiFi
    // ESP.restart(); // e.g.: Reiniciar ESP.
  }
}