#pragma once

struct ImageConfig
{
	std::string			m_FileName;
	uint32_t			m_Frames				= 0;
};

struct ImageContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<ImageConfig> m_ImageContainerConfig;
};