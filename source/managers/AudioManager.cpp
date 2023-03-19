// Corresponding header
#include "managers/AudioManager.h"
#include "managers/config/AudioManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/audio/Audio.h"
#include "managers/AssetManager.h"

AudioManager* g_AudioManager = nullptr;

// =============================================================================
AudioManager::AudioManager()
{
}

// =============================================================================
AudioManager::~AudioManager()
{
}

// =============================================================================
bool AudioManager::Init(const AudioManagerConfig& cfg)
{

	return true;
}

// =============================================================================
void AudioManager::Deinit()
{
}

// =============================================================================
int32_t AudioManager::PlaySound(SoundId id, int32_t loops)
{
	return Audio::PlaySound(g_AssetManager->GetSoundData(id).m_Sound, loops);
}

// =============================================================================
void AudioManager::PauseSound(int32_t channel, bool paused)
{
	if (paused)
	{
		if (IsSoundPlaying(channel))
		{
			Audio::TogglePauseSound(channel);
		}
	}
	else
	{
		if (!IsSoundPlaying(channel))
		{
			Audio::TogglePauseSound(channel);
		}
	}
}

// =============================================================================
void AudioManager::PauseSounds(bool paused)
{
	if (paused)
	{
		if (IsMusicPlaying())
		{
			Audio::TogglePauseMusic();
		}
	}
	else
	{
		if (!IsMusicPlaying())
		{
			Audio::TogglePauseMusic();
		}
	}
}

// =============================================================================
void AudioManager::StopSound(int32_t channel)
{
	Audio::StopSound(channel);
}

// =============================================================================
void AudioManager::StopSounds()
{
	Audio::StopSounds();
}

// =============================================================================
void AudioManager::PlayMusic(MusicId id, int32_t loops)
{
	Audio::PlayMusic(g_AssetManager->GetMusicData(id).m_Music, loops);
}

// =============================================================================
void AudioManager::PauseMusic(bool paused)
{
	if (paused)
	{
		if (IsMusicPlaying())
		{
			Audio::TogglePauseMusic();
		}
	}
	else
	{
		if (!IsMusicPlaying())
		{
			Audio::TogglePauseMusic();
		}
	}
}

// =============================================================================
void AudioManager::StopMusic()
{
	Audio::StopMusic();
}

// =============================================================================
void AudioManager::SetSoundVolume(int32_t channel, uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume,
		void(), "Received invalid volume value.");

	Audio::SetSoundVolume(channel, volume);
}

// =============================================================================
void AudioManager::SetSoundsVolume(uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume,
		void(), "Received invalid volume value.");

	Audio::SetSoundsVolume(volume);
}

// =============================================================================
void AudioManager::SetMusicVolume(uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume,
		void(), "Received invalid volume value.");

	Audio::SetMusicVolume(volume);
}

// =============================================================================
uint8_t AudioManager::GetSoundVolume(int32_t channel)
{
	return Audio::GetSoundVolume(channel);
}

// =============================================================================
uint8_t AudioManager::GetMusicVolume()
{
	return Audio::GetMusicVolume();
}

// =============================================================================
bool AudioManager::IsSoundPlaying(int32_t channel)
{
	return Audio::IsSoundPlaying(channel);
}

// =============================================================================
bool AudioManager::IsSoundPaused(int32_t channel)
{
	return Audio::IsSoundPaused(channel);
}

// =============================================================================
bool AudioManager::IsMusicPlaying()
{
	return Audio::IsMusicPlaying();
}

// =============================================================================
bool AudioManager::IsMusicPaused()
{
	return Audio::IsMusicPaused();
}