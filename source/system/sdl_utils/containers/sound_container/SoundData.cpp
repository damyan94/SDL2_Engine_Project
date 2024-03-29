#include "stdafx.h"

#include "system/sdl_utils/containers/sound_container/SoundData.h"

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