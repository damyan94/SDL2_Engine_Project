#include "stdafx.h"

#include "System/Components/Audio/Sound.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/AudioManager.h"

////////////////////////////////////////////////////////////////////////////////
Sound::Sound()
	: m_SoundId(SoundId(0))
	, m_Channel(0)
{
}

////////////////////////////////////////////////////////////////////////////////
Sound::~Sound()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::Init(SoundId id)
{
	const auto& data = AssetManager::Instance().GetSoundData(id);
	//ReturnIf(!data, false);

	m_AudioParameters.m_Volume			= data.m_Volume;
	m_AudioParameters.m_ObjectType		= EObjectType::Sound;
	m_SoundId							= id;
	m_Channel							= 0;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Sound::Deinit()
{
	AudioObject::Reset();
}

////////////////////////////////////////////////////////////////////////////////
void Sound::Play()
{
	ReturnIf(m_AudioParameters.m_Volume <= 0);
	
	m_Channel = AudioManager::Instance().PlaySound(AssetManager::Instance().GetSoundData(m_SoundId), m_AudioParameters.m_Loops);
}

////////////////////////////////////////////////////////////////////////////////
void Sound::Pause(bool paused)
{
	AudioManager::Instance().PauseSound(m_Channel, paused);
}

////////////////////////////////////////////////////////////////////////////////
void Sound::Stop()
{
	AudioManager::Instance().StopSound(m_Channel);
	m_Channel = 0;
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::IsPlaying() const
{
	return AudioManager::Instance().IsSoundPlaying(m_Channel);
}

////////////////////////////////////////////////////////////////////////////////
void Sound::SetVolume(uint8_t volume)
{
	AudioManager::Instance().SetSoundVolume(m_Channel, volume);
}

////////////////////////////////////////////////////////////////////////////////
uint8_t Sound::GetVolume()
{
	return AudioManager::Instance().GetSoundVolume(m_Channel);
}