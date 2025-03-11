#pragma once

struct Mix_Chunk;

struct SoundData
{
	Mix_Chunk*			m_Sound					= nullptr;
	uint8_t				m_Volume				= 0;
};