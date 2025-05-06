# Altímetro Numbus - Hypernova Aerospace

Este repositorio contiene distintos programas utilizados para el desarrollo del **Altímetro Numbus**, un sistema embarcado en cohetes desarrollado por **Hypernova Aerospace** para la medición de altitud en tiempo real mediante el sensor **BMP280** y, en su versión extendida, con el sensor **AHT20**.

El sistema permite establecer una referencia de altitud al encenderse y calcular la altitud relativa del vehículo durante el ascenso, con el objetivo de detectar el apogeo y activar mecanismos como el despliegue de un paracaídas.

## Archivos incluidos

- **BMP280-test.ino**  
  Código base de prueba que mide la altitud relativa usando el BMP280. Establece una altura inicial al arrancar y muestra lecturas cada segundo.

- **BMP280-prom.ino**  
  Variante mejorada que realiza un promedio de múltiples lecturas por segundo para reducir el ruido en las mediciones y obtener una altitud más precisa.

- **BMP280-AHT20.ino**  
  Versión extendida que incluye el sensor AHT20 para medir también la temperatura y humedad ambiental. Utiliza un módulo combinado BMP280 + AHT20.

## Requisitos

- Arduino IDE
- Librerías:
  - `Adafruit_BMP280`
  - `Adafruit_AHTX0` (solo para la versión AHT20)

## Aplicación

Este sistema es parte del hardware de vuelo del cohete y se utiliza como base para calcular altitud, detectar apogeo y activar sistemas de recuperación automatizados.

---

© Hypernova Aerospace, 2025
