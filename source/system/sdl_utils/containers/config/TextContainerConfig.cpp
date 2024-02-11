#include "stdafx.h"

#include "system/sdl_utils/containers/config/TextContainerConfig.h"

static const std::string c_TypeString = "TEXT";

// =============================================================================
bool TextContainerConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_TypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_TypeString.c_str());
		return true;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_TypeString);

		const int32_t id = Utils::ReadStringHashed(readStrings[i], "id").m_Hash;

		TextConfig newCfg;

		auto color = Utils::ReadIntArray(readStrings[i], "color", 4);
		AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(i), false);

		newCfg.m_TextColor = Color(color[0], color[1], color[2], color[3]);

		newCfg.m_FontId = FontId(Utils::ReadStringHashed(readStrings[i], "font_id").m_Hash);

		newCfg.m_WrapWidth = Utils::ReadInt(readStrings[i], "wrap_width");
		AssertReturnIf(newCfg.m_WrapWidth < 0 && _CONFIG_ERROR_INFO(i), false);

		for (int32_t j = (int32_t)ELanguage::Invalid + 1; j < (int32_t)ELanguage::Count; j++)
		{
			const auto currLanguage = ELanguage(j);
			std::string languageString = Utils::ReadString(readStrings[i], Utils::GetLanguageStringFromId(currLanguage));
			AssertReturnIf(languageString.empty() && _CONFIG_ERROR_INFO(i), false);

			newCfg.m_LanguageStrings.emplace(currLanguage, std::move(languageString));
		}

		m_TextContainerConfig.emplace(TextId(id), std::move(newCfg));
	}

	return true;
}