#include "BM280Sensor.h"
#include <bits/stdc++.h>

BM280Sensor::BM280Sensor(uint8_t adr) {
    sensorObject = new Adafruit_BME280();
    sensorAddress = adr;
}

void BM280Sensor::init(){
    sensorObject->begin(sensorAddress);
}

float BM280Sensor::getTemperature() {
    return sensorObject->readTemperature();
}

float BM280Sensor::getPressure(){
    return sensorObject->readPressure() / 100000;
}

float BM280Sensor::getHumidity(){
    return sensorObject->readHumidity();
}

float BM280Sensor::getCurrentValue() {
    return measurementData.back();
}

void BM280Sensor::setMinValue(){
    if (!measurementData.empty()) {
        float newVal = measurementData.back();
        min = (newVal < min) ? newVal : min;
    }
}

void BM280Sensor::setMaxValue(){
    if (!measurementData.empty()){
        float newVal = measurementData.back();
        max = (newVal > max) ? newVal : max;
    }
}

void BM280Sensor::setAvgValue(){
    if (!measurementData.empty()) {
        uint16_t size = measurementData.size();
        float avgA = std::accumulate(measurementData.begin(), measurementData.end(), 0.0) / size;
        avg = (avg * counter + avgA * size) / (counter + size);
        counter = counter + size;
        if (size > 100) {
            measurementData.erase(measurementData.begin(), measurementData.end()-1);
        }
    }
}

void BM280Sensor::measureByUnit() {
    float measurement;
    if (unit == 't'){
        measurement = getTemperature();
    } else if (unit == 'h'){
        measurement = getHumidity();
    } else if (unit == 'p'){
        measurement = getPressure();
    }
    measurementData.push_back(measurement);
}

void BM280Sensor::measurementUnitChanged() {
    measurementData.clear();
    min = 0.0;
    max = 0.0;
    avg = 0.0;
    counter = 0;
}

void BM280Sensor::setUnit(char newUnit) {
    if (newUnit != unit){
        unit = newUnit;
        measurementUnitChanged();
    }
}

void BM280Sensor::setAllValues() {
    setMinValue();
    setMaxValue();
    setAvgValue();
}
void BM280Sensor::setAvg(float value) {
    avg = value;
    counter++;
}
void BM280Sensor::setAllValuesCurrentMeasurement(){
    float currentMeasurement = measurementData.back();
    min = currentMeasurement;
    max = currentMeasurement;
    setAvg(currentMeasurement);
}