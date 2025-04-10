#include "stdafx.h"

#include "Application/Application/Config/ApplicationConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ApplicationConfig::Read()
{
	//TODO maybe this has to be fixed?
	ReturnIf(!DrawManagerConfig.Read(File(ConfigFilePaths::SystemConfig).GetLines()), false);

	ReturnIf(!AssetManagerConfig.Read(), false);
	ReturnIf(!AudioManagerConfig.Read(), false);
	ReturnIf(!TimerManagerConfig.Read(), false);
	ReturnIf(!ImGuiManagerConfig.Read(), false);

	ReturnIf(!GameConfig.Read(), false);

	return true;
}