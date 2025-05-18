#include "Adafruit_Sensor.h"
#include "DisplayManager.h"
#include "headers.h"

void clearDisplay()
{
    auto display = DisplayManager::getDisplay();

    display.clearDisplay();
    display.display();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

String formatDisplayValue(const float value, const int precision, const char* unit)
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

    auto display = DisplayManager::getDisplay();

    display.print(paddedTitle + "= " + formatDisplayValue(value, 1, unit));
    display.println();
}

void refreshOled()
{
    clearDisplay();

    // auto& [temperature, humidity, pressure] = sensorData;
    // printRow("Temp", temperature, "C");
    // printRow("Humidity", humidity, "%");
    // printRow("Pressure", pressure, "hPa");
    //
    auto display = DisplayManager::getDisplay();
    display.display();
    delay(1000);
}
