#include "stdafx.h"

#include "system/sdl_utils/containers/music_container/MusicData.h"

// =============================================================================
MusicData::MusicData()
	: m_Music(nullptr)
	, m_Volume(Constants::MaxVolume)
{
}

// =============================================================================
MusicData::MusicData(Mix_Music* music, uint8_t volume)
	: m_Music(music)
	, m_Volume(volume)
{
}

// =============================================================================
MusicData::~MusicData()
{
}