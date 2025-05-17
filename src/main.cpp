#include <Adafruit_BME280.h>

#include "../lib/oled/src/oled.h"
#include "../lib/bme280Sensor/src/bme280Sensor.h"

void setup()
{
    Serial.begin(9600);

    Serial.println("Initializing BME280 Sensor...");
    sensorSetup();

    Serial.println("Initializing OLED Display...");
    oledSetup();
}

void loop()
{
    refreshOled();
    delay(1000);
}
