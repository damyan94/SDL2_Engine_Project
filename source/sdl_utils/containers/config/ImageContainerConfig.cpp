// Corresponding header
#include "sdl_utils/containers/config/ImageContainerConfig.h"

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
bool ImageContainerConfig::Read()
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::ImageContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)ImageId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::ImageContainer);
	
	for (size_t i = 0; i < (size_t)ImageId::Count; i++)
	{
		ImageConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::ImageContainer, i));

		newCfg.m_Frames = Utils::ReadInt(readStrings[i], "frames");
		AssertReturnIf(newCfg.m_Frames < 0, false,
			_CONFIG_ERROR_INFO(ConfigFilePaths::ImageContainer, i));
	
		m_ImageContainerConfig.emplace(ImageId(i), std::move(newCfg));
	}

	return true;
}