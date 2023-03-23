// Corresponding header
#include "sdl_utils/containers/sound_container/SoundContainer.h"
#include "sdl_utils/containers/config/SoundContainerConfig.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes

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
SoundData SoundContainer::GetSoundData(SoundId id) const
{
	AssertReturnIf(!DoesAssetExist(id), SoundData(),
		"Received unexsistant sound id.");

	return m_SoundContainer.find(id)->second;
}

// =============================================================================
bool SoundContainer::Init(const SoundContainerConfig& cfg)
{
	for (const auto& [id, soundCfg] : cfg.m_SoundContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already exsistant sound id.");

		SoundData newSound;

		newSound.m_Sound = Mix_LoadWAV(soundCfg.m_FileName.c_str());
		AssertReturnIf(!newSound.m_Sound, false,
			"Mix_LoadWAV() failed: " + std::string(SDL_GetError()));

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
		ContinueIf(!sound.m_Sound);

		Mix_FreeChunk(sound.m_Sound);
		sound = nullptr;
	}

	m_SoundContainer.clear();
}