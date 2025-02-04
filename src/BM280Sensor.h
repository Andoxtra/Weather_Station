#ifndef WEATHERSTATION_BM280SENSOR_H
#define WEATHERSTATION_BM280SENSOR_H

#include <vector>
#include <algorithm>
#include "Adafruit_BME280.h"

#include "helper.h"

class BM280Sensor {
private:
    Adafruit_BME280* sensorObject;
    ~BM280Sensor(){delete sensorObject;};
    uint8_t sensorAddress{};
    char unit{};
    float min{};
    float max{};
    float avg{};
    uint64_t counter = 0;
    std::vector<float> measurementData;
    void setMinValue();
    void setMaxValue();
    void setAvgValue();
    void setAvg(float value);
    void measurementUnitChanged();
public:
    explicit BM280Sensor(uint8_t adr);
    float getHumidity();
    float getTemperature();
    float getPressure();
    float getMinValue() const{return min;};
    float getMaxValue() const{return max;};
    float getAvgValue() const{return avg;};
    float getCurrentValue();
    void measureByUnit();
    void setUnit(char newUnit);
    void setAllValues();
    void setAllValuesCurrentMeasurement();
    void init();
};


#endif //WEATHERSTATION_BM280SENSOR_H
