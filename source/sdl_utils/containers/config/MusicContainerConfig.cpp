#include "stdafx.h"

#include "sdl_utils/containers/config/MusicContainerConfig.h"

static const std::string c_TypeString = "MUSIC";

// =============================================================================
bool MusicContainerConfig::Read(const ConfigStrings& readStrings)
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

		MusicConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false, _CONFIG_ERROR_INFO(i));

		newCfg.m_Volume = Utils::ReadInt(readStrings[i], "volume");
		AssertReturnIf(newCfg.m_Volume <= 0, false, _CONFIG_ERROR_INFO(i));

		m_MusicContainerConfig.emplace(MusicId(i), std::move(newCfg));
	}

	return true;
}