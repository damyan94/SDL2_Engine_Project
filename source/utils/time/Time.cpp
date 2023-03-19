// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes
#include <chrono>

// Third-party includes

// Own includes

// =============================================================================
Time::Time()
	: m_Microseconds(TimePoint(0))
{
	SetToNow();
}

// =============================================================================
Time::~Time()
{
}

// =============================================================================
void Time::SetToNow()
{
	m_Microseconds = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
}

// =============================================================================
uint64_t Time::GetAs(EUnitOfTime unit) const
{
	std::chrono::microseconds microSeconds(m_Microseconds);

	switch (unit)
	{
	case EUnitOfTime::Nanoseconds:
		return std::chrono::duration_cast<std::chrono::nanoseconds>(microSeconds).count();

	case EUnitOfTime::Microseconds:
		return std::chrono::duration_cast<std::chrono::microseconds>(microSeconds).count();

	case EUnitOfTime::Milliseconds:
		return std::chrono::duration_cast<std::chrono::milliseconds>(microSeconds).count();

	case EUnitOfTime::Seconds:
		return std::chrono::duration_cast<std::chrono::seconds>(microSeconds).count();

	case EUnitOfTime::Minutes:
		return std::chrono::duration_cast<std::chrono::minutes>(microSeconds).count();

	case EUnitOfTime::Hours:
		return std::chrono::duration_cast<std::chrono::hours>(microSeconds).count();

	case EUnitOfTime::Days:
		return std::chrono::duration_cast<std::chrono::days>(microSeconds).count();

	default:
		return 0;
	}
}

// =============================================================================
uint64_t Time::GetElapsedTimeTillNow(EUnitOfTime unit) const
{
	return Time::GetNow().GetAs(unit) - GetAs(unit);
}

// =============================================================================
std::string Time::GetString(ETimeStringFormat format) const
{
	time_t timeSeconds = m_Microseconds / 1000 / 1000;

	constexpr uint8_t resultLength = 40;
	char result[resultLength]{'\0'};
	tm* timeinfo = localtime(&timeSeconds);

	switch (format)
	{
	case ETimeStringFormat::yyyymmddHHmmss_ZeroPunctuation:
		strftime(result, resultLength, "%Y%m%d%H%M%S", timeinfo);
		break;

	case ETimeStringFormat::yyyymmddHHmmss_Dots:
		strftime(result, resultLength, "%Y.%m.%d %H:%M:%S", timeinfo);
		break;

	case ETimeStringFormat::ddmmyyyyHHmmss_ZeroPunctuation:
		strftime(result, resultLength, "%d%m%Y%H%M%S", timeinfo);
		break;

	case ETimeStringFormat::ddmmyyyyHHmmss_Dots:
		strftime(result, resultLength, "%d.%m.%Y %H:%M:%S", timeinfo);
		break;

	default:
		break;
	}

	return std::string(result);
}

// =============================================================================
String Time::GetWString(ETimeStringFormat format) const
{
	std::string temp = GetString(format);
	return std::wstring(temp.begin(), temp.end());
}

// =============================================================================
Time Time::GetNow()
{
	return Time();
}