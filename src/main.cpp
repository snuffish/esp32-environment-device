#include <Arduino.h>
#include <WiFi.h>

#include "Adafruit_SSD1306.h"
#include "oled.h"
#include "sensor.h"
#include "wifi.h"

extern Adafruit_SSD1306 display;
extern void clearDisplay();

void setup()
{
    Serial.begin(9600);

    Serial.println("Initializing OLED Display...");
    oledSetup();

    Serial.println("Initializing WiFi...");
    setupWiFi();

    Serial.println("Initializing BME280 Sensor...");
    sensorSetup();
}

void loop()
{
    if (WiFi.isConnected())
    {
        refreshOled();
    }
    delay(1000);
}
