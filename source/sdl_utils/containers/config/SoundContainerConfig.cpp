// Corresponding header
#include "sdl_utils/containers/config/SoundContainerConfig.h"

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
bool SoundContainerConfig::Read()
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::SoundContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)SoundId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::SoundContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		SoundConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::SoundContainer, i));

		newCfg.m_Volume = Utils::ReadInt(readStrings[i], "volume");
		AssertReturnIf(newCfg.m_Volume <= 0, false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::SoundContainer, i));

		m_SoundContainerConfig.emplace(SoundId(i), std::move(newCfg));
	}

	return true;
}