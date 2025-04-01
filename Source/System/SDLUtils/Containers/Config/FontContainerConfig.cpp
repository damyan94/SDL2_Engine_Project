#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool FontContainerConfig::Read(const ConfigStrings& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

		FontConfig newCfg;

		newCfg.FileName = ConfigFilePaths::ConfigFilePath(Utils::ReadString(readStrings[i], "FileName"));
		AssertReturnIf(newCfg.FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.Size = Utils::ReadInt(readStrings[i], "Size");
		AssertReturnIf(newCfg.Size <= 0 && _CONFIG_ERROR_INFO(i), false);

		newCfg.WrapAlign = EFontWrapAlign(Utils::ReadInt(readStrings[i], "WrapAlign"));
		AssertReturnIf(!IsEnumValueValid(newCfg.WrapAlign) && _CONFIG_ERROR_INFO(i), false);

		FontContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}