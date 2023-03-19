#ifndef SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/FontId.h"
#include "sdl_utils/CommonIncludes.h"
#include "sdl_utils/containers/font_container/FontData.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;
struct FontContainerConfig;

class FontContainer
{
public:
	bool				DoesAssetExist(FontId id) const;
	FontData			GetFontData(FontId id) const;

protected:
	FontContainer();
	~FontContainer();

	bool				Init(const FontContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<FontId, FontData> m_FontsContainer;
};

#endif // !SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTCONTAINER_H_