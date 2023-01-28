// Corresponding header
#include "sdl_utils/containers/SoundContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "defines/SoundDefines.h"

std::unordered_map<int32_t, Mix_Chunk*> SoundContainer::_sounds;

// =============================================================================
SoundContainer::~SoundContainer()
{
	Deinit();
}

// =============================================================================
// Mix_LoadWAV
int32_t SoundContainer::Init()
{
	for (const auto& soundInfo : soundsInfo)
	{
		int32_t id = soundInfo.id;
		if (_sounds.find(id) != _sounds.end())
		{
			std::cerr << "Error, found existing sound with the same id: "
				<< id << std::endl;
			return EXIT_FAILURE;
		}

		_sounds[id] = Mix_LoadWAV(soundInfo.fileName);
		if (!_sounds[id])
		{
			std::cerr << "Error, Mix_LoadWAV() failed for file: "
				<< soundInfo.fileName << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

// =============================================================================
// Mix_FreeChunk
void SoundContainer::Deinit()
{
	for (auto& sound : _sounds)
		if (sound.second)
		{
			Mix_FreeChunk(sound.second);
			sound.second = nullptr;
		}
}

// =============================================================================
Mix_Chunk* SoundContainer::GetSoundById(int32_t id)
{
	if (_sounds.find(id) == _sounds.end() && _sounds.size() > 1)
	{
		std::cerr << "Error, could not find sound with id: "
			<< id << std::endl;
		return nullptr;
	}

	return _sounds[id];
}