// Corresponding header
#include "sdl_utils/containers/MusicContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "defines/MusicDefines.h"

std::unordered_map<MusicId, Mix_Music*> MusicContainer::m_Musics;

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
bool MusicContainer::Init()
{
	for (const auto& musicInfo : m_MusicsData)
	{
		MusicId id = musicInfo.m_Id;

		AssertReturnIf(DoesAssetExist(id), false);

		m_Musics[id] = Mix_LoadMUS(musicInfo.m_FileName);
		AssertReturnIf(!m_Musics[id], false);
	}

	return true;
}

// =============================================================================
// Mix_FreeMusic
void MusicContainer::Deinit()
{
	for (auto& [id, music] : m_Musics)
	{
		if (music)
		{
			Mix_FreeMusic(music);
			music = nullptr;
		}
	}

	m_Musics.clear();
}

// =============================================================================
bool MusicContainer::DoesAssetExist(MusicId id)
{
	return m_Musics.find(id) != m_Musics.end();
}

// =============================================================================
Mix_Music* MusicContainer::GetMusicById(MusicId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr);

	return m_Musics[id];
}