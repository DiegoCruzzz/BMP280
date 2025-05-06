/***************************************************************************
 Altímetro Nibus - Lectura de altitud con promedio para mayor precisión.
 Este programa promedia varias lecturas por segundo del BMP280 para
 reducir ruido y obtener una altitud más precisa.
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Comunicación I2C

float initialAltitude = 0;
float altitude = 0;

// Configuración de promedio
const int numReadings = 10;  // Lecturas por ciclo
float pressureReference = 1028.1; // hPa (ajustar según condiciones locales)

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(100);
  Serial.println(F("BMP280 con promedio"));

  unsigned status = bmp.begin();
  if (!status) {
    Serial.println("ERROR: No se encontró el sensor");
    while (1) delay(10);
  }

  // Lectura inicial para fijar altitud base
  initialAltitude = bmp.readAltitude(pressureReference);
}

void loop() {
  float sum = 0;

  for (int i = 0; i < numReadings; i++) {
    sum += bmp.readAltitude(pressureReference);
    delay(1000 / numReadings);  // Distribuir las lecturas en 1 segundo
  }

  altitude = (sum / numReadings) - initialAltitude;

  Serial.print(F("Altura promedio = "));
  Serial.print(altitude);
  Serial.println(" m");
}
