#pragma once

#include "application/ui/menus/start_menu/config/StartMenuConfig.h"

struct ConsoleMenuConfig {};

struct MenuManagerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ConsoleMenuConfig	m_ConsoleMenuConfig;
	StartMenuConfig		m_StartMenuConfig;
};