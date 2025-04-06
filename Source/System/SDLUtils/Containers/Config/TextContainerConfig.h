#pragma once

struct TextConfig
{
	Color				TextColor				= Colors::Black;
	FontId				FontId					= 0;
	StringId			StringId				= 0;
	int32_t				WrapWidth				= 0;
};

struct TextContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<TextConfig>		TextContainerConfig;
};