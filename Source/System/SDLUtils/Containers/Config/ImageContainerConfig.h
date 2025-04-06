#pragma once

struct ImageConfig
{
	std::string			FileName;
	uint32_t			Frames				= 0;
};

struct ImageContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<ImageConfig> ImageContainerConfig;
};