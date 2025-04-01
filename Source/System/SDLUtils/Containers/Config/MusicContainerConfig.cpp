#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool MusicContainerConfig::Read(const ConfigStrings& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		MusicConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.Volume = Utils::ReadInt(readStrings[i], "Volume");
		AssertReturnIf(newCfg.Volume <= 0 && _CONFIG_ERROR_INFO(i), false);

		MusicContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}