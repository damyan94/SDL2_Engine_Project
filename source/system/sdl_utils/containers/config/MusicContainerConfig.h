#pragma once

struct MusicConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct MusicContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<MusicConfig> m_MusicContainerConfig;
};