#pragma once

struct MusicConfig
{
	std::string			FileName;
	uint8_t				Volume		= 0;
};

struct MusicContainerConfig
{
	bool				Read(const LinesOfText& readStrings);

	std::vector<MusicConfig> MusicContainerConfig;
};