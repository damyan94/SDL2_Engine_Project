#include "stdafx.h"

#include "application/config/AppConfig.h"

// =============================================================================
bool AppConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_MenuManagerConfig.Read(readStrings), false);
	ReturnIf(!m_GameConfig.Read(readStrings), false);

	return true;
}