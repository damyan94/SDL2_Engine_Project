#include "stdafx.h"

#include "application/ui/menus/start_menu/config/StartMenuConfig.h"

static const std::string c_CategoryString = "MENU";

// =============================================================================
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
	auto posRect = Utils::ReadIntArray(readStrings[startLine], "position", 4);
	AssertReturnIf(posRect.size() != 4, false, _CONFIG_ERROR_INFO(startLine));

	m_PosRect = Rectangle(posRect[0], posRect[1], posRect[2], posRect[3]);

	auto componentsStringIds = Utils::ReadStringArrayHashed(readStrings[startLine], "components_ids", 3);
	AssertReturnIf(componentsStringIds.size() != 3, false, _CONFIG_ERROR_INFO(startLine));

	m_ButtonNewGameConfig.Read(readStrings, componentsStringIds[0].m_Hash);
	m_ButtonSettingsConfig.Read(readStrings, componentsStringIds[1].m_Hash);
	m_ButtonQuitConfig.Read(readStrings, componentsStringIds[2].m_Hash);

	return true;
}