#pragma once

struct FontConfig
{
	std::string			m_FileName;
	uint32_t			m_Size					= 0;
	EFontWrapAlign		m_WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<FontConfig>	m_FontContainerConfig;
};