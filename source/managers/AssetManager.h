#ifndef MANAGERS_ASSETMANAGER_H_
#define MANAGERS_ASSETMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"

#include "sdl_utils/containers/image_container/ImageContainer.h"
#include "sdl_utils/containers/text_container/TextContainer.h"
#include "sdl_utils/containers/font_container/FontContainer.h"
#include "sdl_utils/containers/sound_container/SoundContainer.h"
#include "sdl_utils/containers/music_container/MusicContainer.h"

// Forward declarations
struct AssetManagerConfig;

class AssetManager
	: public ImageContainer
	, public FontContainer
	, public TextContainer
	, public SoundContainer
	, public MusicContainer
{
public:
	AssetManager();
	~AssetManager();

	AssetManager(const AssetManager& other) = delete;
	AssetManager(AssetManager&& other) = delete;

	AssetManager& operator=(const AssetManager& other) = delete;
	AssetManager& operator=(AssetManager&& other) = delete;

	bool				Init(const AssetManagerConfig& cfg);
	void				Deinit();
};

extern AssetManager* g_AssetManager;

#endif // !MANAGERS_ASSETMANAGER_H_