#ifndef SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICDATA_H_
#define SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
typedef struct _Mix_Music Mix_Music;

struct MusicData
{
	MusicData();
	MusicData(Mix_Music* sound);

	~MusicData();

	Mix_Music*			m_Music;
	uint8_t				m_Volume;
};

#endif // !SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICDATA_H_