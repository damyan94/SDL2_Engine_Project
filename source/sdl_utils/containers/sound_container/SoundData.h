#ifndef SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDDATA_H_
#define SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct Mix_Chunk;

struct SoundData
{
	SoundData();
	SoundData(Mix_Chunk* sound, uint8_t volume);

	~SoundData();

	Mix_Chunk*			m_Sound					= nullptr;
	uint8_t				m_Volume				= 0;
};

#endif // !SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDDATA_H_