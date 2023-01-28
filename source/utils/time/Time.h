#ifndef UTILS_TIME_TIME_H_
#define UTILS_TIME_TIME_H_

//#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

// C/C++ system includes
#include <cstdint>
#include <string>
#include <chrono>
#include <ctime>

// Third-party includes

// Own includes

// Forward declarations

namespace TimeConstants
{
	constexpr int64_t SecondsInMinute = 60;
	constexpr int64_t MinutesInHour = 60;
	constexpr int64_t HoursInDay = 24;
	constexpr int64_t DaysInYear = 365;

	constexpr int64_t SecondsInHour = SecondsInMinute * MinutesInHour;
	constexpr int64_t SecondsInDay = SecondsInHour * HoursInDay;
	constexpr int64_t SecondsInYear = SecondsInDay * DaysInYear;

	constexpr int64_t MinutesInDay = MinutesInHour * HoursInDay;
	constexpr int64_t MinutesInYear = MinutesInDay * DaysInYear;

	constexpr int64_t HoursInYear = HoursInDay * DaysInYear;
} // !namespace TimeConstants

enum class UnitsOfTime : uint8_t
{
	Nanoseconds,
	Microseconds,
	Milliseconds,
	Seconds,
	Minutes,
	Hours
};

//typedef std::chrono::steady_clock::time_point TimePoint;

//struct TimePoint
//{
//	TimePoint();
//	~TimePoint();
//
//	static TimePoint GetCurrentTime();
//
//	std::chrono::steady_clock::time_point m_Data;
//};

class Time
{
public:
	Time();
	~Time();

	int64_t GetElapsedTime(UnitsOfTime unit);
	static std::string GetTimeString(time_t t);
	static std::string GetTimeString(std::chrono::system_clock::time_point t);

private:
	//TimePoint m_StartTime;
	//TimePoint m_ElapsedTime;
	std::chrono::steady_clock::time_point m_StartTime;
	std::chrono::steady_clock::time_point m_ElapsedTime;
};

#endif // !UTILS_TIME_TIME_H_