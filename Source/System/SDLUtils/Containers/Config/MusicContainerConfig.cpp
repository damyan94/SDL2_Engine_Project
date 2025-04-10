#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool MusicContainerConfig::Read(const LinesOfText& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		MusicConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty(), false);

		newCfg.Volume = Utils::ReadInt(readStrings[i], "Volume");
		AssertReturnIf(newCfg.Volume <= 0, false);

		MusicContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}