#pragma once

struct Mix_Chunk;

struct SoundData
{
	SoundData();
	SoundData(Mix_Chunk* sound, uint8_t volume);

	~SoundData();

	Mix_Chunk*			m_Sound					= nullptr;
	uint8_t				m_Volume				= 0;
};