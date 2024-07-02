#include "catch_amalgamated.hpp"
#include "alarm.hpp"
#include "sensor.hpp"
#include <stdio.h>


TEST_CASE("default is off", "[require]")
{
    Alarm alarm;
    REQUIRE(!alarm.isAlarmOn());
}

TEST_CASE("activate when below range", "[require]")
{
    Alarm alarm(65535, 100000);
    alarm.check();
    REQUIRE(alarm.isAlarmOn());
}

TEST_CASE("activate when over range", "[require]")
{
    Alarm alarm(0, 0);
    alarm.check();
    REQUIRE(alarm.isAlarmOn());
}
