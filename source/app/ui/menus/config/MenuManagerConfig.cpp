#include "stdafx.h"

#include "app/ui/menus/config/MenuManagerConfig.h"

// =============================================================================
bool MenuManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_StartMenuConfig.Read(readStrings), false);

	return true;
}