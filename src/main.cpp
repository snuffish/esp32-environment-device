#include <Arduino.h>

#include "Adafruit_SSD1306.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("HEJ 1111");
    delay(1000);
    Serial.println("HEJ 2222");
    delay(1000);
}

void loop()
{
    Serial.println("Hello world!");
    delay(1000);
}
