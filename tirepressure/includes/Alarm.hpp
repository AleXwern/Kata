#pragma once
#include "sensor.hpp"

using namespace std;

class Alarm
{
public:
    Alarm(double lpt = 17, double hpt = 21);
    void check();
    bool isAlarmOn();

protected:
    Sensor sensor;
    double lowPressureTreshold;
    double highPressureTreshold;
    bool alarmOn;
};

