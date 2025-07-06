#include "stdafx.h"

#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool MenuManagerConfig::Read(const StringVector& lines, const UIComponentsConfig& uiComponentsConfig)
{
	for (const auto& line : lines)
	{
		MenuConfigs.emplace_back();
		ReturnIf(!MenuConfigs.back().Read(line, uiComponentsConfig), false);
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool MenuConfig::Read(const std::string& line, const UIComponentsConfig& uiComponentsConfig)
{
	auto posRect = Utils::ReadIntArray(line, "Position", 4);
	//AssertReturnIf(posRect.size() != 4 && _CONFIG_ERROR_INFO(startLine), false);

	PosRect = Rectangle(posRect[0], posRect[1], posRect[2], posRect[3]);

	EUIComponentType type = EUIComponentType::Invalid;
	int32_t id = -1;

	auto pos = line.find_last_of("ComponentId_") + 1;
	AssertReturnIf(pos == std::string::npos, false);
	std::string countString;
	while (line[pos] >= '0' && line[pos] <= '9')
	{
		countString += line[pos];
		pos++;
	}
	const auto count = std::stoi(countString);

	for (int32_t i = 0; i < count; i++)
	{
		type = GetUIComponentTypeFromString(Utils::ReadString(line, "ComponentType_" + std::to_string(i + 1)));
		id = Utils::ReadInt(line, "ComponentId_" + std::to_string(i + 1));
		ComponentsConfig.push_back(uiComponentsConfig.GetUIComponentConfig(type, id));
	}

	return true;
}