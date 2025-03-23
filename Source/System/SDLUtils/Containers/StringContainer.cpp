#include "stdafx.h"

#include "System/SDLUtils/Containers/StringContainer.h"
#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"

////////////////////////////////////////////////////////////////////////////////
const std::string& StringData::GetLocalizedString(ELanguage language) const
{
	const auto it = LanguageStrings.find(language);
	AssertReturnIf(it == LanguageStrings.end(), "");

	return it->second;
}

////////////////////////////////////////////////////////////////////////////////
StringContainer::StringContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
StringContainer::~StringContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool StringContainer::DoesAssetExist(StringId id) const
{
	return id >= 0 && id < m_StringsContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const StringData& StringContainer::GetStringData(StringId id) const
{
	AssertReturnIf(!DoesAssetExist(id), StringData());

	return m_StringsContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool StringContainer::Init(const StringContainerConfig& cfg)
{
	for (int i = 0; i < cfg.m_StringsContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& stringCfg = cfg.m_StringsContainerConfig[i];

		StringData newString;

		for (const auto& [language, string] : stringCfg.LanguageStrings)
		{
			newString.LanguageStrings[language] = string;
		}

		m_StringsContainer.emplace_back(std::move(newString));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void StringContainer::Deinit()
{
	m_StringsContainer.clear();
}