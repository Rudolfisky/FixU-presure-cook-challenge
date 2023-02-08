#ifndef Smart_Shower_H
#define Smart_Shower_H

#include "Events.h"
#include "States.h"
#include "Running.h"
#include "Mode.h"

unsigned long currentmillis = 0;

class shower
{
public:
    shower();
    void HandleEvent(Events event);
    void Run(Events event);
    Modes ChangeMode(Mode mode);
    void selectedProgram(Events event);

    void RunHot(Events event);
    void RunMedium(Events event);
    void RunCold(Events event);

private:
    States ShowerState;
    Runningstate RunningState;
    Mode ShowerMode;
    
};

#endif