#include "stdafx.h"

#include "System/SDLUtils/Containers/Data/MusicData.h"

////////////////////////////////////////////////////////////////////////////////
MusicData::MusicData()
	: m_Music(nullptr)
	, m_Volume(Constants::MaxVolume)
{
}

////////////////////////////////////////////////////////////////////////////////
MusicData::MusicData(Mix_Music* music, uint8_t volume)
	: m_Music(music)
	, m_Volume(volume)
{
}

////////////////////////////////////////////////////////////////////////////////
MusicData::~MusicData()
{
}