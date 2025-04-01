#pragma once

#include "System/Components/UI/Components/Config/UIComponentsConfig.h"

struct StartMenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			m_PosRect;

	const IUIComponentConfig* m_ButtonNewGameConfig;
	const IUIComponentConfig* m_ButtonSettingsConfig;
	const IUIComponentConfig* m_ButtonQuitConfig;
};