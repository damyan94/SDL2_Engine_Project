#include "stdafx.h"

#include "Application/UI/Menus/StartMenu/Config/StartMenuConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool StartMenuConfig::Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig)
{
	auto posRect = Utils::ReadIntArray(line, "Position", 4);
	//AssertReturnIf(posRect.size() != 4 && _CONFIG_ERROR_INFO(startLine), false);

	m_PosRect = Rectangle(posRect[0], posRect[1], posRect[2], posRect[3]);

	auto type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_1"));
	auto id = Utils::ReadInt(line, "ComponentId_1");
	m_ButtonNewGameConfig = uiComponentsConfig.GetUIComponentConfig(type, id);

	type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_2"));
	id = Utils::ReadInt(line, "ComponentId_2");
	m_ButtonSettingsConfig = uiComponentsConfig.GetUIComponentConfig(type, id);

	type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_3"));
	id = Utils::ReadInt(line, "ComponentId_3");
	m_ButtonQuitConfig = uiComponentsConfig.GetUIComponentConfig(type, id);

	return true;
}