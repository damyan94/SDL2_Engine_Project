#include "stdafx.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/Config/AssetManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
AssetManager::AssetManager()
{
}

////////////////////////////////////////////////////////////////////////////////
AssetManager::~AssetManager()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
AssetManager& AssetManager::Instance()
{
	static AssetManager m_Instance;
	return m_Instance;
}

////////////////////////////////////////////////////////////////////////////////
bool AssetManager::Init(const AssetManagerConfig& cfg)
{
	ReturnIf(!ImageContainer::Init(cfg.m_ImageContainerConfig), false);
	ReturnIf(!FontContainer::Init(cfg.m_FontContainerConfig), false);
	ReturnIf(!TextContainer::Init(cfg.m_TextContainerConfig), false);
	ReturnIf(!SoundContainer::Init(cfg.m_SoundContainerConfig), false);
	ReturnIf(!MusicContainer::Init(cfg.m_MusicContainerConfig), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void AssetManager::Deinit()
{
}