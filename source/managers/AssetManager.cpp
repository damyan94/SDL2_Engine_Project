// Corresponding header
#include "managers/AssetManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

AssetManager* AssetManager::m_AssetManager = nullptr;

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
AssetManager* AssetManager::Get()
{
	if (!m_AssetManager)
	{
		m_AssetManager = new AssetManager;
	}

	return m_AssetManager;
}

// =============================================================================
bool AssetManager::Init()
{
	m_AssetContainers.resize((size_t)EAssetContainerType::Count);

	m_AssetContainers[(size_t)EAssetContainerType::Image] = new ImageContainer;
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Image], false);
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Image]->Init(), false);

	m_AssetContainers[(size_t)EAssetContainerType::Font] = new FontContainer;
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Font], false);
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Font]->Init(), false);

	m_AssetContainers[(size_t)EAssetContainerType::Sound] = new SoundContainer;
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Sound], false);
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Sound]->Init(), false);

	m_AssetContainers[(size_t)EAssetContainerType::Music] = new MusicContainer;
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Music], false);
	AssertReturnIf(!m_AssetContainers[(size_t)EAssetContainerType::Music]->Init(), false);

	return true;
}

// =============================================================================
void AssetManager::Deinit()
{
	for (auto assetContainer : m_AssetContainers)
	{
		assetContainer->Deinit();
	}
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
AssetContainer* AssetManager::GetContainer(EAssetContainerType type)
{
	AssertReturnIf(!IsEnumValueValid<EAssetContainerType>(type), nullptr);

	return m_AssetContainers[(size_t)type];
}