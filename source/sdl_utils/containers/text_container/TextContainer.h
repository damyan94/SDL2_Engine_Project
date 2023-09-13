#ifndef SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_

#include "sdl_utils/containers/text_container/TextData.h"

struct TextContainerConfig;

class TextContainer
{
public:
	bool				DoesAssetExist(TextId id) const;
	const TextData*		GetTextData(TextId id) const;

	bool				UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth);
	bool				UpdateAllTexts();

	void				ChangeLanguage(ELanguage newLanguage);

protected:
	TextContainer();
	~TextContainer();

	bool				Init(const TextContainerConfig& cfg);
	void				Deinit();

private:
	ELanguage			m_CurrLanguage;

	std::unordered_map<TextId, TextData> m_TextsContainer;
};

#endif // !SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_