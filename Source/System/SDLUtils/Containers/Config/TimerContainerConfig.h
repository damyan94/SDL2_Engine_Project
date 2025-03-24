#pragma once

struct TimerConfig
{
};

struct TimerContainerConfig
{
	bool				Read();

	std::vector<TimerConfig> TimerContainerConfig;
};