// Corresponding header
#include "sdl_utils/containers/MusicContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// =============================================================================
MusicContainer::MusicContainer()
{
}

// =============================================================================
MusicContainer::~MusicContainer()
{
	Deinit();
}

// =============================================================================
// Mix_LoadMUS
bool MusicContainer::Init(const MusicContainerConfig& cfg)
{
	for (const auto& [id, musicInfo] : cfg.m_MusicContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant music id.");

		m_MusicContainer[id].m_Music = Mix_LoadMUS(musicInfo.m_FileName.c_str());
		AssertReturnIf(!m_MusicContainer[id].m_Music, false, "Mix_LoadMUS() failed: " + std::string(SDL_GetError()));
	}

	return true;
}

// =============================================================================
// Mix_FreeMusic
void MusicContainer::Deinit()
{
	for (auto& [id, music] : m_MusicContainer)
	{
		ContinueIf(!music.m_Music);

		Mix_FreeMusic(music.m_Music);
		music = nullptr;
	}

	m_MusicContainer.clear();
}

// =============================================================================
bool MusicContainer::DoesAssetExist(MusicId id)
{
	return m_MusicContainer.find(id) != m_MusicContainer.end();
}

// =============================================================================
Mix_Music* MusicContainer::GetMusicById(MusicId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant music id.");

	return m_MusicContainer[id].m_Music;
}

// =============================================================================
MusicContainer::MusicUnit::MusicUnit()
	: m_Music(nullptr)
{
}

// =============================================================================
MusicContainer::MusicUnit::MusicUnit(Mix_Music* music)
	: m_Music(music)
{
}

// =============================================================================
MusicContainer::MusicUnit::~MusicUnit()
{
}