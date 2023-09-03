#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include "utils.h"

#define NUM_SECs_IN_HOUR	60 * 60
#define NUM_SECs_IN_DAY		24 * 60 * 60
#define NUM_SECs_IN_MONTH	30 * 24 * 60 * 60
#define NUM_SECs_IN_YEAR	365 * 24 * 60 * 60

struct RawObject
{
    RawObject(std::string _name, double _x, double _y, std::string _type, time_t _time_elapsed)
    {
        name = _name;
        x = _x;
        y = _y;
        type = _type;
        time_elapsed = _time_elapsed;
    }
    std::string name;
    double x;
    double y;
    std::string type;
    time_t time_elapsed;
};