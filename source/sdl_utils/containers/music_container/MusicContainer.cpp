// Corresponding header
#include "sdl_utils/containers/music_container/MusicContainer.h"
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "sdl_utils/audio/Audio.h"

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
const MusicData* MusicContainer::GetMusicData(MusicId id) const
{
	auto result = m_MusicContainer.find(id);
	AssertReturnIf(result == m_MusicContainer.end(), nullptr,
		"Received unexistant music id.");

	return &result->second;
}

// =============================================================================
bool MusicContainer::Init(const MusicContainerConfig& cfg)
{
	for (const auto& [id, musicCfg] : cfg.m_MusicContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant music id.");

		MusicData newMusic;

		Audio::CreateMusicFromFile(newMusic.m_Music, musicCfg.m_FileName.c_str());
		ReturnIf(!newMusic.m_Music, false);

		newMusic.m_Volume = musicCfg.m_Volume;

		m_MusicContainer.emplace(id, std::move(newMusic));
	}

	return true;
}

// =============================================================================
void MusicContainer::Deinit()
{
	for (auto& [id, music] : m_MusicContainer)
	{
		Audio::DestroyMusic(music.m_Music);
	}

	m_MusicContainer.clear();
}