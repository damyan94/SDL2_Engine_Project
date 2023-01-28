// Corresponding header
#include "sdl_utils/audio/Audio.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

// =============================================================================
// Mix_PlayChannel
void Audio::PlaySound(int32_t soundId, int32_t loops)
{
	Mix_PlayChannel(Audio::FIRST_FREE_CHANNEL,
		SoundContainer::GetSoundById(soundId), loops);
}

// =============================================================================
// Mix_Pause
void Audio::PauseSounds()
{
	Mix_Pause(ALL_CHANNELS);
}

// =============================================================================
// Mix_HaltChannel
void Audio::StopSounds()
{
	Mix_HaltChannel(ALL_CHANNELS);
}

// =============================================================================
// Mix_PlayMusic
void Audio::PlayMusic(int32_t musicId, int32_t loops)
{
	Mix_PlayMusic(MusicContainer::GetMusicById(musicId), loops);
}

// =============================================================================
// Mix_PauseMusic
void Audio::PauseMusic()
{
	Mix_PauseMusic();
}

// =============================================================================
// Mix_HaltMusic
void Audio::StopMusic()
{
	Mix_HaltMusic();
}

// =============================================================================
// Mix_Volume
void Audio::SetSoundsVolume(uint8_t volume)
{
	if (volume < VOLUME_ZERO || volume > VOLUME_MAX) //TODO VPS-Studio: V560 A part of conditional expression is always false: volume < VOLUME_ZERO. Unsigned type value is never < 0. Audio.cpp 61
	{
		std::cerr << "Error, Audio::SetSoundsVolume() received invalid parameter volume: "
			<< volume << std::endl;
		return;
	}

	Mix_Volume(ALL_CHANNELS, volume);
}

// =============================================================================
// Mix_VolumeMusic
void Audio::SetMusicVolume(uint8_t volume)
{
	if (volume < VOLUME_ZERO || volume > VOLUME_MAX) //TODO VPS-Studio: V560 A part of conditional expression is always false: volume < VOLUME_ZERO. Unsigned type value is never < 0. Audio.cpp 75
	{
		std::cerr << "Error, Audio::SetSoundsVolume() received invalid parameter volume: "
			<< volume << std::endl;
		return;
	}

	Mix_VolumeMusic(volume);
}

// =============================================================================
uint8_t Audio::GetSoundsVolume()
{
	return Mix_Volume(ALL_CHANNELS, -1);
}

// =============================================================================
uint8_t Audio::GetMusicVolume()
{
	return Mix_VolumeMusic(-1);
}

// =============================================================================
// Mix_PlayingMusic
bool Audio::PlayingMusic()
{
	return Mix_PlayingMusic();
}

// =============================================================================
// Mix_PausedMusic
bool Audio::PausedMusic()
{
	return Mix_PausedMusic();
}