#pragma once

#include "Application/UI/Menus/Config/StartMenuConfig.h"
#include "Application/UI/Menus/Config/ConsoleMenuConfig.h"
#include "System/Components/UI/Config/UIComponentsConfig.h"

struct MenuManagerConfig
{
	bool				Read(const LinesOfText& line, const UIComponentsConfig& uiComponentsConfig);

	StartMenuConfig		StartMenuConfig;
	ConsoleMenuConfig	ConsoleMenuConfig;
};