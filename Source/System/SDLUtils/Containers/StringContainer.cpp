#include "stdafx.h"

#include "System/SDLUtils/Containers/StringContainer.h"
#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"

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
	return id >= 0 && id < m_StringsContainer.begin()->second.size();
}

////////////////////////////////////////////////////////////////////////////////
const std::string& StringContainer::GetLocalizedString(ELanguage language, StringId id) const
{
	AssertReturnIf(!DoesAssetExist(id), "");

	const auto it = m_StringsContainer.find(language);
	AssertReturnIf(it == m_StringsContainer.end(), "");

	return it->second[id];
}

////////////////////////////////////////////////////////////////////////////////
bool StringContainer::Init(const StringContainerConfig& cfg)
{
	for (const auto& [language, strings] : cfg.StringContainerConfig)
	{
		m_StringsContainer[language] = strings;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void StringContainer::Deinit()
{
	m_StringsContainer.clear();
}