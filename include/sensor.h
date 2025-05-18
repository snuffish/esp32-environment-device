#ifndef SENSOR_H
#define SENSOR_H

typedef struct SensorData
{
    float temperature;
    float humidity;
    float pressure;
} SensorData;

void sensorSetup();
SensorData getSensorData();

#endif //SENSOR_H
