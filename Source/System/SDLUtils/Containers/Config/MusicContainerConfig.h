#pragma once

struct MusicConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct MusicContainerConfig
	: public IConfig
{
	bool Parse(const LinesOfText& readStrings) final;

	std::vector<MusicConfig> MusicContainerConfig;
};