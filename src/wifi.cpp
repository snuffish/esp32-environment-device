#include <Arduino.h>
#include <WiFiManager.h>

#include "DisplayManager.h"

#define SSID "AutoConnectAP"
#define PASSWORD "12345678"

WiFiManager wm;

bool setupWiFi()
{
    auto display = DisplayManager::getDisplay();

    display.println("SSID: " + String(SSID));
    display.println("Password: " + String(PASSWORD));
    display.display();

    delay(1000);

    const bool isSuccessful = wm.autoConnect(SSID, PASSWORD);
    Serial.println(isSuccessful ? "Connected" : "Failed to connect");

    return isSuccessful;
}
