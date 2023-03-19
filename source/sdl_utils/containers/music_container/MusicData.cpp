// Corresponding header
#include "sdl_utils/containers/music_container/MusicData.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
MusicData::MusicData()
	: m_Music(nullptr)
{
}

// =============================================================================
MusicData::MusicData(Mix_Music* music)
	: m_Music(music)
{
}

// =============================================================================
MusicData::~MusicData()
{
}