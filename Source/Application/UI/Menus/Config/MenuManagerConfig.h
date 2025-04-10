#pragma once

#include "System/Components/UI/Config/UIComponentsConfig.h"

struct MenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			PosRect;

	std::vector<const IUIComponentConfig*> ComponentsConfig;
};

struct MenuManagerConfig
{
	bool				Read(const LinesOfText& line, const UIComponentsConfig& uiComponentsConfig);

	std::vector<MenuConfig> MenuConfigs;
};