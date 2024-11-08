#include "stdafx.h"

#include "application/Game/config/GameConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool GameConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_MenuManagerConfig.Read(readStrings), false);
	ReturnIf(!m_GameConfig.Read(readStrings), false);

	return true;
}