#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    bool isTimed, hasPaceLap;
    int raceTime, raceLaps, extraLaps;
    float maxFuel, usage, lapTime;

    Calculator();

    int getNumLaps();
    float getRaceTime();
    float getLapsPerTank();
    float getTotalFuel();
    int getNumStops();
    float getFuelOnStop();

};

#endif // CALCULATOR_H
