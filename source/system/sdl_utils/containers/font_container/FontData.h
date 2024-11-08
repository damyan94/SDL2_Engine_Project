#pragma once

typedef struct _TTF_Font TTF_Font;

struct FontData
{
	FontData();
	FontData(TTF_Font* font, uint8_t size, EFontWrapAlign wrapAlign);

	~FontData();

	TTF_Font*			m_Font					= nullptr;
	uint8_t				m_Size					= 0;
	EFontWrapAlign		m_WrapAlign				= EFontWrapAlign::Invalid;
};