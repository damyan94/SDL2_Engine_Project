#pragma once

#include "System/Components/UI/Config/UIComponentsConfig.h"

struct ConsoleMenuConfig
{
	bool				Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig);

	Rectangle			m_PosRect;

	const LabelConfig* m_LabelDrawCalls;
	const LabelConfig* m_LabelPosition;
};