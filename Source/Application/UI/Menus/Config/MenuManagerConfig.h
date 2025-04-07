#pragma once

#include "Application/UI/Menus/Config/StartMenuConfig.h"
#include "System/Components/UI/Config/UIComponentsConfig.h"

struct ConsoleMenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			m_PosRect;

	const LabelConfig* m_LabelDrawCalls;
	const LabelConfig* m_LabelPosition;
};

struct MenuManagerConfig
{
	bool				Read(const ConfigStrings& line, const UIComponentsConfig& uiComponentsConfig);

	ConsoleMenuConfig	ConsoleMenuConfig;
	StartMenuConfig		StartMenuConfig;
};