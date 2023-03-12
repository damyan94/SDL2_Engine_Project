// Corresponding header
#include "sdl_utils/containers/SoundContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "sdl_utils/containers/config/SoundContainerConfig.h"

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
// Mix_LoadWAV
bool SoundContainer::Init(const SoundContainerConfig& cfg)
{
	for (const auto& [id, soundData] : cfg.m_SoundContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant sound id.");

		m_SoundContainer[id].m_Sound = Mix_LoadWAV(soundData.m_FileName.c_str());
		AssertReturnIf(!m_SoundContainer[id].m_Sound, false, "Mix_LoadWAV() failed: " + std::string(SDL_GetError()));
	}

	return true;
}

// =============================================================================
// Mix_FreeChunk
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

// =============================================================================
bool SoundContainer::DoesAssetExist(SoundId id)
{
	return m_SoundContainer.find(id) != m_SoundContainer.end();
}

// =============================================================================
Mix_Chunk* SoundContainer::GetSoundById(SoundId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant sound id.");

	return m_SoundContainer[id].m_Sound;
}

// =============================================================================
SoundContainer::SoundUnit::SoundUnit()
	: m_Sound(nullptr)
{
}

// =============================================================================
SoundContainer::SoundUnit::SoundUnit(Mix_Chunk* font)
	: m_Sound(font)
{
}

// =============================================================================
SoundContainer::SoundUnit::~SoundUnit()
{
}