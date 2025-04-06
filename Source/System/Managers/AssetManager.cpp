#include "stdafx.h"

#include "System/Managers/AssetManager.h"
#include "Application/Application/ConfigManager.h"
#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"
#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"
#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"
#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"
#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

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
	static AssetManager instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool AssetManager::Init()
{
	ReturnIf(!m_ImageContainer.Init(ConfigManager::Instance().Get<ImageContainerConfig>()), false);
	ReturnIf(!m_StringContainer.Init(ConfigManager::Instance().Get<StringContainerConfig>()), false);
	ReturnIf(!m_FontContainer.Init(ConfigManager::Instance().Get<FontContainerConfig>()), false);
	ReturnIf(!m_TextContainer.Init(ConfigManager::Instance().Get<TextContainerConfig>(), m_StringContainer, m_FontContainer), false);
	ReturnIf(!m_DynamicTextContainer.Init(m_FontContainer), false);
	ReturnIf(!m_SoundContainer.Init(ConfigManager::Instance().Get<SoundContainerConfig>()), false);
	ReturnIf(!m_MusicContainer.Init(ConfigManager::Instance().Get<MusicContainerConfig>()), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void AssetManager::Deinit()
{
}