#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>

#include "DisplayManager.h"

void setup()
{
    Serial.begin(9600);

    Serial.println("Initializing OLED Display...");

    Serial.println("Initializing WiFi...");

    // Serial.println("Initializing BME280 Sensor...");
    // sensorSetup();
}

void loop()
{
    Serial.println("Hello World!");

    // DisplayManager::clearDisplay();

    auto display = DisplayManager::getDisplay();
    //
    display.println("HEJSAN");
    display.println("PÅ");
    display.println("DIGSAN");
    display.display();


    // if (WiFi.isConnected())
    // {
    //     // refreshOled();
    // }
    delay(1000);
}