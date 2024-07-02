#include "alarm.hpp"
#include "sensor.hpp"

Alarm::Alarm(double lpt, double hpt)
{
    sensor = Sensor();
    lowPressureTreshold = lpt;
    highPressureTreshold = hpt;
    alarmOn = false;
}

void Alarm::check()
{
    double psiPressureValue = sensor.popNextPressurePsiValue();

    if (psiPressureValue < lowPressureTreshold || highPressureTreshold < psiPressureValue)
    {
        alarmOn = true;
    }
}

bool Alarm::isAlarmOn()
{
    return alarmOn;
}

//THING

#include "sensor.hpp"

#include <cstdlib>
#include <time.h>

using namespace std;

Sensor::Sensor()
{
    srand((unsigned)time(0));
}

double Sensor::popNextPressurePsiValue()
{
    // placeholder implementation that simulates a real sensor in a real tire
    double pressure = 16 + (float)rand()/((float)RAND_MAX/(6));
    return pressure;
}