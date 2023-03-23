// Corresponding header
#include "sdl_utils/containers/config/TextContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// =============================================================================
bool TextContainerConfig::Read()
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::TextContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)TextId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::TextContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		TextConfig newCfg;

		std::string temp = Utils::ReadString(readStrings[i], "string");
		newCfg.m_String = String(temp.begin(), temp.end());

		auto color = Utils::ReadIntArray(readStrings[i], "color", 4);
		AssertReturnIf(color.size() != 4, false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::TextContainer, i));

		newCfg.m_TextColor = Color(color[0], color[1], color[2], color[3]);

		newCfg.m_FontId = FontId(Utils::ReadInt(readStrings[i], "font_id"));
		AssertReturnIf(!IsEnumValueValid(newCfg.m_FontId), false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::TextContainer, i));

		m_TextContainerConfig.emplace(TextId(i), std::move(newCfg));
	}

	return true;
}