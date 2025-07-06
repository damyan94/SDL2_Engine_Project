#pragma once

struct SoundConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct SoundContainerConfig
{
	bool				Read(const StringVector& readStrings);

	std::vector<SoundConfig> SoundContainerConfig;
};