#include "stdafx.h"

#include "Application/Game/Config/GameConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool GameConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!MenuManagerConfig.Read(readStrings), false);
	ReturnIf(!GameManagerConfig.Read(readStrings), false);

	return true;
}