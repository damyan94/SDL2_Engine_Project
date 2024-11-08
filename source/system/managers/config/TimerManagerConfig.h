#pragma once

#include "System/SDLUtils/Containers/Config/TimerContainerConfig.h"

struct TimerManagerConfig
{
	bool						Read();

	TimerContainerConfig		m_TimerContainerConfig;
};