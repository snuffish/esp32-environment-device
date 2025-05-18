#include <Arduino.h>
#include <WiFiManager.h>
#include "Adafruit_SSD1306.h"

#define SSID "AutoConnectAP"
#define PASSWORD "12345678"

extern Adafruit_SSD1306 display;
extern void clearDisplay();

WiFiManager wm;

void setupWiFi()
{
    clearDisplay();
    display.println("SSID: " + String(SSID));
    display.println("Password: " + String(PASSWORD));
    display.display();

    delay(1000);

    bool res = wm.autoConnect(SSID, PASSWORD);

    if (!res)
    {
        Serial.println("Failed to connect");
    }
    else
    {
        Serial.println("Connected!");
    }
}
