#include "stdafx.h"

#include "system/components/ui/components/config/TextBoxConfig.h"

#include "system/defines/ConfigFilePaths.h"

static const std::string c_TypeString = "TEXTBOX";

// =============================================================================
bool TextBoxConfig::Read(const ConfigStrings& readStrings, UIComponentId id)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_TypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_TypeString.c_str());
		return true;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_TypeString);
		ContinueIf(Utils::ReadStringHashed(readStrings[i], "id").m_Hash != id);

		const auto& pos = Utils::ReadIntArray(readStrings[i], "position", 2);
		AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
		m_Pos = Point(pos[0], pos[1]);

		m_ImageId	= Utils::ReadStringHashed(readStrings[i], "image_id").m_Hash;

		m_MaxChars	= Utils::ReadInt(readStrings[i], "max_chars");
		AssertReturnIf(m_MaxChars <= 0 && _CONFIG_ERROR_INFO(i), false);

		m_FontId	= FontId(Utils::ReadStringHashed(readStrings[i], "font_id").m_Hash);

		const auto& color = Utils::ReadIntArray(readStrings[i], "text_color", 4);
		AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(i), false);
		m_TextColor = Color(color[0], color[1], color[2], color[3]);

		break;
	}

	return true;
}