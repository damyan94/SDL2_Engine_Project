#ifndef SDL_UTILS_CONTAINERS_FONTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_FONTCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/FontId.h"
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;
class FontContainerCfg;

class FontContainer
{
public:
	FontContainer();
	~FontContainer();

	bool				Init(const FontContainerCfg& cfg);
	void				Deinit();

	bool				DoesAssetExist(FontId id);

	TTF_Font*			GetFontById(FontId id);
	int32_t				GetFontSizeById(FontId id);

private:
	struct FontUnit
	{
		FontUnit();
		FontUnit(TTF_Font* font, uint32_t size);

		~FontUnit();

		TTF_Font*		m_Font;
		uint32_t		m_Size;
	};

	std::unordered_map<FontId, FontUnit> m_FontsContainer;
};

#endif // !SDL_UTILS_CONTAINERS_FONTCONTAINER_H_