#ifndef SENSOR_H
#define SENSOR_H

struct SensorData {
    float temperature;
    float humidity;
    float pressure;
};

void sensorSetup();
SensorData getSensorData();

void print();

#endif //SENSOR_H
