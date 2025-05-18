#include "../include/sensor.h"

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
        while (1) delay(10);
    }

    bme_temp->printSensorDetails();
    bme_pressure->printSensorDetails();
    bme_humidity->printSensorDetails();
}

SensorData getSensorData()
{
    sensors_event_t temp_event, temp_pressure, temp_humidity;
    bme_temp->getEvent(&temp_event);
    bme_pressure->getEvent(&temp_pressure);
    bme_humidity->getEvent(&temp_humidity);

    SensorData data;
    data.temperature = temp_event.temperature;
    data.pressure = temp_pressure.pressure;
    data.humidity = temp_humidity.relative_humidity;

    return data;
}

void sensorLog()
{
    auto data = getSensorData();

    Serial.print(F("Temperature = "));
    Serial.print(data.temperature);
    Serial.println("*C");

    Serial.print(F("Humidity = "));
    Serial.print(data.humidity);
    Serial.println("%");

    Serial.print(F("Pressure = "));
    Serial.print(data.pressure);
    Serial.println("hPa");
}
