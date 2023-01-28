// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
Time::Time()
	: m_StartTime(std::chrono::steady_clock::now())
	, m_ElapsedTime(std::chrono::steady_clock::now())
{
}

// =============================================================================
Time::~Time()
{
}

// =============================================================================
int64_t Time::GetElapsedTime(UnitsOfTime unit)
{
	m_ElapsedTime = m_StartTime;
	m_StartTime = std::chrono::steady_clock::now();
	const auto duration = m_StartTime - m_ElapsedTime;

	int64_t result = 0;

	switch (unit)
	{
	case UnitsOfTime::Hours:
		result = std::chrono::duration_cast<std::chrono::hours>(duration).count();
		break;

	case UnitsOfTime::Minutes:
		result = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
		break;

	case UnitsOfTime::Seconds:
		result = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
		break;

	case UnitsOfTime::Microseconds:
		result = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
		break;

	case UnitsOfTime::Milliseconds:
		result = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		break;

	case UnitsOfTime::Nanoseconds:
		result = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
		break;

	default:
		break;
	}

	return result;
}

// =============================================================================
//dd.mm.yyyy HH:mm:ss
std::string Time::GetTimeString(time_t t)
{
	char result[80];
	struct tm* timeinfo = localtime(&t);
	strftime(result, 80, "%Y.%m.%d %H:%M:%S", timeinfo);

	return result;
}

// =============================================================================
//dd.mm.yyyy HH:mm:ss
std::string Time::GetTimeString(std::chrono::system_clock::time_point t)
{
	time_t toTime_t = std::chrono::system_clock::to_time_t(t);

	return GetTimeString(toTime_t);
}

//TimePoint::TimePoint()
//{
//}
//
//TimePoint::~TimePoint()
//{
//}
//
//TimePoint TimePoint::GetCurrentTime()
//{
//	return TimePoint();
//}