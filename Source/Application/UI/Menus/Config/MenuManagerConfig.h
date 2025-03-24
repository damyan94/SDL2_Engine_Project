#pragma once

#include "Application/UI/Menus/StartMenu/Config/StartMenuConfig.h"

struct ConsoleMenuConfig {};

struct MenuManagerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ConsoleMenuConfig	ConsoleMenuConfig;
	StartMenuConfig		StartMenuConfig;
};