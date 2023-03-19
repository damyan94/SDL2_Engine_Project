#ifndef SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/TextId.h"
#include "defines/id/FontId.h"
#include "sdl_utils/CommonIncludes.h"
#include "sdl_utils/containers/text_container/TextData.h"

// Forward declarations
struct TextContainerConfig;

class TextContainer
{
public:
	bool				DoesAssetExist(TextId id) const;
	TextData			GetTextData(TextId id) const;

	bool				UpdateText(TextId id, FontId fontId, const Color& color);
	bool				UpdateAllTexts();

protected:
	TextContainer();
	~TextContainer();

	bool				Init(const TextContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<TextId, TextData> m_TextsContainer;
};

#endif // !SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTCONTAINER_H_