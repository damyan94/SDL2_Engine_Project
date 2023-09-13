#include "stdafx.h"

#include "system/sdl_utils/containers/sound_container/SoundContainer.h"
#include "system/sdl_utils/containers/config/SoundContainerConfig.h"

#include "system/sdl_utils/audio/Audio.h"

// =============================================================================
SoundContainer::SoundContainer()
{
}

// =============================================================================
SoundContainer::~SoundContainer()
{
	Deinit();
}

// =============================================================================
bool SoundContainer::DoesAssetExist(SoundId id) const
{
	return m_SoundContainer.find(id) != m_SoundContainer.end();
}

// =============================================================================
const SoundData* SoundContainer::GetSoundData(SoundId id) const
{
	auto result = m_SoundContainer.find(id);
	AssertReturnIf(result == m_SoundContainer.end(), nullptr,
		"Received unexistant sound id.");

	return &result->second;
}

// =============================================================================
bool SoundContainer::Init(const SoundContainerConfig& cfg)
{
	for (const auto& [id, soundCfg] : cfg.m_SoundContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant sound id.");

		SoundData newSound;

		Audio::CreateSoundFromFile(newSound.m_Sound, soundCfg.m_FileName.c_str());
		ReturnIf(!newSound.m_Sound, false);

		newSound.m_Volume = soundCfg.m_Volume;

		m_SoundContainer.emplace(id, std::move(newSound));
	}

	return true;
}

// =============================================================================
void SoundContainer::Deinit()
{
	for (auto& [id, sound] : m_SoundContainer)
	{
		Audio::DestroySound(sound.m_Sound);
	}

	m_SoundContainer.clear();
}