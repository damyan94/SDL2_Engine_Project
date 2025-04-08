#pragma once

struct ImageConfig
{
	std::string			FileName;
	uint32_t			Frames				= 0;
};

struct ImageContainerConfig
{
	bool				Read(const LinesOfText& readStrings);

	std::vector<ImageConfig> ImageContainerConfig;
};