#pragma once

struct AudioParameters
{
	AudioParameters();
	~AudioParameters();

	void				Reset();

	int32_t				m_Loops;
	bool				m_LoopInfinitely;

	uint8_t				m_Volume;
	uint8_t				m_MaxVolume;

	EObjectType			m_ObjectType;
};