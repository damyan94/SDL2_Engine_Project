#include "stdafx.h"

#include "System/Components/Audio/Music.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
Music::Music()
{
}

////////////////////////////////////////////////////////////////////////////////
Music::~Music()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Music::Init(MusicId id)
{
	const auto& data = AssetManager::Instance().m_MusicContainer.GetData(id);
	//ReturnIf(!data, false);

	m_AudioParameters.Volume			= data.m_Volume;
	m_AudioParameters.ObjectType		= EObjectType::Music;
	m_AudioParameters.ResourceId		= id;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Music::Deinit()
{
	AudioObject::Reset();
}