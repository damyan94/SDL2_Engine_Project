// Corresponding header
#include "managers/AssetManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/config/AssetManagerConfig.h"

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

AssetManager* g_AssetManager = nullptr;

// =============================================================================
AssetManager::AssetManager()
	: m_ImageContainer(nullptr)
	, m_FontContainer(nullptr)
	, m_SoundContainer(nullptr)
	, m_MusicContainer(nullptr)
{
}

// =============================================================================
AssetManager::~AssetManager()
{
	SafeDelete(m_ImageContainer);
	SafeDelete(m_FontContainer);
	SafeDelete(m_SoundContainer);
	SafeDelete(m_MusicContainer);
}

// =============================================================================
bool AssetManager::Init(const AssetManagerConfig& cfg)
{
	m_ImageContainer = new ImageContainer;
	m_FontContainer = new FontContainer;
	m_SoundContainer = new SoundContainer;
	m_MusicContainer = new MusicContainer;

	AssertReturnIf(!m_ImageContainer, false, "Failed to allocate memory.");
	AssertReturnIf(!m_FontContainer, false, "Failed to allocate memory.");
	AssertReturnIf(!m_SoundContainer, false, "Failed to allocate memory.");
	AssertReturnIf(!m_MusicContainer, false, "Failed to allocate memory.");

	ReturnIf(!m_ImageContainer->Init(cfg.m_ImageContainerConfig), false);
	ReturnIf(!m_FontContainer->Init(cfg.m_FontContainerConfig), false);
	ReturnIf(!m_SoundContainer->Init(cfg.m_SoundContainerConfig), false);
	ReturnIf(!m_MusicContainer->Init(cfg.m_MusicContainerConfig), false);

	return true;
}

// =============================================================================
void AssetManager::Deinit()
{
	m_ImageContainer->Deinit();
	m_FontContainer->Deinit();
	m_SoundContainer->Deinit();
	m_MusicContainer->Deinit();
}

// =============================================================================
void AssetManager::Update(int32_t dt)
{
}

// =============================================================================
ImageContainer* AssetManager::GetImageContainer() const
{
	return m_ImageContainer;
}

// =============================================================================
FontContainer* AssetManager::GetFontContainer() const
{
	return m_FontContainer;
}

// =============================================================================
SoundContainer* AssetManager::GetSoundContainer() const
{
	return m_SoundContainer;
}

// =============================================================================
MusicContainer* AssetManager::GetMusicContainer() const
{
	return m_MusicContainer;
}