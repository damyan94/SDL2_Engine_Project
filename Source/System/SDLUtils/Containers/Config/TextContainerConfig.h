#pragma once

struct TextConfig
{
	Color				TextColor				= Colors::Black;
	FontId				FontId					= 0;
	StringId			StringId				= 0;
	int32_t				WrapWidth				= 0;
};

struct TextContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<TextConfig>		m_TextsConfig;
};