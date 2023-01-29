#ifndef UTILS_TIME_TIMEPOINT_H_
#define UTILS_TIME_TIMEPOINT_H_

// C/C++ system includes
#include <cstdint>
#include <chrono>
#include <ctime>

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"

// Forward declarations

class Time
{
public:
	Time();
	~Time();

	uint64_t GetElapsedTime(UnitOfTime unit);
	std::string GetString() const;

	void SetToNow();

private:
	TimePoint GetNow();

private:
	TimePoint m_StartTime;
};

#endif // !UTILS_TIME_TIMEPOINT_H_