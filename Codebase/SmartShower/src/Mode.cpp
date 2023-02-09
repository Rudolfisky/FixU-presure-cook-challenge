#include "Mode.h"

void Mode::SetMode(Modes newMode)
{
    modes = newMode;

    switch (newMode)
    {
    case GREEN_MODE:
        TIME_COLD = 0; // is above 30 up to 40
        TIME_MEDIUM = 0; // medium is from 20 up to 30
        TIME_HOT = 5000; // cold is below 20 c
        break;
    case RAPID_MODE:
        TIME_COLD = 0;
        TIME_MEDIUM = 0;
        TIME_HOT = 0;
        break;
    case MANUAL_MODE:
        TIME_COLD = 0;
        TIME_MEDIUM = 0;
        TIME_HOT = 0;
        break;
    default:
        break;
    }
}

unsigned long Mode::GetTimeCold() const
{
    return TIME_COLD;
}

unsigned long Mode::GetTimeMedium() const
{
    return TIME_MEDIUM;
}

unsigned long Mode::GetTimeHot() const
{
    return TIME_HOT;
}

Modes Mode::GetCurrentMode() const
{
    return modes;
}