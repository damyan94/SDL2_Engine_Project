#include "stdafx.h"

#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool MenuManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_StartMenuConfig.Read(readStrings), false);

	return true;
}