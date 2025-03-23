#pragma once

struct StringConfig
{
	LanguageStringMap	LanguageStrings;
};

struct StringContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<StringConfig>	m_StringsContainerConfig;
};