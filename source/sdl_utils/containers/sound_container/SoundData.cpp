// Corresponding header
#include "sdl_utils/containers/sound_container/SoundData.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/Defines.h"

// =============================================================================
SoundData::SoundData()
	: m_Sound(nullptr)
	, m_Volume(Constants::MaxVolume)
{
}

// =============================================================================
SoundData::SoundData(Mix_Chunk* sound, uint8_t volume)
	: m_Sound(sound)
	, m_Volume(volume)
{
}

// =============================================================================
SoundData::~SoundData()
{
}