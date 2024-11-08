#pragma once

#include "System/SDLUtils/Containers/ImageContainer.h"
#include "System/SDLUtils/Containers/TextContainer.h"
#include "System/SDLUtils/Containers/FontContainer.h"
#include "System/SDLUtils/Containers/SoundContainer.h"
#include "System/SDLUtils/Containers/MusicContainer.h"

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