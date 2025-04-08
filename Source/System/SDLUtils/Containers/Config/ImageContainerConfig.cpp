#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ImageContainerConfig::Read(const LinesOfText& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		ImageConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.Frames = Utils::ReadInt(readStrings[i], "Frames");
		AssertReturnIf(newCfg.Frames < 0 && _CONFIG_ERROR_INFO(i), false);
	
		ImageContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}