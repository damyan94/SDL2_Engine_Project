#include "stdafx.h"

#include "system/sdl_utils/containers/config/ImageContainerConfig.h"
#include "defines/ConfigFilePaths.h"

static const std::string c_TypeString = "IMAGE";

// =============================================================================
bool ImageContainerConfig::Read(const ConfigStrings& readStrings)
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

		ImageConfig newCfg;

		newCfg.m_FileName = ConfigFilePaths::MainDir + Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false, _CONFIG_ERROR_INFO(i));

		newCfg.m_Frames = Utils::ReadInt(readStrings[i], "frames");
		AssertReturnIf(newCfg.m_Frames < 0, false, _CONFIG_ERROR_INFO(i));
	
		m_ImageContainerConfig.emplace(ImageId(id), std::move(newCfg));
	}

	return true;
}