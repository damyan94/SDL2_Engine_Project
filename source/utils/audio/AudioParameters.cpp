// Corresponding header
#include "utils/audio/AudioParameters.h"

// C/C++ system includes

// Third-party includes

// Own includes

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