#include "Thermoactuator.h"

Thermoactuator::Thermoactuator(byte pin)
{
    Serial.println(F("Thermoactuator Starting"));

    this->pin = pin;
    pinMode(this->pin, OUTPUT);

    Serial.println(F("Thermoactuator Started"));
}

void Thermoactuator::tick()
{
    if(value > 0)
    {
    value--;
    delay(10);
    }
    else
    {
        reset(); //remove this
    }
    analogWrite(pin, value);
    Serial.print("data: ");
    Serial.println(value);
}

void Thermoactuator::reset()
{
    value = 150;
}