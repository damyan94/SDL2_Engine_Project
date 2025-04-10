#include "stdafx.h"

#include <chrono>

#include "System/Utils/Time/Time.h"

////////////////////////////////////////////////////////////////////////////////
Time::Time()
	: m_Microseconds(TimePoint(0))
{
	SetToNow();
}

////////////////////////////////////////////////////////////////////////////////
Time::~Time()
{
}

////////////////////////////////////////////////////////////////////////////////
Time::Time(TimePoint ms)
	: m_Microseconds(ms)
{
}

////////////////////////////////////////////////////////////////////////////////
bool Time::operator==(const Time& other) const
{
	return m_Microseconds == other.m_Microseconds;
}

////////////////////////////////////////////////////////////////////////////////
bool Time::operator!=(const Time& other) const
{
	return m_Microseconds != other.m_Microseconds;
}

////////////////////////////////////////////////////////////////////////////////
bool Time::operator>(const Time& other) const
{
	return m_Microseconds > other.m_Microseconds;
}

////////////////////////////////////////////////////////////////////////////////
bool Time::operator<(const Time& other) const
{
	return m_Microseconds < other.m_Microseconds;
}

////////////////////////////////////////////////////////////////////////////////
Time Time::operator+(const Time& other) const
{
	return Time(m_Microseconds + other.m_Microseconds);
}

////////////////////////////////////////////////////////////////////////////////
Time Time::operator-(const Time& other) const
{
	return Time(m_Microseconds - other.m_Microseconds);
}

////////////////////////////////////////////////////////////////////////////////
void Time::SetToNow()
{
	m_Microseconds = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
}

////////////////////////////////////////////////////////////////////////////////
uint64_t Time::GetAs(EUnitOfTime unit) const
{
	using namespace std::chrono;

	const microseconds tp(m_Microseconds);

	switch (unit)
	{
	case EUnitOfTime::Nanosecond:	return duration_cast<nanoseconds>(tp).count();
	case EUnitOfTime::Microsecond:	return duration_cast<microseconds>(tp).count();
	case EUnitOfTime::Millisecond:	return duration_cast<milliseconds>(tp).count();
	case EUnitOfTime::Second:		return duration_cast<seconds>(tp).count();
	case EUnitOfTime::Minute:		return duration_cast<minutes>(tp).count();
	case EUnitOfTime::Hour:			return duration_cast<hours>(tp).count();
	case EUnitOfTime::Day:			return duration_cast<days>(tp).count();
	case EUnitOfTime::Week:			return duration_cast<weeks>(tp).count();
	case EUnitOfTime::Month:		return duration_cast<months>(tp).count();
	case EUnitOfTime::Year:			return duration_cast<years>(tp).count();

	default:
		Assert("Invalid unit of time.");
		return TimePoint();
	}
}

////////////////////////////////////////////////////////////////////////////////
uint64_t Time::GetElapsedTimeUntilNow(EUnitOfTime unit) const
{
	return Time(GetNow() - m_Microseconds).GetAs(unit);
}

////////////////////////////////////////////////////////////////////////////////
std::string Time::GetString(ETimeStringFormat format) const
{
	using namespace std::chrono;

	time_point tp = time_point<system_clock, microseconds>(microseconds(m_Microseconds));

	switch (format)
	{
	case ETimeStringFormat::Default:	return Format("{:%d.%m.%Y %H:%M:%OS}", tp);
	case ETimeStringFormat::Timestamp:	return Format("{:%Y%m%d%H%M%OS}", tp);
	case ETimeStringFormat::TimePoint:	return Format("{}", m_Microseconds);

	default:
		Assert("Invalid time string format.");
		return std::string();
	}
}

////////////////////////////////////////////////////////////////////////////////
Time Time::GetNow()
{
	return Time();
}