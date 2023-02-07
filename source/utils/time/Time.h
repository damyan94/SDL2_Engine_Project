#ifndef UTILS_TIME_TIMEPOINT_H_
#define UTILS_TIME_TIMEPOINT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"

// Forward declarations

class Time
{
public:
	Time();
	~Time();

	uint64_t			GetElapsedTime(EUnitOfTime unit);
	std::string			GetString() const;

	void				ResetToNow();

private:
	TimePoint			GetNow();

private:
	TimePoint			m_StartTime;
};

#endif // !UTILS_TIME_TIMEPOINT_H_