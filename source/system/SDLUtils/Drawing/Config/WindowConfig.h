#pragma once

struct WindowConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::string			m_Name;
	int32_t				m_PosX;
	int32_t				m_PosY;
	int32_t				m_Width;
	int32_t				m_Height;
	int32_t				m_Flags;
};