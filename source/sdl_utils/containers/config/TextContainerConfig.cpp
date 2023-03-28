// Corresponding header
#include "sdl_utils/containers/config/TextContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "text";

// =============================================================================
bool TextContainerConfig::Read(const ConfigStrings& readStrings)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size() - 1)
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	std::string language = "bg";//Utils::ReadString(readStrings[0], L"language");

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_CategoryTypeString);

		const int32_t id = Utils::ReadInt(readStrings[i], "id");

		TextConfig newCfg;

		newCfg.m_String = Utils::ReadString(readStrings[i], language);
		AssertReturnIf(newCfg.m_String.empty(), false, _CONFIG_ERROR_INFO(i));

		auto color = Utils::ReadIntArray(readStrings[i], "color", 4);
		AssertReturnIf(color.size() != 4, false, _CONFIG_ERROR_INFO(i));

		newCfg.m_TextColor = Color(color[0], color[1], color[2], color[3]);

		newCfg.m_FontId = FontId(Utils::ReadInt(readStrings[i], "font_id"));
		AssertReturnIf(!IsResourceIdValid(FontId, newCfg.m_FontId), false,
			_CONFIG_ERROR_INFO(i));

		m_TextContainerConfig.emplace(TextId(id), std::move(newCfg));
	}

	return true;
}