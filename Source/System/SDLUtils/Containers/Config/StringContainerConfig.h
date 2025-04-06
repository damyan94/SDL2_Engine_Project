#pragma once

struct StringConfig
{
	LanguageStringMap	LanguageStrings;
};

struct StringContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<StringConfig>	StringContainerConfig;
};