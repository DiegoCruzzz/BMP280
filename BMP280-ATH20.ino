/***************************************************************************
 Altímetro Nibus - Lectura de altitud, temperatura y humedad con módulo BMP280 + AHT20.
 Este programa mide la altitud relativa usando el BMP280 y obtiene temperatura
 y humedad ambiental desde el sensor AHT20 integrado.
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_AHTX0.h>  // Librería para AHT20

Adafruit_BMP280 bmp;   // Sensor de altitud
Adafruit_AHTX0 aht;    // Sensor de temperatura y humedad

float initialAltitude = 0;
float altitude = 0;
float pressureReference = 1028.1; // hPa

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(100);
  Serial.println(F("BMP280 + AHT20"));

  // Inicializar BMP280
  if (!bmp.begin()) {
    Serial.println("ERROR: No se encontró el BMP280");
    while (1) delay(10);
  }

  // Inicializar AHT20
  if (!aht.begin()) {
    Serial.println("ERROR: No se encontró el AHT20");
    while (1) delay(10);
  }

  initialAltitude = bmp.readAltitude(pressureReference);
}

void loop() {
  // Altitud relativa
  altitude = bmp.readAltitude(pressureReference) - initialAltitude;

  // Lectura de temperatura y humedad
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("Altitud = ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.print("Temperatura = ");
  Serial.print(temp.temperature);
  Serial.println(" °C");

  Serial.print("Humedad = ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  Serial.println("-------------------------");
  delay(1000);
}
