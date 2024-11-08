#pragma once

struct SoundConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct SoundContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<SoundConfig> m_SoundContainerConfig;
};