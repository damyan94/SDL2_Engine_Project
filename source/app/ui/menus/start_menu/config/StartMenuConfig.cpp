// Corresponding header
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryString = "menu";

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

	auto componentsStringIds = Utils::ReadStringArrayHashed(readStrings[startLine], "components_ids", 4);

	m_ButtonConfig.Read(readStrings, componentsStringIds[0].m_Hash);
	m_CheckboxConfig.Read(readStrings, componentsStringIds[1].m_Hash);
	m_RadioButtonConfig.Read(readStrings, componentsStringIds[2].m_Hash);
	m_TextBoxConfig.Read(readStrings, componentsStringIds[3].m_Hash);

	return true;
}