#ifndef Smart_Shower_H
#define Smart_Shower_H

#include <Arduino.h>
#include "Events.h"
#include "States.h"
#include "Running.h"
#include "Mode.h"

#define TEMPDECREASEVAL 7



class Shower
{
public:
    Shower();
    void HandleEvent(Events event);
    void Run(Events event);
    Modes ChangeMode(Mode mode);
    void selectedProgram(Events event);

    void RunHot();
    void RunMedium();
    void RunCold();
    void reset();

private:
    States ShowerState;
    Runningstate RunningState;
    Mode ShowerMode;
    Modes currentModeShower;
    unsigned long currentmillis;
    int ShowerTimeCold;
    int ShowerTimeMedium;
    int ShowerTimeHot;
    uint8_t value;
    int pin = 4; // pin led
    unsigned long LedSlowDown;
    unsigned long currentmillisLed;
    float getTemperature();
    
};

#endif