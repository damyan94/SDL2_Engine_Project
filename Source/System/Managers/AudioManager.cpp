#include "stdafx.h"

#include "System/Managers/AudioManager.h"
#include "System/Managers/Config/AudioManagerConfig.h"

#include "System/SDLUtils/Audio/Audio.h"
#include "System/SDLUtils/Containers/Data/SoundData.h"
#include "System/SDLUtils/Containers/Data/MusicData.h"

////////////////////////////////////////////////////////////////////////////////
AudioManager::AudioManager()
{
}

////////////////////////////////////////////////////////////////////////////////
AudioManager::~AudioManager()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
AudioManager& AudioManager::Instance()
{
	static AudioManager m_Instance;
	return m_Instance;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::Init(const AudioManagerConfig& cfg)
{

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
int32_t AudioManager::PlaySound(const SoundData& data, int32_t loops)
{
	return Audio::PlaySound(data.m_Sound, loops);
}

////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
void AudioManager::StopSound(int32_t channel)
{
	Audio::StopSound(channel);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::StopSounds()
{
	Audio::StopSounds();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::PlayMusic(const MusicData& data, int32_t loops)
{
	Audio::PlayMusic(data.m_Music, loops);
}

////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
void AudioManager::StopMusic()
{
	Audio::StopMusic();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::SetSoundVolume(int32_t channel, uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume);

	Audio::SetSoundVolume(channel, volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::SetSoundsVolume(uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume);

	Audio::SetSoundsVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::SetMusicVolume(uint8_t volume)
{
	AssertReturnIf(volume < Constants::ZeroVolume || volume > Constants::MaxVolume);

	Audio::SetMusicVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
uint8_t AudioManager::GetSoundVolume(int32_t channel)
{
	return Audio::GetSoundVolume(channel);
}

////////////////////////////////////////////////////////////////////////////////
uint8_t AudioManager::GetMusicVolume()
{
	return Audio::GetMusicVolume();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::IsSoundPlaying(int32_t channel)
{
	return Audio::IsSoundPlaying(channel);
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::IsSoundPaused(int32_t channel)
{
	return Audio::IsSoundPaused(channel);
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::IsMusicPlaying()
{
	return Audio::IsMusicPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::IsMusicPaused()
{
	return Audio::IsMusicPaused();
}