#ifndef UTILS_TIME_TIME_H_
#define UTILS_TIME_TIME_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/Defines.h"

// Forward declarations

class Time
{
public:
	Time();
	~Time();

	void				SetToNow();

	uint64_t			GetAs(EUnitOfTime unit) const;
	uint64_t			GetElapsedTimeTillNow(EUnitOfTime unit) const;
	std::string			GetString(ETimeStringFormat format) const;
	String				GetWString(ETimeStringFormat format) const;

public:
	//Time since 1.1.1970 00:00:00 in microseconds
	static Time			GetNow();

private:
	TimePoint			m_Microseconds;
};

#endif // !UTILS_TIME_TIME_H_