#ifndef SDL_UTILS_AUDIO_AUDIO_H_
#define SDL_UTILS_AUDIO_AUDIO_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"
#include "defines/id/MusicId.h"

#include "utils/UtilsCommonIncludes.h"

// Forward declarations

namespace Audio
{
	constexpr int32_t LOOP_NONE = 0;
	constexpr int32_t LOOP_INFINITELY = -1;
	constexpr int32_t FIRST_FREE_CHANNEL = -1;
	constexpr int32_t ALL_CHANNELS = -1;
	constexpr uint8_t VOLUME_ZERO = 0;
	constexpr uint8_t VOLUME_MAX = 128;

	void PlaySound(SoundId id, int32_t loops = 0);
	void PauseSounds();
	void StopSounds();

	void PlayMusic(MusicId id, int32_t loops);
	void PauseMusic();
	void StopMusic();

	void SetSoundsVolume(uint8_t volume);
	void SetMusicVolume(uint8_t volume);

	uint8_t GetSoundsVolume();
	uint8_t GetMusicVolume();

	bool IsMusicPlaying();
	bool isMusicPaused();
};

#endif // !SDL_UTILS_AUDIO_AUDIO_H_