#include "Adafruit_SSD1306.h"
#include "../include/oled.h"
#include "../include/sensor.h"

auto display = Adafruit_SSD1306(128, 32, &WIRE);

void oledSetup()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

    Serial.println("Oled started!");
    display.display();
    delay(1000);
}

String formatDisplayValue(float value, int precision, const char* unit)
{
    char valueStr[10];
    dtostrf(value, 4, precision, valueStr);
    auto result = String(valueStr);
    result += " ";
    result += unit;

    return result;
}

void printRow(const String& title, const float value, const char* unit, const size_t titleWidth = 10)
{
    auto paddedTitle = title;
    while (paddedTitle.length() < titleWidth)
    {
        paddedTitle += " ";
    }

    display.print(paddedTitle + "= " + formatDisplayValue(value, 1, unit));
    display.println();
}

void refreshOled()
{
    display.clearDisplay();
    display.display();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);

    SensorData data = getSensorData();
    printRow("Temp", data.temperature, "C");
    printRow("Humidity", data.humidity, "%");
    printRow("Pressure", data.pressure, "hPa");

    display.display();

    delay(1000);
}
