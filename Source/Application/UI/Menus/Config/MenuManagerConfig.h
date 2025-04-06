#pragma once

#include "Application/UI/Menus/StartMenu/Config/StartMenuConfig.h"
#include "System/Components/UI/Components/Config/UIComponentsConfig.h"

struct ConsoleMenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			m_PosRect;

	const IUIComponentConfig* m_LabelDrawCalls;
	const IUIComponentConfig* m_LabelPosition;
};

struct MenuManagerConfig
{
	bool				Read(const LinesOfText& line, const UIComponentsConfig& uiComponentsConfig);

	ConsoleMenuConfig	ConsoleMenuConfig;
	StartMenuConfig		StartMenuConfig;
};