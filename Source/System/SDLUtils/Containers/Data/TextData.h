#pragma once

#include "System/SDLUtils/Drawing/Texture.h"

struct TextData
{
	Texture*			m_Texture;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	FontId				m_FontId				= 0;
	Color				m_TextColor				= Colors::Black;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings; //TODO rethink this, maybe make it part of the asset manager by adding StringContainer?
};