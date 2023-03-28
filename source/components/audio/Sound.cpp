// Corresponding header
#include "components/audio/Sound.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/AudioManager.h"

// =============================================================================
Sound::Sound()
	: m_SoundId(SoundId(-1))
	, m_Channel(0)
{
}

// =============================================================================
Sound::~Sound()
{
	Deinit();
}

// =============================================================================
bool Sound::Init(SoundId id)
{
	SoundData data = g_AssetManager->GetSoundData(id);

	m_AudioParameters.m_Loops			= 0;
	m_AudioParameters.m_LoopInfinitely	= false;

	m_AudioParameters.m_Volume			= data.m_Volume;
	m_AudioParameters.m_MaxVolume		= Constants::MaxVolume;

	m_AudioParameters.m_ObjectType		= EObjectType::Sound;

	m_SoundId							= id;
	m_Channel							= 0;

	return true;
}

// =============================================================================
void Sound::Deinit()
{
	AudioObject::Reset();
}

// =============================================================================
void Sound::Play()
{
	ReturnIf(m_AudioParameters.m_Volume <= 0, void());
	
	m_Channel = g_AudioManager->PlaySound(m_SoundId, m_AudioParameters.m_Loops);
}

// =============================================================================
void Sound::Pause(bool paused)
{
	g_AudioManager->PauseSound(m_Channel, paused);
}

// =============================================================================
void Sound::Stop()
{
	g_AudioManager->StopSound(m_Channel);
	m_Channel = 0;
}

// =============================================================================
bool Sound::IsPlaying() const
{
	return g_AudioManager->IsSoundPlaying(m_Channel);
}

// =============================================================================
void Sound::SetVolume(uint8_t volume)
{
	g_AudioManager->SetSoundVolume(m_Channel, volume);
}

// =============================================================================
uint8_t Sound::GetVolume()
{
	return g_AudioManager->GetSoundVolume(m_Channel);
}