#include "stdafx.h"

#include "System/Components/Audio/Sound.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
Sound::Sound()
	: m_Channel(0)
{
}

////////////////////////////////////////////////////////////////////////////////
Sound::~Sound()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::Init(SoundId id)
{
	const auto& data = AssetManager::Instance().m_SoundContainer.GetData(id);
	//ReturnIf(!data, false);

	m_AudioParameters.Volume			= data.m_Volume;
	m_AudioParameters.ObjectType		= EObjectType::Sound;
	m_AudioParameters.ResourceId		= id;

	m_Channel							= 0;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Sound::Deinit()
{
	AudioObject::Reset();
}