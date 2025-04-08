#include "stdafx.h"

#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool MenuManagerConfig::Read(const LinesOfText& line, const UIComponentsConfig& uiComponentsConfig)
{
	ReturnIf(!StartMenuConfig.Read(line[0], uiComponentsConfig), false);
	ReturnIf(!ConsoleMenuConfig.Read(line[1], uiComponentsConfig), false);

	return true;
}