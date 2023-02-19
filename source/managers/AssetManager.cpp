// Corresponding header
#include "managers/AssetManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

#include "sdl_utils/containers/cfg/ImageContainerCfg.h"
#include "sdl_utils/containers/cfg/FontContainerCfg.h"
#include "sdl_utils/containers/cfg/SoundContainerCfg.h"
#include "sdl_utils/containers/cfg/MusicContainerCfg.h"

// =============================================================================
AssetManager* AssetManager::m_Instance = nullptr;

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
	Deinit();
}

// =============================================================================
AssetManager* AssetManager::Get()
{
	if (!m_Instance)
	{
		m_Instance = new AssetManager;
		AssertReturnIf(!m_Instance, nullptr, "Failed to allocate memory.");
	}

	return m_Instance;
}

// =============================================================================
bool AssetManager::Init()
{
	m_ImageContainer = new ImageContainer;
	AssertReturnIf(!m_ImageContainer, false, "Failed to allocate memory.");
	ImageContainerCfg cfg;
	ReturnIf(!cfg.Read(), false);
	ReturnIf(!m_ImageContainer->Init(cfg), false);

	m_FontContainer = new FontContainer;
	AssertReturnIf(!m_FontContainer, false, "Failed to allocate memory.");
	FontContainerCfg cfg1;
	ReturnIf(!cfg1.Read(), false);
	ReturnIf(!m_FontContainer->Init(cfg1), false);

	m_SoundContainer = new SoundContainer;
	AssertReturnIf(!m_SoundContainer, false, "Failed to allocate memory.");
	SoundContainerCfg cfg2;
	ReturnIf(!cfg2.Read(), false);
	ReturnIf(!m_SoundContainer->Init(cfg2), false);

	m_MusicContainer = new MusicContainer;
	AssertReturnIf(!m_MusicContainer, false, "Failed to allocate memory.");
	MusicContainerCfg cfg3;
	ReturnIf(!cfg3.Read(), false);
	ReturnIf(!m_MusicContainer->Init(cfg3), false);

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
void AssetManager::HandleEvent(const InputEvent& e)
{
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