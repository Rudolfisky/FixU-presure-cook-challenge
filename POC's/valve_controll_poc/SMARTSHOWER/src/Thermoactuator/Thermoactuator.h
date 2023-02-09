#ifndef THERMOACTUATOR_H
#define THERMOACTUATOR_H


#define SENSORTYPE_MOCK false
#define SENSORTYPE_REAL true
#define SENSORTYPE SENSORTYPE_MOCK

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class Thermoactuator
{
    private:
    byte pin;
    uint8_t value;
 
    public:
    Thermoactuator(byte pin);
    void tick();
    void reset();
};

#endif