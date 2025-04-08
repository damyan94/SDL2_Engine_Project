#pragma once

struct SoundConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct SoundContainerConfig
{
	bool				Read(const LinesOfText& readStrings);

	std::vector<SoundConfig> SoundContainerConfig;
};