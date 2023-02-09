#ifndef Mode_H
#define mode_H

enum Modes
{
    GREEN_MODE,
    RAPID_MODE,
    MANUAL_MODE
};

class Mode
{
private:
    Modes modes;
    unsigned long TIME_COLD;
    unsigned long TIME_MEDIUM;
    unsigned long TIME_HOT;

public:
    void SetMode(Modes newMode);
    Modes GetCurrentMode() const;

    unsigned long GetTimeCold() const;
    unsigned long GetTimeMedium() const;
    unsigned long GetTimeHot() const;
};

#endif