#pragma once

struct FontConfig
{
	std::string			FileName;
	uint32_t			Size					= 0;
	EFontWrapAlign		WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<FontConfig>	FontContainerConfig;
};