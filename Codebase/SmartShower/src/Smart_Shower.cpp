#include "Smart_Shower.h"
#include <Arduino.h>



Shower::Shower()
{
    ShowerState = STANDBY;
    RunningState = NO_INDICATOR;
    currentModeShower = GREEN_MODE;
    currentmillis = 0;
}
void Shower::HandleEvent(Events event)
{
    switch (ShowerState)
    {
    case STANDBY:
        break;
    case CHANGES_MODE:
        selectedProgram(event);
        break;
    case STARTING:
        Run(event);
        break;
    default:
        break;
    }
}

void Shower::Run(Events event)
{
    switch (RunningState)
    {
    case NO_INDICATOR:
        break;
    case HOT_TEMP:
        RunHot();
        break;
    case MEDIUM_TEMP:
        RunMedium();
        break;
    case COLD_TEMP:
        RunCold();
        break;
    case DONE:
        break;
    default:
        break;
    }
}

void Shower::selectedProgram(Events event)
{
    switch (event)
    {
    case PRESSMENU:
        ShowerMode.SetMode(GREEN_MODE);
        ShowerTimeCold = ShowerMode.GetTimeCold();
        ShowerTimeMedium = ShowerMode.GetTimeMedium();
        ShowerTimeHot = ShowerMode.GetTimeHot();
        Serial.println(ShowerMode.GetTimeCold());
        Serial.println(ShowerMode.GetTimeMedium());
        Serial.println(ShowerMode.GetTimeHot());
        LedSlowDown = 500;
        value = 255;
        break;

    default:
        break;
    }
}

Modes Shower::ChangeMode(Mode mode)
{
    Modes currentMode = mode.GetCurrentMode();

    switch (currentMode)
    {
    case GREEN_MODE:
        Serial.println("GREEN MODE");
        currentMode = RAPID_MODE;
        break;
    case RAPID_MODE:
        Serial.println("RAPID MODE");
        currentMode = MANUAL_MODE;
        break;
    case MANUAL_MODE:
        Serial.println("MANUAL MODE");
        currentMode = GREEN_MODE;
        break;
    default:
        break;
    }

    return currentMode;
}

void Shower::RunHot()
{
    
    currentmillis = millis();
  
    while (ShowerTimeHot != 0)
    {
        if (millis() - currentmillis >= ShowerTimeHot)
        {
            Serial.println("hot done");
            ShowerTimeHot = 0;
        }
      
         if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= TEMPDECREASEVAL;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            Serial.print(F("Temperature = "));
            Serial.println(getTemperature());
            currentmillisLed = millis();
        }
    }
    //RunningState = MEDIUM_TEMP;
}

void Shower::RunMedium()
{
    currentmillis = millis();
    while (ShowerTimeMedium != 0)
    {
        if (millis() - currentmillis >= ShowerTimeMedium) // switch to diffrent mode
        {
            Serial.println("medium done");
            ShowerTimeMedium = 0;
        }

        if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= TEMPDECREASEVAL;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            Serial.print(F("Temperature = "));
            Serial.println(getTemperature());
            currentmillisLed = millis();
        }
    }
    //RunningState = COLD_TEMP;
}

void Shower::RunCold()
{
    currentmillis = millis();
    
    while (ShowerTimeCold != 0)
    {
        if (millis() - currentmillis >= ShowerTimeCold)
        {
            Serial.println("cold done");
            ShowerTimeCold = 0;
        }
         if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= TEMPDECREASEVAL;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            Serial.print(F("Temperature = "));
            Serial.println(getTemperature());
            currentmillisLed = millis();
        }
    }
    //RunningState = DONE;
}

void Shower::reset()
{
    ShowerTimeHot = 0;
}

float Shower::getTemperature()
{
    float temperature = 40;
    temperature -= (255-value)/15;
    return temperature;
    
}