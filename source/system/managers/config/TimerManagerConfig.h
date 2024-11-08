#pragma once

#include "system/sdl_utils/containers/config/TimerContainerConfig.h"

struct TimerManagerConfig
{
	bool						Read();

	TimerContainerConfig		m_TimerContainerConfig;
};