// Corresponding header
#include "sdl_utils/containers/config/FontContainerConfig.h"

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
bool FontContainerConfig::Read()
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::FontContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)FontId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::FontContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		FontConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::FontContainer, i));

		newCfg.m_Size = Utils::ReadInt(readStrings[i], "size");
		AssertReturnIf(newCfg.m_Size <= 0, false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::FontContainer, i));

		newCfg.m_WrapAlign = EFontWrapAlign(Utils::ReadInt(readStrings[i], "wrap_align"));
		AssertReturnIf(!IsEnumValueValid(newCfg.m_WrapAlign), false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::FontContainer, i));

		m_FontContainerConfig.emplace(FontId(i), std::move(newCfg));
	}

	return true;
}