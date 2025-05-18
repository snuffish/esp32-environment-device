#include "Adafruit_SSD1306.h"
#include "../include/oled.h"
#include "../include/sensor.h"

Adafruit_SSD1306 display(128, 32, &Wire);

void clearDisplay()
{
    display.clearDisplay();
    display.display();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

void oledSetup()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

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
    clearDisplay();

    SensorData data = getSensorData();
    printRow("Temp", data.temperature, "C");
    printRow("Humidity", data.humidity, "%");
    printRow("Pressure", data.pressure, "hPa");

    display.display();
    delay(1000);
}
