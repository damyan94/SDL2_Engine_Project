#pragma once

struct FontConfig
{
	std::string			FileName;
	uint32_t			Size					= 0;
	EFontWrapAlign		WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
{
	bool				Read(const StringVector& readStrings);

	std::vector<FontConfig>	FontContainerConfig;
};