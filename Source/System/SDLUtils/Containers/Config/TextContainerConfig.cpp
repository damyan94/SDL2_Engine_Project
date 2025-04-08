#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool TextContainerConfig::Read(const LinesOfText& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

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