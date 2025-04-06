#pragma once

#include "System/SDLUtils/Containers/ImageContainer.h"
#include "System/SDLUtils/Containers/StringContainer.h"
#include "System/SDLUtils/Containers/FontContainer.h"
#include "System/SDLUtils/Containers/TextContainer.h"
#include "System/SDLUtils/Containers/DynamicTextContainer.h"
#include "System/SDLUtils/Containers/SoundContainer.h"
#include "System/SDLUtils/Containers/MusicContainer.h"

//TODO maybe store a pointer/reference to these configs in the corresponding class?
class AssetManager
	: public INonCopyMoveable
{
private:
	AssetManager();
	~AssetManager();

public:
	static AssetManager&	Instance();

	bool					Init();
	void					Deinit();

	ImageContainer			m_ImageContainer;
	StringContainer			m_StringContainer;
	FontContainer			m_FontContainer;
	TextContainer			m_TextContainer;
	DynamicTextContainer	m_DynamicTextContainer;
	SoundContainer			m_SoundContainer;
	MusicContainer			m_MusicContainer;
};