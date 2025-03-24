#pragma once

struct FontConfig
{
	std::string			FileName;
	uint32_t			Size					= 0;
	EFontWrapAlign		WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<FontConfig>	FontContainerConfig;
};