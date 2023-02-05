#ifndef ASSET_DRAWMANAGER_H_
#define ASSET_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/Manager.h"

// Forward declarations

class AssetManager
	: public Manager
{
public:
	~AssetManager() final;

	static AssetManager* Get();

	bool				Init() final;
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	AssetContainer*		GetContainer(EAssetContainerType type);

private:
	std::vector<AssetContainer*> m_AssetContainers;

	AssetManager();
	static AssetManager* m_AssetManager;
};

#endif // !ASSET_DRAWMANAGER_H_