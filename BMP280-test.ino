/***************************************************************************
 Altímetro Nibus - Lectura de altitud con sensor BMP280 vía I2C.
 Este programa realiza una lectura inicial para fijar la altitud cero
 y luego mide en tiempo real la altitud relativa.
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Comunicación I2C

float initialAltitude = 0;
float altitude = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(100);
  Serial.println(F("BMP280 test"));

  unsigned status = bmp.begin();
  if (!status) {
    Serial.println("ERROR: No se encontró el sensor");
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(), 16);
    Serial.print("        ID of 0xFF probablemente significa una dirección incorrecta o sensor incompatible.\n");
    Serial.print("   ID de 0x56-0x58 representa BMP280,\n");
    Serial.print("        0x60 BME280, 0x61 BME680.\n");
    while (1) delay(10);
  }

  // Lectura inicial para establecer altura cero relativa
  initialAltitude = bmp.readAltitude(1028.1);  // Ajustar según presión local
}

void loop() {
  altitude = bmp.readAltitude(1028.1) - initialAltitude;

  Serial.print(F("Altura aproximada = "));
  Serial.print(altitude);
  Serial.println(" m");

  delay(1000);
}

