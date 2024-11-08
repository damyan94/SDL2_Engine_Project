#pragma once

class Texture;

struct TextData
{
	TextData();
	TextData(Texture* texture, Rectangle frameRect, FontId fontId, int32_t wrapWidth);
	~TextData();

	Texture*			m_Texture;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	FontId				m_FontId				= 0;
	Color				m_TextColor				= Colors::Black;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings;
};