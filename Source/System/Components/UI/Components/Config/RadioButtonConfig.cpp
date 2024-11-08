#include "stdafx.h"

#include "System/Components/UI/Components/Config/RadioButtonConfig.h"

#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "RadioButton";

////////////////////////////////////////////////////////////////////////////////
bool RadioButtonConfig::Read(const ConfigStrings& readStrings, UIComponentId id)
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
		m_TextId	= Utils::ReadInt(readStrings[i], "TextId");
		m_SoundId	= Utils::ReadInt(readStrings[i], "SoundId");

		break;
	}

	return true;
}