#pragma once

struct SoundConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct SoundContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<SoundConfig> SoundContainerConfig;
};