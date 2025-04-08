#include "stdafx.h"

#include "Application/Game/Config/GameConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool GameConfig::Read()
{
	ReturnIf(!UIComponentsConfig.Read(), false);
	ReturnIf(!MenuManagerConfig.Read(File(ConfigFilePaths::MenuConfig).GetFileContents(), UIComponentsConfig), false);
	ReturnIf(!GameManagerConfig.Read(), false);

	return true;
}