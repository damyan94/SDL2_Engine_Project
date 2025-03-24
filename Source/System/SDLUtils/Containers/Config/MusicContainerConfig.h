#pragma once

struct MusicConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct MusicContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<MusicConfig> MusicContainerConfig;
};