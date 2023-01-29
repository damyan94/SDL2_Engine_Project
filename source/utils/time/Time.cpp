// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
Time::Time()
	: m_StartTime(std::chrono::steady_clock::time_point())
{
	SetToNow();
}

// =============================================================================
Time::~Time()
{
}

// =============================================================================
uint64_t Time::GetElapsedTime(UnitsOfTime unit)
{
	const auto duration = GetNow() - m_StartTime;
	//SetToNow();
	uint64_t result = 0;

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
std::string Time::GetString() const
{
	using namespace std::chrono;

	time_t toTimeT = system_clock::to_time_t(system_clock::now() +
		duration_cast<system_clock::duration>(m_StartTime - steady_clock::now()));

	char result[40];
	struct tm* timeinfo = localtime(&toTimeT);
	strftime(result, 40, "%Y.%m.%d %H:%M:%S", timeinfo);

	return std::string(result);
}

// =============================================================================
void Time::SetToNow()
{
	m_StartTime = GetNow();
}

// =============================================================================
TimePoint Time::GetNow()
{
	return std::chrono::steady_clock::now();
}