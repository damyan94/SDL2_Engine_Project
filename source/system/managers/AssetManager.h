#pragma once

#include "system/sdl_utils/containers/image_container/ImageContainer.h"
#include "system/sdl_utils/containers/text_container/TextContainer.h"
#include "system/sdl_utils/containers/font_container/FontContainer.h"
#include "system/sdl_utils/containers/sound_container/SoundContainer.h"
#include "system/sdl_utils/containers/music_container/MusicContainer.h"

struct AssetManagerConfig;

class AssetManager
	: public INonCopyMoveable
	, public ImageContainer
	, public FontContainer
	, public TextContainer
	, public SoundContainer
	, public MusicContainer
{
private:
	AssetManager();
	~AssetManager();

public:
	static AssetManager& Instance();

	bool				Init(const AssetManagerConfig& cfg);
	void				Deinit();
};