#include "stdafx.h"

#include "System/SDLUtils/Containers/MusicContainer.h"
#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

#include "System/SDLUtils/Audio/Audio.h"

////////////////////////////////////////////////////////////////////////////////
MusicContainer::MusicContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
MusicContainer::~MusicContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool MusicContainer::DoesAssetExist(MusicId id) const
{
	return id >= 0 && id < m_MusicContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const MusicData* MusicContainer::GetMusicData(MusicId id) const
{
	AssertReturnIf(!DoesAssetExist(id), nullptr);

	return &m_MusicContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool MusicContainer::Init(const MusicContainerConfig& cfg)
{
	for (int i = 0; i < cfg.m_MusicContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& musicCfg = cfg.m_MusicContainerConfig[i];

		MusicData newMusic;

		Audio::CreateMusicFromFile(newMusic.m_Music, musicCfg.m_FileName.c_str());
		ReturnIf(!newMusic.m_Music, false);

		newMusic.m_Volume = musicCfg.m_Volume;

		m_MusicContainer.emplace_back(std::move(newMusic));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void MusicContainer::Deinit()
{
	for (auto& music : m_MusicContainer)
	{
		Audio::DestroyMusic(music.m_Music);
	}

	m_MusicContainer.clear();
}