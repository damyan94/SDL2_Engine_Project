#include "stdafx.h"

#include "System/SDLUtils/Audio/AudioParameters.h"

////////////////////////////////////////////////////////////////////////////////
AudioParameters::AudioParameters()
	: Loops(0)
	, LoopInfinitely(false)
	, Volume(Constants::MaxVolume)
	, MaxVolume(Constants::MaxVolume)
	, ObjectType(EObjectType::Invalid)
	, ResourceId(-1)
{
}

////////////////////////////////////////////////////////////////////////////////
AudioParameters::~AudioParameters()
{
}

////////////////////////////////////////////////////////////////////////////////
void AudioParameters::Reset()
{
	Loops				= 0;
	LoopInfinitely		= false;

	Volume				= Constants::MaxVolume;
	MaxVolume			= Constants::MaxVolume;

	ObjectType			= EObjectType::Invalid;
	ResourceId			= -1;
}