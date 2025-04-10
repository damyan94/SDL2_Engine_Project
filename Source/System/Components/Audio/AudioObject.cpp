#include "stdafx.h"

#include "System/Components/Audio/AudioObject.h"

#include "Managers/AudioManager.h"

////////////////////////////////////////////////////////////////////////////////
AudioObject::AudioObject()
{
}

////////////////////////////////////////////////////////////////////////////////
AudioObject::~AudioObject()
{
}

////////////////////////////////////////////////////////////////////////////////
const AudioParameters& AudioObject::GetAudioParameters() const
{
	return m_AudioParameters;
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::Reset()
{
	m_AudioParameters.Reset();
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::Play()
{
	switch (m_AudioParameters.ObjectType)
	{
	case EObjectType::Sound:
		AudioManager::Instance().PlaySound(m_AudioParameters);
		return;

	case EObjectType::Music:
		AudioManager::Instance().PlayMusic(m_AudioParameters);
		return;

	default:
		Assert("TODO");
		return;
	}
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::Pause(bool paused)
{
	AudioManager::Instance().PauseMusic(paused);
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::Stop()
{
	AudioManager::Instance().StopMusic();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioObject::IsPlaying() const
{
	return AudioManager::Instance().IsMusicPlaying();
}

// Getters

////////////////////////////////////////////////////////////////////////////////
int32_t AudioObject::GetLoops() const
{
	return m_AudioParameters.Loops;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioObject::GetLoopInfinitely() const
{
	return m_AudioParameters.LoopInfinitely;
}

////////////////////////////////////////////////////////////////////////////////
uint8_t AudioObject::GetVolume() const
{
	return m_AudioParameters.MaxVolume;
}

////////////////////////////////////////////////////////////////////////////////
uint8_t AudioObject::GetMaxVolume() const
{
	return m_AudioParameters.Volume;
}

////////////////////////////////////////////////////////////////////////////////
EObjectType AudioObject::GetObjectType() const
{
	return m_AudioParameters.ObjectType;
}

// Setters

////////////////////////////////////////////////////////////////////////////////
void AudioObject::SetLoops(int32_t loops)
{
	m_AudioParameters.Loops = loops;
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::SetLoopInfinitely(bool loopInfinitely)
{
	m_AudioParameters.LoopInfinitely = loopInfinitely;
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::SetVolume(uint8_t volume)
{
	m_AudioParameters.MaxVolume = volume;
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::SetMaxVolume(uint8_t volume)
{
	m_AudioParameters.Volume = volume;
}

////////////////////////////////////////////////////////////////////////////////
void AudioObject::SetObjectType(EObjectType type)
{
	m_AudioParameters.ObjectType = type;
}

// Others