#pragma once

struct SoundConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct SoundContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<SoundConfig> SoundContainerConfig;
};