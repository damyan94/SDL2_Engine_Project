// Corresponding header
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryString = "start_menu";

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

	auto componentsStringIds = Utils::ReadStringArrayHashed(readStrings[startLine], "components_ids", 4);
	std::vector<Hash32> uiComponentsIds;
	for (const auto& component : componentsStringIds)
	{
		uiComponentsIds.emplace_back(component.m_Hash);
	}

	m_ButtonConfig.Read(readStrings, uiComponentsIds[0]);
	m_CheckboxConfig.Read(readStrings, uiComponentsIds[1]);
	m_RadioButtonConfig.Read(readStrings, uiComponentsIds[2]);
	m_TextBoxConfig.Read(readStrings, uiComponentsIds[3]);

	return true;
}