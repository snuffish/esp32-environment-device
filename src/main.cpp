#include <Adafruit_BME280.h>

#include "oled.h"
#include "sensor.h""

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
