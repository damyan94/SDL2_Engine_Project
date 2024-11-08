#include "stdafx.h"

#include "application/ui/menus/start_menu/config/StartMenuConfig.h"

static const std::string c_CategoryString = "Menu";

////////////////////////////////////////////////////////////////////////////////
bool StartMenuConfig::Read(const ConfigStrings& readStrings)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryString.c_str());
		return true;
	}

	/*for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_CategoryTypeString);

	}*/
	auto posRect = Utils::ReadIntArray(readStrings[startLine], "Position", 4);
	AssertReturnIf(posRect.size() != 4 && _CONFIG_ERROR_INFO(startLine), false);

	m_PosRect = Rectangle(posRect[0], posRect[1], posRect[2], posRect[3]);

	auto componentsStringIds = Utils::ReadIntArray(readStrings[startLine], "ComponentIds", 3);
	AssertReturnIf(componentsStringIds.size() != 3 && _CONFIG_ERROR_INFO(startLine), false);

	m_ButtonNewGameConfig.Read(readStrings, componentsStringIds[0]);
	m_ButtonSettingsConfig.Read(readStrings, componentsStringIds[1]);
	m_ButtonQuitConfig.Read(readStrings, componentsStringIds[2]);

	return true;
}