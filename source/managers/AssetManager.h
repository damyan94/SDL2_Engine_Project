#ifndef ASSET_DRAWMANAGER_H_
#define ASSET_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/IManager.h"

// Forward declarations
class ImageContainer;
class FontContainer;
class SoundContainer;
class MusicContainer;

class AssetManager
	: public IManager
{
private:
	AssetManager();

public:
	~AssetManager() final;

	static AssetManager* Get();

	bool				Init() final;
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	ImageContainer*		GetImageContainer() const;
	FontContainer* 		GetFontContainer() const;
	SoundContainer* 	GetSoundContainer() const;
	MusicContainer*		GetMusicContainer() const;

private:
	ImageContainer*		m_ImageContainer;
	FontContainer*		m_FontContainer;
	SoundContainer*		m_SoundContainer;
	MusicContainer*		m_MusicContainer;

	static AssetManager* m_Instance;
};

#endif // !ASSET_DRAWMANAGER_H_