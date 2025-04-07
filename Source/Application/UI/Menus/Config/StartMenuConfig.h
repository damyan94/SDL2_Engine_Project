#pragma once

#include "System/Components/UI/Config/UIComponentsConfig.h"

struct StartMenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			m_PosRect;

	const ButtonConfig* m_ButtonNewGameConfig;
	const ButtonConfig* m_ButtonSettingsConfig;
	const ButtonConfig* m_ButtonQuitConfig;
};