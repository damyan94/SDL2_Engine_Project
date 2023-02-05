// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
Time::Time()
	: m_StartTime(std::chrono::steady_clock::time_point())
{
	ResetToNow();
}

// =============================================================================
Time::~Time()
{
}

// =============================================================================
uint64_t Time::GetElapsedTime(EUnitOfTime unit)
{
	const auto duration = GetNow() - m_StartTime;
	//ResetToNow(); //TODO Consider if this should be here
	uint64_t result = 0;

	switch (unit)
	{
	case EUnitOfTime::Hours:
		return std::chrono::duration_cast<std::chrono::hours>(duration).count();

	case EUnitOfTime::Minutes:
		return std::chrono::duration_cast<std::chrono::minutes>(duration).count();

	case EUnitOfTime::Seconds:
		return std::chrono::duration_cast<std::chrono::seconds>(duration).count();

	case EUnitOfTime::Microseconds:
		return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();

	case EUnitOfTime::Milliseconds:
		return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

	case EUnitOfTime::Nanoseconds:
		return std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

	default:
		return 0;
	}

	return 0;
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
void Time::ResetToNow()
{
	m_StartTime = GetNow();
}

// =============================================================================
TimePoint Time::GetNow()
{
	return std::chrono::steady_clock::now();
}