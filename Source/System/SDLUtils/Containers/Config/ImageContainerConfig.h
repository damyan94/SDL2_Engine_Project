#pragma once

struct ImageConfig
{
	std::string			FileName;
	uint32_t			Frames				= 0;
};

struct ImageContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<ImageConfig> ImageContainerConfig;
};