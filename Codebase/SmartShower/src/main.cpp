#include "Thermoactuator/Thermoactuator.h"
#include "Thermometer/Thermometer.h"
#include "Webserver/Webserver.h"
#include "Smart_Shower.h"

//#define PIN_THERMOMETER 12
#define PIN_THERMOACTUATOR 4
int OneTimeRun = 0;
enum statusprogram
{
    SETUP,
    HOT,
    MEDIUM,
    COLD,
    WAIT
};

//dingus

//Thermoactuator *thermoactuator;
//Thermometer *thermometer;
Webserver *webserver;
Shower *shower;
statusprogram  Statusprogram;


void setup()
{
  Serial.begin(115200);
  //thermoactuator = new Thermoactuator(PIN_THERMOACTUATOR);
  //thermometer = new Thermometer(PIN_THERMOMETER);
  webserver = new Webserver();
  shower = new Shower();
}

void loop()
{
  //Serial.print("Temperature: ");
  //Serial.println(thermometer->getTemperature());
  
  //thermoactuator->tick();

  webserver->tick();

  //Serial.print("Alpha: ");
  //Serial.println(webserver->getAlpha());
  //Serial.print("Beta: ");
  //Serial.println(webserver->getBeta());
  if(webserver->getAlpha())
  {
    shower->RunHot();
  }
  else
  {
    shower->reset();
  }

  switch (Statusprogram)
  {
  case SETUP:
    if(!webserver->getAlpha())
    {
      OneTimeRun = 0;
    }
     if(webserver->getAlpha() && OneTimeRun == 0)
     {
      OneTimeRun = 1;
      shower->selectedProgram(PRESSMENU);
      Statusprogram = HOT;
     }
    break;
  case HOT:
      shower->RunHot();
      Statusprogram = MEDIUM;
  break;
  case MEDIUM:
      shower->RunMedium();
      Statusprogram = COLD;
  break;
  case COLD:
      shower->RunCold();
      Statusprogram = SETUP;
  break;
  default:
    break;
  }
}