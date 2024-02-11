#include "stdafx.h"

#include <SDL_mixer.h>

#include "system/sdl_utils/audio/Audio.h"

static constexpr int32_t FirstFreeChannel		= -1;
static constexpr int32_t AllChannels			= -1;

// =============================================================================
bool Audio::CreateSoundFromFile(Mix_Chunk*& outSound, const std::string& fileName)
{
	outSound = Mix_LoadWAV(fileName.c_str());

	AssertReturnIf(!outSound && SDL_GetError(), false);

	return true;
}

// =============================================================================
bool Audio::CreateMusicFromFile(Mix_Music*& outMusic, const std::string& fileName)
{
	outMusic = Mix_LoadMUS(fileName.c_str());

	AssertReturnIf(!outMusic && SDL_GetError(), false);

	return true;
}

// =============================================================================
void Audio::DestroySound(Mix_Chunk*& outSound)
{
	ReturnIf(!outSound, void());

	Mix_FreeChunk(outSound);
	outSound = nullptr;
}

// =============================================================================
void Audio::DestroyMusic(Mix_Music*& outMusic)
{
	ReturnIf(!outMusic, void());

	Mix_FreeMusic(outMusic);
	outMusic = nullptr;
}

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