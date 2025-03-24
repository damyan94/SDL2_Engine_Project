#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "Text";

////////////////////////////////////////////////////////////////////////////////
bool TextContainerConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_TypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_TypeString.c_str());
		return false;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "Type") != c_TypeString);

		TextConfig newCfg;

		auto color = Utils::ReadIntArray(readStrings[i], "Color", 4);
		AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(i), false);

		newCfg.TextColor = Color(color[0], color[1], color[2], color[3]);

		newCfg.StringId = StringId(Utils::ReadInt(readStrings[i], "StringId"));
		newCfg.FontId = FontId(Utils::ReadInt(readStrings[i], "FontId"));

		newCfg.WrapWidth = Utils::ReadInt(readStrings[i], "WrapWidth");
		AssertReturnIf(newCfg.WrapWidth < 0 && _CONFIG_ERROR_INFO(i), false);

		TextContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}