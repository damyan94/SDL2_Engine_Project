#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool SoundContainerConfig::Read(const StringVector& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		SoundConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty(), false);

		newCfg.Volume = Utils::ReadInt(readStrings[i], "Volume");
		AssertReturnIf(newCfg.Volume <= 0, false);

		SoundContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}