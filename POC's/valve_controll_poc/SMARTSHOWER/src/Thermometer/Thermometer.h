#ifndef THERMOMETER_H
#define THERMOMETER_H


#define SENSORTYPE_MOCK false
#define SENSORTYPE_REAL true
#define SENSORTYPE SENSORTYPE_MOCK

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class Thermometer
{
    private:
    byte pin;
    OneWire *oneWire;
    DallasTemperature *tempSensor;
 
    public:
    Thermometer(byte pin);
    float getTemperature();
};

#endif