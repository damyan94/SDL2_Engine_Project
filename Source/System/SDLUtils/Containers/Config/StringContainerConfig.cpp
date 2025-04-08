#include "stdafx.h"

#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool StringContainerConfig::Read(const LinesOfText& readStrings)
{
	const auto count = readStrings.size();
	for (size_t i = 0; i < count; i++)
	{
		const auto& line = readStrings[i];
		const auto id = Utils::ReadInt(line, "Id");
		AssertReturnIf(id != i, false);

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