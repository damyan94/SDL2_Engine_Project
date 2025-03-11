#pragma once

#include "System/SDLUtils/Drawing/Texture.h"

struct ImageData
{
	Texture*			m_Texture;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	int32_t				m_FramesCount			= 0;
};