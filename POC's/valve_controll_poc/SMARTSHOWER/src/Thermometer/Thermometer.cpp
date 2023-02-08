#include "Thermometer.h"

Thermometer::Thermometer(byte pin)
{
    Serial.println(F("Thermosensor Starting"));
    this->pin = pin;
    pinMode(this->pin, INPUT);

    oneWire = new OneWire(pin);  
    tempSensor = new DallasTemperature(oneWire);

    tempSensor->begin();    // initialize the sensor

    Serial.println(F("Thermosensor Started"));
}

float Thermometer::getTemperature()
{
    tempSensor->requestTemperatures();             // send the command to get temperatures
    float tempCelsius = tempSensor->getTempCByIndex(0);  // read temperature in Celsius

    Serial.print(F("Temperature: "));
    Serial.print(tempCelsius);    // print the temperature in Celsius
    Serial.println(F("°C"));

    return tempCelsius;
}


