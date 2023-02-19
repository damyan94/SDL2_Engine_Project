// Corresponding header
#include "sdl_utils/audio/Audio.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "managers/AssetManager.h"

// =============================================================================
// Mix_PlayChannel
void Audio::PlaySound(SoundId id, int32_t loops)
{
	const auto soundContainer = AssetManager::Get()->GetSoundContainer();

	Mix_PlayChannel(Audio::FIRST_FREE_CHANNEL, soundContainer->GetSoundById(id), loops);
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
void Audio::PlayMusic(MusicId id, int32_t loops)
{
	const auto musicContainer = AssetManager::Get()->GetMusicContainer();

	Mix_PlayMusic(musicContainer->GetMusicById(id), loops);
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
	AssertReturnIf(volume < VOLUME_ZERO || volume > VOLUME_MAX, void(),
		"Received invalid volume value.");

	Mix_Volume(ALL_CHANNELS, volume);
}

// =============================================================================
// Mix_VolumeMusic
void Audio::SetMusicVolume(uint8_t volume)
{
	AssertReturnIf(volume < VOLUME_ZERO || volume > VOLUME_MAX, void(),
		"Received invalid volume value.");

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
bool Audio::IsMusicPlaying()
{
	return Mix_PlayingMusic();
}

// =============================================================================
// Mix_PausedMusic
bool Audio::isMusicPaused()
{
	return Mix_PausedMusic();
}