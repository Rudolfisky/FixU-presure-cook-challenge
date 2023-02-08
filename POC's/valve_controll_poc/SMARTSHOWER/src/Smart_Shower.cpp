#include "Smart_Shower.h"
#include <Arduino.h>

 int ShowerTimeCold;
 int ShowerTimeMedium;
 int ShowerTimeHot;

shower::shower()
{
    ShowerState = STANDBY;
    RunningState = NO_INDICATOR;
}
void shower::HandleEvent(Events event)
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

void shower::Run(Events event)
{
    switch(RunningState)
    {
    case NO_INDICATOR:
        break;
    case HOT_TEMP:
        RunHot(event);
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

void shower::selectedProgram(Events event)
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

Modes shower::ChangeMode(Mode mode)
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

void shower::RunHot(Events event)
{
    currentmillis = millis();

    while(ShowerTimeHot != 0)
    {
        if(millis() - currentmillis >= ShowerTimeHot)
        {
            ShowerTimeHot = 0;
        }
    }
    RunningState = MEDIUM_TEMP;
}

void shower::RunMedium(Events event)
{
    currentmillis = millis();

    while(ShowerTimeMedium != 0)
    {
        if(millis() - currentmillis >= ShowerTimeMedium)
        {
            ShowerTimeMedium = 0;
        }
    }
    RunningState = COLD_TEMP;
}

void shower::RunCold(Events event)
{
    currentmillis = millis();

    while(ShowerTimeCold != 0)
    {
        if(millis() - currentmillis >= ShowerTimeCold)
        {
            ShowerTimeCold = 0;
        }
    }
    RunningState = DONE;
}