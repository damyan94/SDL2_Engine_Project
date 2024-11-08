#include "stdafx.h"

#include "system/managers/config/TimerManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool TimerManagerConfig::Read()
{
	ReturnIf(!m_TimerContainerConfig.Read(), false);

	return true;
}