#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "Sound";

////////////////////////////////////////////////////////////////////////////////
bool SoundContainerConfig::Read(const ConfigStrings& readStrings)
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

		SoundConfig newCfg;

		newCfg.m_FileName = ConfigFilePaths::MainDir + Utils::ReadString(readStrings[i], "FileName");
		AssertReturnIf(newCfg.m_FileName.empty() && _CONFIG_ERROR_INFO(i), false);

		newCfg.m_Volume = Utils::ReadInt(readStrings[i], "Volume");
		AssertReturnIf(newCfg.m_Volume <= 0 && _CONFIG_ERROR_INFO(i), false);

		m_SoundContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}