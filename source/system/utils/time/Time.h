#pragma once

class Time
{
public:
	Time();
	~Time();

private:
	Time(TimePoint ms);

public:
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;

	Time operator+(const Time& other) const;
	Time operator-(const Time& other) const;

	void				SetToNow();

	uint64_t			GetAs(EUnitOfTime unit) const;
	uint64_t			GetElapsedTimeTillNow(EUnitOfTime unit) const;
	std::string			GetString(ETimeStringFormat format) const;

public:
	//Time since 1.1.1970 00:00:00 in microseconds
	static Time			GetNow();

private:
	TimePoint			m_Microseconds;
};