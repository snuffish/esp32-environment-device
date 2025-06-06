#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_BME280 bme; // use I2C interface
Adafruit_Sensor* bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor* bme_pressure = bme.getPressureSensor();
Adafruit_Sensor* bme_humidity = bme.getHumiditySensor();

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void bme280_init()
{
    Serial.println(F("BME280 Sensor event test"));

    if (!bme.begin())
    {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        while (1) delay(10);
    }

    bme_temp->printSensorDetails();
    bme_pressure->printSensorDetails();
    bme_humidity->printSensorDetails();
}

void oled_init()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }

    // Serial.println("SSD1306 Initialized!");
}

bool oled_test = false;

void setup()
{
    Serial.begin(9600);

    bme280_init();
    oled_init();
}

void drawDisplay()
{
    if (oled_test)
    {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println("OLED TEST");
        display.display();

        return;
    }

     sensors_event_t temp_event, pressure_event, humidity_event;
     bme_temp->getEvent(&temp_event);
     bme_pressure->getEvent(&pressure_event);
     bme_humidity->getEvent(&humidity_event);

     // Clear the buffer
     display.clearDisplay();

     display.setTextSize(1);
     display.setTextColor(SSD1306_WHITE);
     display.setCursor(0, 0);
     // display.println("OLED TEST");
     display.printf("Temprature: %.2f C\n", temp_event.temperature);
     display.printf("Humidity: %.2f ", humidity_event.relative_humidity);
     display.print("%\n");
     display.printf("Pressure: %.2f hPa\n", pressure_event.pressure);

     display.display();


    // Serial.print(F("Temperature = "));
    // Serial.print(temp_event.temperature);
    // Serial.println(" *C");
    //
    // Serial.print(F("Humidity = "));
    // Serial.print(humidity_event.relative_humidity);
    // Serial.println(" %");
    //
    // Serial.print(F("Pressure = "));
    // Serial.print(pressure_event.pressure);
    // Serial.println(" hPa");
}

void loop()
{
    drawDisplay();
    Serial.println("Display updated");
    delay(1000);
}