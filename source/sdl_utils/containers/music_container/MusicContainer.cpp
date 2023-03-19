// Corresponding header
#include "sdl_utils/containers/music_container/MusicContainer.h"
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes

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
bool MusicContainer::DoesAssetExist(MusicId id) const
{
	return m_MusicContainer.find(id) != m_MusicContainer.end();
}

// =============================================================================
MusicData MusicContainer::GetMusicData(MusicId id) const
{
	AssertReturnIf(!DoesAssetExist(id), MusicData(),
		"Received unexsistant music id.");

	return m_MusicContainer.find(id)->second;
}

// =============================================================================
// Mix_LoadMUS
bool MusicContainer::Init(const MusicContainerConfig& cfg)
{
	for (const auto& [id, musicCfg] : cfg.m_MusicContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already exsistant music id.");

		MusicData newMusic;
		newMusic.m_Music = Mix_LoadMUS(musicCfg.m_FileName.c_str());
		AssertReturnIf(!newMusic.m_Music, false,
			"Mix_LoadMUS() failed: " + std::string(SDL_GetError()));

		newMusic.m_Volume = musicCfg.m_Volume;
		AssertReturnIf(newMusic.m_Volume < 0, false,
			"Received invalid volume.");

		m_MusicContainer.emplace(id, std::move(newMusic));
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