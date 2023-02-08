#include "Thermometer/Thermometer.h"
#include "Webserver/Webserver.h"

#define PIN_THERMOMETER 12


//dingus

Thermometer *thermometer;
Webserver *webserver;


void setup()
{
  Serial.begin(115200);
  thermometer = new Thermometer(PIN_THERMOMETER);
  webserver = new Webserver();
}

void loop()
{
  Serial.print("Temperature: ");
  Serial.println(thermometer->getTemperature());

  webserver->tick();

  Serial.print("Alpha: ");
  Serial.println(webserver->getAlpha());
  Serial.print("Beta: ");
  Serial.println(webserver->getBeta());
}