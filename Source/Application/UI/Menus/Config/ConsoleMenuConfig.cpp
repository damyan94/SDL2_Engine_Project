#include "stdafx.h"

#include "Application/UI/Menus/Config/ConsoleMenuConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool ConsoleMenuConfig::Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig)
{
	auto posRect = Utils::ReadIntArray(line, "Position", 4);
	//AssertReturnIf(posRect.size() != 4 && _CONFIG_ERROR_INFO(startLine), false);

	m_PosRect = Rectangle(posRect[0], posRect[1], posRect[2], posRect[3]);

	auto type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_1"));
	auto id = Utils::ReadInt(line, "ComponentId_1");
	m_LabelDrawCalls = uiComponentsConfig.GetUIComponentConfig<LabelConfig>(id);

	type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_2"));
	id = Utils::ReadInt(line, "ComponentId_2");
	m_LabelPosition = uiComponentsConfig.GetUIComponentConfig<LabelConfig>(id);

	return true;
}