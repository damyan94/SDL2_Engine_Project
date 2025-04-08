#pragma once

struct StringConfig
{
	LanguageStringMap	LanguageStrings;
};

struct StringContainerConfig
{
	bool				Read(const LinesOfText& readStrings);

	std::vector<StringConfig>	StringContainerConfig;
};