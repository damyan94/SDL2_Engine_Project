#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool SoundContainerConfig::Read(const LinesOfText& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		SoundConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.Volume = Utils::ReadInt(readStrings[i], "Volume");
		AssertReturnIf(newCfg.Volume <= 0 && _CONFIG_ERROR_INFO(i), false);

		SoundContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}