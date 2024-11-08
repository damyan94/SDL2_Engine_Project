#pragma once

struct TextConfig
{
	Color				m_TextColor				= Colors::Black;
	FontId				m_FontId				= 0;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings;
};

struct TextContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<TextConfig> m_TextContainerConfig;
};