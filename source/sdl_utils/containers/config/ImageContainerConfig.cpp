// Corresponding header
#include "sdl_utils/containers/config/ImageContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "image";

// =============================================================================
bool ImageContainerConfig::Read(const ConfigStrings& readStrings)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size() - 1)
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}
	
	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_CategoryTypeString);

		const int32_t id = Utils::ReadInt(readStrings[i], "id");

		ImageConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false, _CONFIG_ERROR_INFO(i));

		newCfg.m_Frames = Utils::ReadInt(readStrings[i], "frames");
		AssertReturnIf(newCfg.m_Frames < 0, false, _CONFIG_ERROR_INFO(i));
	
		m_ImageContainerConfig.emplace(ImageId(id), std::move(newCfg));
	}

	return true;
}