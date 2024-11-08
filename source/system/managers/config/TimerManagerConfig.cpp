#include "stdafx.h"

#include "System/Managers/Config/TimerManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool TimerManagerConfig::Read()
{
	ReturnIf(!m_TimerContainerConfig.Read(), false);

	return true;
}