#ifndef ASSET_DRAWMANAGER_H_
#define ASSET_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"

// Forward declarations
struct AssetManagerConfig;
class ImageContainer;
class FontContainer;
class SoundContainer;
class MusicContainer;

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	AssetManager(const AssetManager& other) = delete;
	AssetManager& operator=(const AssetManager& other) = delete;

	bool				Init(const AssetManagerConfig& cfg);
	void				Deinit();
	void				Update(int32_t dt);

	ImageContainer*		GetImageContainer() const;
	FontContainer* 		GetFontContainer() const;
	SoundContainer* 	GetSoundContainer() const;
	MusicContainer*		GetMusicContainer() const;

private:
	ImageContainer*		m_ImageContainer;
	FontContainer*		m_FontContainer;
	SoundContainer*		m_SoundContainer;
	MusicContainer*		m_MusicContainer;
};

extern AssetManager* g_AssetManager;

#endif // !ASSET_DRAWMANAGER_H_