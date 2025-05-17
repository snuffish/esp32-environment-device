#ifndef SENSOR_H
#define SENSOR_H

struct SensorData
{
    float temperature;
    float humidity;
    float pressure;
};

extern void sensorSetup();
extern SensorData getSensorData();

void print();

#endif //SENSOR_H
