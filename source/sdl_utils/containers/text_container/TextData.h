#ifndef SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_
#define SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_

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

#endif // !SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_