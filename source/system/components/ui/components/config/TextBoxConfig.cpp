#include "stdafx.h"

#include "System/Components/UI/Components/Config/TextBoxConfig.h"

#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "Textbox";

////////////////////////////////////////////////////////////////////////////////
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
		BreakIf(Utils::ReadString(readStrings[i], "Type") != c_TypeString);
		ContinueIf(Utils::ReadInt(readStrings[i], "Id") != id);

		const auto& pos = Utils::ReadIntArray(readStrings[i], "Position", 2);
		AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
		m_Pos = Point(pos[0], pos[1]);

		m_ImageId	= Utils::ReadInt(readStrings[i], "ImageId");

		m_MaxChars	= Utils::ReadInt(readStrings[i], "MaximumChars");
		AssertReturnIf(m_MaxChars <= 0 && _CONFIG_ERROR_INFO(i), false);

		m_FontId	= FontId(Utils::ReadInt(readStrings[i], "FontId"));

		const auto& color = Utils::ReadIntArray(readStrings[i], "TextColor", 4);
		AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(i), false);
		m_TextColor = Color(color[0], color[1], color[2], color[3]);

		break;
	}

	return true;
}