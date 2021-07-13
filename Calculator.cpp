#include <QtMath>
#include "Calculator.h"

Calculator::Calculator() : isTimed(true),
    raceTime(0),
    raceLaps(0),
    maxFuel(0),
    usage(0),
    lapTime(0)
{

}


int Calculator::getNumLaps()
{
    if(!isTimed) return raceLaps;

    return qCeil(raceTime * 60 / lapTime);
}


float Calculator::getRaceTime()
{
    if(isTimed) return raceTime;

    return (raceLaps * lapTime) / 60;
}


float Calculator::getLapsPerTank()
{
    return maxFuel / usage;
}


float Calculator::getTotalFuel()
{
    return usage * getNumLaps();
}

int Calculator::getNumStops()
{
    return qCeil((getTotalFuel() - maxFuel) / maxFuel);
}

float Calculator::getFuelOnStop()
{
    if(getNumStops()) {
        float calc = getTotalFuel() - (getNumStops()) * (getLapsPerTank()*usage);
        return calc;
    } else {
        return getTotalFuel();
    }
}
