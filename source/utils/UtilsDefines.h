#ifndef UTILS_UTILS_DEFINES_H_
#define UTILS_UTILS_DEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <chrono>

// Third-party includes

// Own includes

// Forward declarations

// ================================= TYPEDEFS ==================================

typedef std::chrono::steady_clock::time_point		TimePoint;
typedef int32_t										TimerId;

// =============================== ENUMERATIONS ================================

enum class UnitOfTime : int8_t
{
	Invalid = -1
	, Nanoseconds
	, Microseconds
	, Milliseconds
	, Seconds
	, Minutes
	, Hours
	, Count
};

enum class TimerType : int8_t
{
	Invalid = -1
	, OneShot
	, Pulse
	, Count
};

enum class ConsoleTextColor : uint16_t
{
	Default		= 37
	, Black		= 90
	, Red		= 91
	, Green		= 92
	, Yellow	= 93
	, Blue		= 94
	, Magenta	= 95
	, Cyan		= 96
	, White		= 97
};

// ================================= CONSTANTS =================================

namespace UtilsConstants
{
extern const int64_t TimeSecondsInMinute;
extern const int64_t TimeMinutesInHour;
extern const int64_t TimeHoursInDay;
extern const int64_t TimeDaysInYear;

extern const int64_t TimeSecondsInHour;
extern const int64_t TimeSecondsInDay;
extern const int64_t TimeSecondsInYear;
	  
extern const int64_t TimeMinutesInDay;
extern const int64_t TimeMinutesInYear;
	  
extern const int64_t TimeHoursInYear;
	  
extern const int64_t TimerMinInterval;
} // !namespace UtilsConstants

#endif // !UTILS_UTILS_DEFINES_H_