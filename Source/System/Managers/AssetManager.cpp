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
	ReturnIf(!m_ImageContainer.Init(cfg.ImageContainerConfig), false);
	ReturnIf(!m_StringContainer.Init(cfg.StringContainerConfig), false);
	ReturnIf(!m_FontContainer.Init(cfg.FontContainerConfig), false);
	ReturnIf(!m_TextContainer.Init(cfg.TextContainerConfig, m_StringContainer, m_FontContainer), false);
	ReturnIf(!m_DynamicTextContainer.Init(m_FontContainer), false);
	ReturnIf(!m_SoundContainer.Init(cfg.SoundContainerConfig), false);
	ReturnIf(!m_MusicContainer.Init(cfg.MusicContainerConfig), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void AssetManager::Deinit()
{
}