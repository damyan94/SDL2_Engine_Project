#pragma once

typedef struct _Mix_Music Mix_Music;

struct MusicData
{
	MusicData();
	MusicData(Mix_Music* sound, uint8_t volume);

	~MusicData();

	Mix_Music*			m_Music					= 0;
	uint8_t				m_Volume				= 0;
};