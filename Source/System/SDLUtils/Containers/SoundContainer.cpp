#include "stdafx.h"

#include "System/SDLUtils/Containers/SoundContainer.h"
#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"

#include "System/SDLUtils/Audio/Audio.h"

////////////////////////////////////////////////////////////////////////////////
SoundContainer::SoundContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
SoundContainer::~SoundContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool SoundContainer::DoesAssetExist(SoundId id) const
{
	return id >= 0 && id < m_SoundContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const SoundData& SoundContainer::GetData(SoundId id) const
{
	AssertReturnIf(!DoesAssetExist(id), SoundData());

	return m_SoundContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool SoundContainer::Init(const SoundContainerConfig& cfg)
{
	for (int i = 0; i < cfg.m_SoundContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& soundCfg = cfg.m_SoundContainerConfig[i];

		SoundData newSound;

		Audio::CreateSoundFromFile(newSound.m_Sound, soundCfg.m_FileName.c_str());
		ReturnIf(!newSound.m_Sound, false);

		newSound.m_Volume = soundCfg.m_Volume;

		m_SoundContainer.emplace_back(std::move(newSound));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void SoundContainer::Deinit()
{
	for (auto& sound : m_SoundContainer)
	{
		Audio::DestroySound(sound.m_Sound);
	}

	m_SoundContainer.clear();
}