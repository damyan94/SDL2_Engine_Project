#include "stdafx.h"

#include "System/Managers/Config/TimerManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool TimerManagerConfig::Read()
{
	ReturnIf(!TimerContainerConfig.Read(), false);

	return true;
}