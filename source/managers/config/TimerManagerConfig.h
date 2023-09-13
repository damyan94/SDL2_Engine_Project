#ifndef MANAGERS_CONFIG_TIMERMANAGERCONFIG_H_
#define MANAGERS_CONFIG_TIMERMANAGERCONFIG_H_

#include "sdl_utils/containers/config/TimerContainerConfig.h"

struct TimerManagerConfig
{
	bool						Read();

	TimerContainerConfig		m_TimerContainerConfig;
};

#endif // !MANAGERS_CONFIG_TIMERMANAGERCONFIG_H_