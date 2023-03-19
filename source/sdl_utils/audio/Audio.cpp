// Corresponding header
#include "sdl_utils/audio/Audio.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes

static constexpr int32_t FirstFreeChannel		= -1;
static constexpr int32_t AllChannels			= -1;

// =============================================================================
int32_t Audio::PlaySound(Mix_Chunk* chunk, int32_t loops)
{
	return Mix_PlayChannel(FirstFreeChannel, chunk, loops);
}

// =============================================================================
void Audio::TogglePauseSound(int32_t channel)
{
	Mix_Pause(channel);
}

// =============================================================================
void Audio::TogglePauseSounds()
{
	Mix_Pause(AllChannels);
}

// =============================================================================
void Audio::StopSound(int32_t channel)
{
	Mix_HaltChannel(channel);
}

// =============================================================================
void Audio::StopSounds()
{
	Mix_HaltChannel(AllChannels);
}

// =============================================================================
void Audio::PlayMusic(Mix_Music* music, int32_t loops)
{
	Mix_PlayMusic(music, loops);
}

// =============================================================================
void Audio::TogglePauseMusic()
{
	Mix_PauseMusic();
}

// =============================================================================
void Audio::StopMusic()
{
	Mix_HaltMusic();
}

// =============================================================================
void Audio::SetSoundVolume(int32_t channel, uint8_t volume)
{
	Mix_Volume(channel, volume);
}

// =============================================================================
void Audio::SetSoundsVolume(uint8_t volume)
{
	Mix_Volume(AllChannels, volume);
}

// =============================================================================
void Audio::SetMusicVolume(uint8_t volume)
{
	Mix_VolumeMusic(volume);
}

// =============================================================================
uint8_t Audio::GetSoundVolume(int32_t channel)
{
	return Mix_Volume(channel, -1);
}

// =============================================================================
uint8_t Audio::GetMusicVolume()
{
	return Mix_VolumeMusic(-1);
}

// =============================================================================
bool Audio::IsSoundPlaying(int32_t channel)
{
	return Mix_Playing(channel);
}

// =============================================================================
bool Audio::IsSoundPaused(int32_t channel)
{
	return Mix_Paused(channel);
}

// =============================================================================
bool Audio::IsMusicPlaying()
{
	return Mix_PlayingMusic();
}

// =============================================================================
bool Audio::IsMusicPaused()
{
	return Mix_PausedMusic();
}