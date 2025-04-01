#include "stdafx.h"

#include "Application/Game/Config/GameConfig.h"
#include "System/Components/UI/Components/Config/UIComponentsConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool GameConfig::Read()
{
	//TODO fix
	static UIComponentsConfig cfg;
	cfg.Read();

	ReturnIf(!MenuManagerConfig.Read(File(ConfigFilePaths::MenuConfig).GetFileContents(), cfg), false);
	ReturnIf(!GameManagerConfig.Read(), false);

	return true;
}