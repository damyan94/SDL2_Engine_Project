// Corresponding header
#include "utils/UtilsDefines.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

namespace UtilsConstants
{
const int64_t TimeSecondsInMinute		= 60;
const int64_t TimeMinutesInHour			= 60;
const int64_t TimeHoursInDay			= 24;
const int64_t TimeDaysInYear			= 365;

const int64_t TimeSecondsInHour			= TimeSecondsInMinute * TimeMinutesInHour;
const int64_t TimeSecondsInDay			= TimeSecondsInHour * TimeHoursInDay;
const int64_t TimeSecondsInYear			= TimeSecondsInDay * TimeDaysInYear;

const int64_t TimeMinutesInDay			= TimeMinutesInHour * TimeHoursInDay;
const int64_t TimeMinutesInYear			= TimeMinutesInDay * TimeDaysInYear;

const int64_t TimeHoursInYear			= TimeHoursInDay * TimeDaysInYear;

const int64_t TimerMinInterval			= 20;
} // !namespace UtilsConstants