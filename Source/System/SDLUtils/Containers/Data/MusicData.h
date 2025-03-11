#pragma once

typedef struct _Mix_Music Mix_Music;

struct MusicData
{
	Mix_Music*			m_Music					= 0;
	uint8_t				m_Volume				= 0;
};