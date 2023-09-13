#include "stdafx.h"

#include "system/managers/AssetManager.h"
#include "system/managers/config/AssetManagerConfig.h"

AssetManager* g_AssetManager = nullptr;

// =============================================================================
AssetManager::AssetManager()
{
}

// =============================================================================
AssetManager::~AssetManager()
{
	Deinit();
}

// =============================================================================
bool AssetManager::Init(const AssetManagerConfig& cfg)
{
	ReturnIf(!ImageContainer::Init(cfg.m_ImageContainerConfig), false);
	ReturnIf(!FontContainer::Init(cfg.m_FontContainerConfig), false);
	ReturnIf(!TextContainer::Init(cfg.m_TextContainerConfig), false);
	ReturnIf(!SoundContainer::Init(cfg.m_SoundContainerConfig), false);
	ReturnIf(!MusicContainer::Init(cfg.m_MusicContainerConfig), false);

	return true;
}

// =============================================================================
void AssetManager::Deinit()
{
}