#ifndef SDL_UTILS_CONTAINERS_FONTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_FONTCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

#include "sdl_utils/containers/AssetContainer.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;

//TODO Remove all the static
class FontContainer
	: public AssetContainer
{
public:
	FontContainer();
	~FontContainer();

	bool				Init() final;
	void				Deinit() final;

	static bool			DoesAssetExist(FontId id);

	static TTF_Font*	GetFontById(FontId id);
	static int32_t		GetFontSizeById(FontId id);

private:
	struct FontUnit
	{
		FontUnit();
		~FontUnit();

		FontUnit(TTF_Font* font, uint32_t size);

		TTF_Font*		m_Font = nullptr;
		uint32_t		m_Size = 12;
	};

	static std::unordered_map<FontId, FontUnit> m_Fonts;
};

#endif // !SDL_UTILS_CONTAINERS_FONTCONTAINER_H_