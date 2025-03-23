#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"
#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "Image";

////////////////////////////////////////////////////////////////////////////////
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
		BreakIf(Utils::ReadString(readStrings[i], "Type") != c_TypeString);

		ImageConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.Frames = Utils::ReadInt(readStrings[i], "Frames");
		AssertReturnIf(newCfg.Frames < 0 && _CONFIG_ERROR_INFO(i), false);
	
		ImageContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}