// Corresponding header
#include "components/audio/Music.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/AudioManager.h"

// =============================================================================
Music::Music()
	: m_MusicId(MusicId::Invalid)
{
}

// =============================================================================
Music::~Music()
{
	Deinit();
}

// =============================================================================
bool Music::Init(MusicId id)
{
	MusicData data = g_AssetManager->GetMusicData(id);

	m_AudioParameters.m_Loops			= 0;
	m_AudioParameters.m_LoopInfinitely	= false;

	m_AudioParameters.m_Volume			= data.m_Volume;
	m_AudioParameters.m_MaxVolume		= Constants::MaxVolume;

	m_AudioParameters.m_ObjectType		= EObjectType::Sound;

	m_MusicId							= id;

	return true;
}

// =============================================================================
void Music::Deinit()
{
	AudioObject::Reset();
}


// =============================================================================
void Music::Play()
{
	ReturnIf(m_AudioParameters.m_Volume <= 0, void());

	g_AudioManager->PlayMusic(m_MusicId, m_AudioParameters.m_Loops);
}

// =============================================================================
void Music::Pause(bool paused)
{
	g_AudioManager->PauseMusic(paused);
}

// =============================================================================
void Music::Stop()
{
	g_AudioManager->StopMusic();
}

// =============================================================================
bool Music::IsPlaying() const
{
	return g_AudioManager->IsMusicPlaying();
}

// =============================================================================
void Music::SetVolume(uint8_t volume)
{
	g_AudioManager->SetMusicVolume(volume);
}

// =============================================================================
uint8_t Music::GetVolume()
{
	return g_AudioManager->GetMusicVolume();
}