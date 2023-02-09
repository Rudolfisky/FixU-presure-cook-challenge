#include "Thermoactuator/Thermoactuator.h"
#include "Thermometer/Thermometer.h"
#include "Webserver/Webserver.h"
#include "Smart_Shower.h"

//#define PIN_THERMOMETER 12
#define PIN_THERMOACTUATOR 4



//dingus

Thermoactuator *thermoactuator;
//Thermometer *thermometer;
Webserver *webserver;
Shower *shower;


void setup()
{
  Serial.begin(115200);
  thermoactuator = new Thermoactuator(PIN_THERMOACTUATOR);
  //thermometer = new Thermometer(PIN_THERMOMETER);
  webserver = new Webserver();
  shower = new Shower();
}

void loop()
{
  //Serial.print("Temperature: ");
  //Serial.println(thermometer->getTemperature());
  shower->RunHot();
  //thermoactuator->tick();

  webserver->tick();

  Serial.print("Alpha: ");
  Serial.println(webserver->getAlpha());
  Serial.print("Beta: ");
  Serial.println(webserver->getBeta());
}