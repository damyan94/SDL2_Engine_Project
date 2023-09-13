#include "stdafx.h"

#include "system/sdl_utils/audio/AudioParameters.h"

// =============================================================================
AudioParameters::AudioParameters()
	: m_Loops(0)
	, m_LoopInfinitely(false)
	, m_Volume(Constants::MaxVolume)
	, m_MaxVolume(Constants::MaxVolume)
	, m_ObjectType(EObjectType::Invalid)
{
}

// =============================================================================
AudioParameters::~AudioParameters()
{
}

// =============================================================================
void AudioParameters::Reset()
{
	m_Loops					= 0;
	m_LoopInfinitely		= false;

	m_Volume				= Constants::MaxVolume;
	m_MaxVolume				= Constants::MaxVolume;

	m_ObjectType			= EObjectType::Invalid;
}