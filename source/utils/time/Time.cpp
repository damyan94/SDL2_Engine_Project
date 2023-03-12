// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes
#include <chrono>

// Third-party includes

// Own includes
#include "utils/others/CodeReadabilityDefines.h"

using namespace std::chrono;

// =============================================================================
Time::Time()
	: m_StartTime(steady_clock::time_point())
{
	ResetToNow();
}

// =============================================================================
Time::~Time()
{
}

// =============================================================================
uint64_t Time::GetElapsedTimeLastCall(EUnitOfTime unit)
{
	const auto duration = GetNow() - m_StartTime;
	//ResetToNow(); //TODO Consider if this should be here
	uint64_t result = 0;

	switch (unit)
	{
	case EUnitOfTime::Hours:
		return duration_cast<hours>(duration).count();

	case EUnitOfTime::Minutes:
		return duration_cast<minutes>(duration).count();

	case EUnitOfTime::Seconds:
		return duration_cast<seconds>(duration).count();

	case EUnitOfTime::Microseconds:
		return duration_cast<microseconds>(duration).count();

	case EUnitOfTime::Milliseconds:
		return duration_cast<milliseconds>(duration).count();

	case EUnitOfTime::Nanoseconds:
		return duration_cast<nanoseconds>(duration).count();

	default:
		return 0;
	}

	return 0;
}

// =============================================================================
//yyyy.mm.dd HH:mm:ss
std::string Time::GetString() const
{
	time_t toTimeT = system_clock::to_time_t(system_clock::now() +
		duration_cast<system_clock::duration>(m_StartTime - steady_clock::now()));

	constexpr uint8_t resultLength = 19 + 1;
	char result[resultLength];
	tm* timeinfo = localtime(&toTimeT);
	strftime(result, resultLength, "%Y.%m.%d %H:%M:%S", timeinfo);

	return std::string(result);
}

// =============================================================================
//yyyymmddHHmmss
std::string Time::GetStringNumbersOnly() const
{
	time_t toTimeT = system_clock::to_time_t(system_clock::now() +
		duration_cast<system_clock::duration>(m_StartTime - steady_clock::now()));

	constexpr uint8_t resultLength = 14 + 1;
	char result[resultLength];
	tm* timeinfo = localtime(&toTimeT);
	strftime(result, resultLength, "%Y%m%d%H%M%S", timeinfo);

	return std::string(result);
}

// =============================================================================
void Time::ResetToNow()
{
	m_StartTime = GetNow();
}

// =============================================================================
TimePoint Time::GetNow()
{
	return steady_clock::now();
}