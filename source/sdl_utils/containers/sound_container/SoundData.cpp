// Corresponding header
#include "sdl_utils/containers/sound_container/SoundData.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
SoundData::SoundData()
	: m_Sound(nullptr)
{
}

// =============================================================================
SoundData::SoundData(Mix_Chunk* sound)
	: m_Sound(sound)
{
}

// =============================================================================
SoundData::~SoundData()
{
}