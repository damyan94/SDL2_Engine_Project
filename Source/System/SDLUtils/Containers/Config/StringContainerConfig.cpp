#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

static const std::string c_TypeString = "String";

////////////////////////////////////////////////////////////////////////////////
bool StringContainerConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_TypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_TypeString.c_str());
		return false;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "Type") != c_TypeString);

		StringConfig newCfg;

		for (int32_t j = (int32_t)ELanguage::Invalid + 1; j < (int32_t)ELanguage::Count; j++)
		{
			const auto currLanguage = ELanguage(j);
			std::string languageString = Utils::ReadString(readStrings[i], Utils::GetLanguageStringFromId(currLanguage));
			AssertReturnIf(languageString.empty() && _CONFIG_ERROR_INFO(i), false);

			newCfg.LanguageStrings.emplace(currLanguage, std::move(languageString));
		}

		StringContainerConfig.emplace_back(std::move(newCfg));
	}

	return true;
}