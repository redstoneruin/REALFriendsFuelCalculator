#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    bool isTimed;
    int raceTime, raceLaps;
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
