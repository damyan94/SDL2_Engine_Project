// Corresponding header
#include "sdl_utils/containers/SoundContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "defines/SoundDefines.h"

std::unordered_map<SoundId, Mix_Chunk*> SoundContainer::m_Sounds;

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
bool SoundContainer::Init()
{
	for (const auto& soundData : m_SoundsData)
	{
		SoundId id = soundData.m_Id;

		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant sound id.");

		m_Sounds[id] = Mix_LoadWAV(soundData.m_FileName);
		AssertReturnIf(!m_Sounds[id], false, "Mix_LoadWAV() failed.");
	}

	return true;
}

// =============================================================================
// Mix_FreeChunk
void SoundContainer::Deinit()
{
	for (auto& [id, sound] : m_Sounds)
	{
		if (sound)
		{
			Mix_FreeChunk(sound);
			sound = nullptr;
		}
	}

	m_Sounds.clear();
}

// =============================================================================
bool SoundContainer::DoesAssetExist(SoundId id)
{
	return m_Sounds.find(id) != m_Sounds.end();
}

// =============================================================================
Mix_Chunk* SoundContainer::GetSoundById(SoundId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant sound id.");

	return m_Sounds[id];
}