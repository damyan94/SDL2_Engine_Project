#include "stdafx.h"

#include "components/audio/AudioObject.h"

// =============================================================================
AudioObject::AudioObject()
{
}

// =============================================================================
AudioObject::~AudioObject()
{
}

// =============================================================================
void AudioObject::Reset()
{
	m_AudioParameters.Reset();
}

// Getters

// =============================================================================
int32_t AudioObject::GetLoops() const
{
	return m_AudioParameters.m_Loops;
}

// =============================================================================
bool AudioObject::GetLoopInfinitely() const
{
	return m_AudioParameters.m_LoopInfinitely;
}

// =============================================================================
uint8_t AudioObject::GetVolume() const
{
	return m_AudioParameters.m_MaxVolume;
}

// =============================================================================
uint8_t AudioObject::GetMaxVolume() const
{
	return m_AudioParameters.m_Volume;
}

// =============================================================================
EObjectType AudioObject::GetObjectType() const
{
	return m_AudioParameters.m_ObjectType;
}

// Setters

// =============================================================================
void AudioObject::SetLoops(int32_t loops)
{
	m_AudioParameters.m_Loops = loops;
}

// =============================================================================
void AudioObject::SetLoopInfinitely(bool loopInfinitely)
{
	m_AudioParameters.m_LoopInfinitely = loopInfinitely;
}

// =============================================================================
void AudioObject::SetVolume(uint8_t volume)
{
	m_AudioParameters.m_MaxVolume = volume;
}

// =============================================================================
void AudioObject::SetMaxVolume(uint8_t volume)
{
	m_AudioParameters.m_Volume = volume;
}

// =============================================================================
void AudioObject::SetObjectType(EObjectType type)
{
	m_AudioParameters.m_ObjectType = type;
}

// Others