#include "Smart_Shower.h"
#include <Arduino.h>

int ShowerTimeCold;
int ShowerTimeMedium;
int ShowerTimeHot;
int value;
int pin = 4; // pin led
unsigned long LedSlowDown;
unsigned long currentmillisLed;

Shower::Shower()
{
    ShowerState = STANDBY;
    RunningState = NO_INDICATOR;
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
        RunMedium(event);
        break;
    case COLD_TEMP:
        RunCold(event);
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
        ShowerMode.SetMode(ChangeMode(ShowerMode));
        ShowerTimeCold = ShowerMode.GetTimeCold();
        ShowerTimeMedium = ShowerMode.GetTimeMedium();
        ShowerTimeHot = ShowerMode.GetTimeHot();
        Serial.println(ShowerMode.GetTimeCold());
        Serial.println(ShowerMode.GetTimeMedium());
        Serial.println(ShowerMode.GetTimeHot());
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
    Serial.println("hot");
    currentmillis = millis();

    while (ShowerTimeHot != 0)
    {
        if (millis() - currentmillis >= ShowerTimeHot)
        {
            ShowerTimeHot = 0;
        }
         if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= 10;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            currentmillisLed = millis();
        }
    }
    RunningState = MEDIUM_TEMP;
}

void Shower::RunMedium(Events event)
{
    currentmillis = millis();

    while (ShowerTimeMedium != 0)
    {
        if (millis() - currentmillis >= ShowerTimeMedium) // switch to diffrent mode
        {
            ShowerTimeMedium = 0;
        }

        if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= 10;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            currentmillisLed = millis();
        }
    }
    RunningState = COLD_TEMP;
}

void Shower::RunCold(Events event)
{
    currentmillis = millis();

    while (ShowerTimeCold != 0)
    {
        if (millis() - currentmillis >= ShowerTimeCold)
        {
            ShowerTimeCold = 0;
        }
         if (millis() - currentmillisLed >= LedSlowDown) // lower led
        {
            value -= 10;
            analogWrite(pin, value);
            Serial.print("data: ");
            Serial.println(value);
            currentmillisLed = millis();
        }
    }
    RunningState = DONE;
}