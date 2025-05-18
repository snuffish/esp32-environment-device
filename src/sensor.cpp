#include "headers.h"

#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
Adafruit_Sensor* bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor* bme_pressure = bme.getPressureSensor();
Adafruit_Sensor* bme_humidity = bme.getHumiditySensor();

void sensorSetup()
{
    if (!bme.begin())
    {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        for (;;) delay(10);
    }

    bme_temp->printSensorDetails();
    bme_pressure->printSensorDetails();
    bme_humidity->printSensorDetails();
}

// {
//     sensors_event_t temp_event, temp_pressure, temp_humidity;
//     bme_temp->getEvent(&temp_event);
//     bme_pressure->getEvent(&temp_pressure);
//     bme_humidity->getEvent(&temp_humidity);
//
//     SensorData data{};
//     data.temperature = temp_event.temperature;
//     data.pressure = temp_pressure.pressure;
//     data.humidity = temp_humidity.relative_humidity;
//
//     return data;
// }
